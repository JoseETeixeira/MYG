#pragma once

#include "IconState.h"
#include "IconSubstate.h"
#include <string>
#include <unordered_map>
#include <vector>
#include "../../byond/utils/string_helper.h"
#include <opencv2/imgcodecs/imgcodecs_c.h>

namespace MYG::dmirender
{

	using ImageInfo = ar::com::hjg::pngj::ImageInfo;
	using ImageLineInt = ar::com::hjg::pngj::ImageLineInt;
	using PngReader = ar::com::hjg::pngj::PngReader;
	using PngChunkPLTE = ar::com::hjg::pngj::chunks::PngChunkPLTE;
	using PngChunkTRNS = ar::com::hjg::pngj::chunks::PngChunkTRNS;
	using Files = com::google::common::io::Files;
	using BufferUtils = org::lwjgl::BufferUtils;
	using GL12 = org::lwjgl::opengl::GL12;
	using GL14 = org::lwjgl::opengl::GL14;

	using BufferedImage = java::awt::image::BufferedImage;
	using DataBufferInt = java::awt::image::DataBufferInt;
	using File = java::io::File;
	using IOException = java::io::IOException;
	using InputStream = java::io::InputStream;
	using ByteBuffer = java::nio::ByteBuffer;
	using ArrayList = java::util::ArrayList;
	using HashMap = java::util::HashMap;
	using List = java::util::List;
	using Map = java::util::Map;
	using Matcher = java::util::regex::Matcher;
	using Pattern = java::util::regex::Pattern;

//JAVA TO C++ CONVERTER TODO TASK: The Java 'import static' statement cannot be converted to C++:
//	import static org.lwjgl.opengl.GL11.*;

	class DMI
	{
	public:
		int width = 32;
		int height = 32;
		int rows = 1;
		int cols = 1;

		std::unordered_map<std::wstring, IconState*> iconStates = std::unordered_map<std::wstring, IconState*>();
		IconState *defaultState;

		int glID = -1;
		BufferedImage *image;

		virtual ~DMI()
		{
			delete defaultState;
			delete image;
		}

