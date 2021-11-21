#include "DMIRead.h"
#include <iostream>
#include "../deps/zlib-1.2.11/zlib.h"
#include "../deps/libpng/png.h"


int read_chunk_callback(png_structp ptr, png_unknown_chunkp chunk);
void read_row_callback(png_structp ptr, png_uint_32 row, int pass);
int inflate(unsigned char *src, int srcLen, unsigned char *dst, int dstLen);
void splitLines(std::vector<std::string> &lines, std::string source);
std::string getStrValue(std::vector<std::string> lines, std::string key);
std::string getStrValue(std::string line, std::string key);
int getIntValue(std::vector<std::string> lines, std::string key);
int getIntValue(std::string line, std::string key);
void getListValue(std::vector<unsigned int> &list, std::string line, std::string key);

char * description;

DMIData * DMIReadData(const char * path)
{
	char header[8];
	FILE *fp = fopen(path, "rb");
	if(!fp)
	{
		// Error opening file
		return NULL;
	}
	fread(header, 1, 8, fp);

	png_voidp user_error_ptr = 0;
	png_error_ptr user_error_fn = 0, user_warning_fn = 0;

	png_structp png_ptr = png_create_read_struct
       (PNG_LIBPNG_VER_STRING, (png_voidp)user_error_ptr,
        user_error_fn, user_warning_fn);
    png_infop info_ptr = png_create_info_struct(png_ptr);
    png_infop end_info = png_create_info_struct(png_ptr);
	setjmp(png_jmpbuf(png_ptr));
	png_init_io(png_ptr, fp);
	png_set_sig_bytes(png_ptr, 8);

	png_voidp user_chunk_ptr = png_get_user_chunk_ptr(png_ptr);
	png_set_read_user_chunk_fn(png_ptr, user_chunk_ptr, read_chunk_callback);
	png_set_read_status_fn(png_ptr, read_row_callback);

	png_byte * list = {(png_byte*)"zTXt\0"};
	png_set_keep_unknown_chunks(png_ptr, 2, list, 1);

	description = new char[2048];
	memset(description, 0, 2048);

	png_read_info(png_ptr, info_ptr);
	for(unsigned i=0;i<png_get_image_height(png_ptr, info_ptr);i++)
    {
		png_read_row(png_ptr, 0, 0);
    }
    png_read_end(png_ptr, info_ptr);

	png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
	
	// Let's parse this mother
	DMIData * dmidata = new DMIData();

	std::vector<std::string> lines;
	splitLines(lines, description);

	dmidata->version = getStrValue(lines, "version");
	dmidata->width = getIntValue(lines, "width");
	dmidata->height = getIntValue(lines, "height");
	
	DMIState state;
	bool open = false;
	for(unsigned int i=0; i<lines.size(); ++i)
	{
		if(lines[i].compare(0, 5, "state") == 0)
		{
			if(open)
			{
				dmidata->states.push_back(state);
			}
			state.delay.clear();
			state.loop = false;
			state.name = lines[i].substr(7, lines[i].size() - 8);
			open = true;
		}
		if(open && lines[i].compare(0, 4, "dirs") == 0)
		{
			state.dirs = getIntValue(lines[i], "dirs");
		}
		if(open && lines[i].compare(0, 6, "frames") == 0)
		{
			state.frames = getIntValue(lines[i], "frames");
		}
		if(open && lines[i].compare(0, 5, "delay") == 0)
		{
			getListValue(state.delay, lines[i], "delay");
		}
		if(open && lines[i].compare(0, 4, "loop") == 0)
		{
			if(getIntValue(lines[i], "loop")) state.loop = true;
		}
	}
	dmidata->states.push_back(state);

	delete[] description;
	return dmidata;
}

int read_chunk_callback(png_structp ptr, png_unknown_chunkp chunk)
{
	// We are only interested in zTXt chunks
	if(strncmp((const char*)chunk->name, "zTXt", 4) == 0)
	{
		unsigned char * buffer = new unsigned char[chunk->size];
		memcpy(buffer, chunk->data, chunk->size);
		int i = 0;
		for(i=0; buffer[i] != 0; ++i){}
		if(strncmp((const char *)buffer, "Description", 11))
		{
			// We don't have the correct chunk
			delete[] buffer;
			return 1;
		}
		std::cout << std::endl;
		i+=2;

		// We now have the lenght of the deflated data
		int length = chunk->size - i;

		// Proceed to inflate it
		unsigned char * inflated = new unsigned char[2048];
		memset(inflated, 0, 2048);
		if(inflate(chunk->data+i, length, inflated, 2048) <= 0)
		{
			// There was an error decompressing
			delete[] buffer;
			delete[] inflated;
			return 1;
		}

		memcpy(description, inflated, 2048);

		delete[] buffer;
		delete[] inflated;

		return 0;
	}
    return 1;
}

void read_row_callback(png_structp ptr, png_uint_32 row, int pass)
{
	
}

int inflate(unsigned char *src, int srcLen, unsigned char *dst, int dstLen) {
    
	z_stream strm;
	memset(&strm, 0, sizeof(z_stream));
    strm.opaque = 0;
    strm.next_in   = src;
    strm.avail_in  = srcLen;
    strm.next_out  = dst;
	strm.avail_out = dstLen;

	inflateInit(&strm);
	int ret = inflate(&strm, Z_FINISH);
	inflateEnd(&strm);

	if(ret != Z_STREAM_END)
	{
		return ret;
	}
	return strm.total_out;
}

void splitLines(std::vector<std::string> &lines, std::string source)
{
	std::string line;
	for(unsigned int i=0; i<source.size(); ++i)
	{
		if(source[i] == '\n' || source[i] == '#')
		{
			while(source[i] != '\n') ++i;
			if(line.size() > 0) lines.push_back(line);
			line.clear();
		}
		else
		{
			if(source[i] != '\n' && source[i] != '\r' && source[i] != ' ' && source[i] != '\t')
			{
				line.push_back(source[i]);
			}
		}
	}
}

std::string getStrValue(std::vector<std::string> lines, std::string key)
{
	for(unsigned int i=0; i<lines.size(); ++i)
	{
		if(lines[i].compare(0, key.size(), key) == 0)
		{
			return lines[i].substr(key.size()+2, lines[i].size() - key.size() - 3);
		}
	}

	return "";
}

std::string getStrValue(std::string line, std::string key)
{
	if(line.compare(0, key.size(), key) == 0)
	{
		return line.substr(key.size()+2, line.size() - key.size() - 3);
	}
	return "";
}

int getIntValue(std::vector<std::string> lines, std::string key)
{
	for(unsigned int i=0; i<lines.size(); ++i)
	{
		if(lines[i].compare(0, key.size(), key) == 0)
		{
			return (unsigned int)atoi(lines[i].substr(key.size()+1, std::string::npos).c_str());
		}
	}

	return 0;
}

int getIntValue(std::string line, std::string key)
{
	if(line.compare(0, key.size(), key) == 0)
	{
		return atoi(line.substr(key.size()+1, std::string::npos).c_str());
	}

	return 0;
}

void getListValue(std::vector<unsigned int> &list, std::string line, std::string key)
{
	if(line.compare(0, key.size(), key) == 0)
	{
		line = line.substr(key.size()+1, std::string::npos);
		std::string buffer;
		for(unsigned int i=0; i<line.size(); ++i)
		{
			if(line[i] == ',')
			{
				list.push_back(atoi(buffer.c_str()));
				buffer.clear();
			}
			else
			{
				buffer.push_back(line[i]);
			}
		}
		list.push_back(atoi(buffer.c_str()));
	}
}