#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include "../../byond/utils/string_helper.h"
#include "../../../third_party/glfw/deps/glad/gl.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace MYG::dmirender
{

	class DMI
	{
	public:
		

		virtual ~DMI()
		{
			delete defaultState;
			delete image;
		}

		DMI(InputStream *inputStream)
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