		DMI(InputStream *inputStream)
		{

			PngReader *pngr = new PngReader(inputStream);
			ImageInfo *info = pngr->getImgInfo();

			// There's a good reason I'm converting this into a bufferedimage and then loading into opengl:
			// I need to display this outside of opengl, and I need bufferedimage to do that.

			image = new BufferedImage(info->cols, info->rows, BufferedImage::TYPE_INT_ARGB);
			//ImageLineInt pngLine;
			DataBufferInt *buffer = static_cast<DataBufferInt*>(image->getRaster().getDataBuffer());
			PngChunkPLTE *pal = pngr->getMetadata().getPLTE();
			PngChunkTRNS *trns = pngr->getMetadata().getTRNS();

			std::vector<int> data = buffer->getData();
			int dataindex = 0;

			// For converting to 8 bit-depth
			int mult = 1;
			int div = 1;
			switch (info->bitDepth)
			{
				case 1:
					mult = 255;
				case 2:
					mult = 85;
				case 4:
					mult = 17;
				case 16:
					div = 257;
			}
			if (info->indexed)
			{
				int tlen = trns != nullptr ? trns->getPalletteAlpha()->length : 0;
				while (pngr->hasMoreRows())
				{
					ImageLineInt *line = static_cast<ImageLineInt*>(pngr->readRow());
					std::vector<int> linearr = line->getScanline();
					for (auto index : linearr)
					{
						if (index < tlen)
						{
							data[dataindex] = static_cast<int>((static_cast<long long>(trns->getPalletteAlpha()[index]) << 24LL) + static_cast<long long>(pal->getEntry(index)));
						}
						else
						{
							data[dataindex] = static_cast<int>(static_cast<long long>(pal->getEntry(index)) + 0xff000000LL);
						}
						dataindex++;
					}
				}
			}
			else if (info->greyscale)
			{
				while (pngr->hasMoreRows())
				{
					ImageLineInt *line = static_cast<ImageLineInt*>(pngr->readRow());
					std::vector<int> linearr = line->getScanline();
					for (int i = 0; i < linearr.size(); i += info->channels)
					{
						int value = linearr[i] * mult / div; // Get the value
						int alpha = 255;
						if (info->channels == 2)
						{
							alpha = linearr[i + 1] * mult / div;
						}
						data[dataindex] = value + (value << 8) + (value << 16) + (alpha << 24);
						dataindex++;
					}
				}
			}
			else
			{
				while (pngr->hasMoreRows())
				{
					ImageLineInt *line = static_cast<ImageLineInt*>(pngr->readRow());
					std::vector<int> linearr = line->getScanline();
					for (int i = 0; i < linearr.size(); i += info->channels)
					{
						int r = linearr[i] * mult / div; // Get the value
						int g = linearr[i + 1] * mult / div;
						int b = linearr[i + 2] * mult / div;
						int alpha = 255;
						if (info->channels == 4)
						{
							alpha = linearr[i + 3] * mult / div;
						}
						data[dataindex] = b + (g << 8) + (r << 16) + (alpha << 24);
						dataindex++;
					}
				}
			}
			pngr->close();

			width = info->cols;
			height = info->rows;
			std::wstring textMeta = pngr->getMetadata().getTxtForKey(L"Description");
			std::vector<std::wstring> lines = textMeta.split(L"(\\r\\n|\\r|\\n)");
			IconState *currState = nullptr;
			std::vector<IconState*> statesList;
			for (auto line : lines)
			{
				std::vector<std::wstring> kv = line.split(L"=");
				if (kv.size() < 2)
				{
					continue;
				}
				std::wstring key = StringHelper::trim(kv[0]);
				std::wstring val = StringHelper::trim(kv[1]);
//JAVA TO C++ CONVERTER NOTE: The following 'switch' operated on a string and was converted to C++ 'if-else' logic:
//				switch (key)
//ORIGINAL LINE: case "width":
				if (key == L"width")
				{
						int newWidth = std::stoi(val);
						cols = (width / newWidth);
						width = newWidth;
				}
//ORIGINAL LINE: case "height":
				else if (key == L"height")
				{
						int newHeight = std::stoi(val);
						rows = (height / newHeight);
						height = newHeight;
				}
//ORIGINAL LINE: case "state":
				else if (key == L"state")
				{
						Matcher *m = Pattern::compile(L"\"(.*)\"").matcher(val);
						if (m->find())
						{
							currState = new IconState(m->group(1));
							if (defaultState == nullptr || currState->name == L"")
							{
								defaultState = currState;
							}
							statesList.push_back(currState);
						}
				}
//ORIGINAL LINE: case "dirs":
				else if (key == L"dirs")
				{
						currState->dirCount = std::stoi(val);
				}
//ORIGINAL LINE: case "frames":
				else if (key == L"frames")
				{
						currState->frameCount = std::stoi(val);
				}
//ORIGINAL LINE: case "delay":
				else if (key == L"delay")
				{
						std::vector<std::wstring> delayStrings = val.split(L",");
						if (delayStrings.size() == currState->dirCount * currState->frameCount)
						{
							currState->delays = std::vector<float>(delayStrings.size());
							for (int i = 0; i < delayStrings.size(); i++)
							{
								currState->delays[i] = std::stof(delayStrings[i]);
							}
						}
				}
			}

			// Old-ish format support.
			if (statesList.size() > 1 && width == info->cols && height == info->rows)
			{
				int frameCount = 0;
				for (auto i : statesList)
				{
					frameCount += i->dirCount * i->frameCount;
				}
				width = info->cols / frameCount;
				cols = frameCount;
			}

			// No icon data? Make one icon state.
			if (statesList.size() <= 0)
			{
				currState = new IconState(L"");
				defaultState = currState;
				statesList.push_back(currState);

			}
			int substateIndex = 0;
			for (auto is : statesList)
			{
				std::vector<IconSubstate*> substatesForState(is->dirCount * is->frameCount);
				for (int i = 0; i < is->dirCount * is->frameCount; i++)
				{
					substatesForState[i] = new IconSubstate(this, substateIndex);
					substateIndex++;
				}
				is->substates = substatesForState;
				iconStates.emplace(is->name, is);
			}

//JAVA TO C++ CONVERTER TODO TASK: A 'delete currState' statement was not added since currState was assigned to a field. Handle memory management manually.
			delete pngr;
		}

		DMI(File *file) : DMI(Files::asByteSource(file).openStream())
		{
		}

		virtual IconState *getIconState(const std::wstring &s)
		{
			if (iconStates.find(s) != iconStates.end())
			{
				return iconStates[s];
			}
			else
			{
				return defaultState;
			}
		}

		virtual void createGL()
		{
			if (image == nullptr || glID != -1)
			{
				return;
			}
			std::vector<int> pixels = (static_cast<DataBufferInt*>(image->getRaster().getDataBuffer()))->getData();
			image->getRGB(0, 0, image->getWidth(), image->getHeight(), pixels, 0, image->getWidth());

			ByteBuffer *buffer = BufferUtils::createByteBuffer(image->getWidth() * image->getHeight() * 4); //4 for RGBA, 3 for RGB

			for (int y = 0; y < image->getHeight(); y++)
			{
				for (int x = 0; x < image->getWidth(); x++)
				{
					int pixel = pixels[y * image->getWidth() + x];
					buffer->put(static_cast<signed char>((pixel >> 16) & 0xFF)); // Red component
					buffer->put(static_cast<signed char>((pixel >> 8) & 0xFF)); // Green component
					buffer->put(static_cast<signed char>(pixel & 0xFF)); // Blue component
					buffer->put(static_cast<signed char>((pixel >> 24) & 0xFF)); // Alpha component. Only for RGBA
				}
			}

			buffer->flip(); //FOR THE LOVE OF GOD DO NOT FORGET THIS

			// You now have a ByteBuffer filled with the color data of each pixel.
			// Now just create a texture ID and bind it. Then you can load it using 
			// whatever OpenGL method you want, for example:
			glID = glGenTextures();
			glBindTexture(GL_TEXTURE_2D, glID);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL12::GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL12::GL_CLAMP_TO_EDGE);

			//Setup texture scaling filtering
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

			glTexParameteri(GL_TEXTURE_2D, GL14::GL_GENERATE_MIPMAP, GL_TRUE);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, image->getWidth(), image->getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
		}
	};

}
