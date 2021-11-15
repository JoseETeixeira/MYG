#pragma once

#include <string>
#include "exceptionhelper.h"

namespace BYOND
{

	class ObjInstance
	{
	public:
		virtual std::wstring getVar(const std::wstring &key) = 0;
		virtual std::wstring typeString() = 0;
		virtual bool istype(const std::wstring &path) = 0;
		virtual std::wstring toStringTGM() = 0;

	private:
		int cachedDir = -1;
		int cachedPixelX = -1234;
		int cachedPixelY = -1234;
		float cachedLayer = -1234;
		int cachedPlane = -1234;
		Color *cachedColor = nullptr;
		std::wstring cachedIconState = L"";
		std::wstring cachedIcon = L"";

	public:
		virtual ~ObjInstance()
		{
			delete cachedColor;
		}

		virtual std::wstring getIcon()
		{
			if (cachedIcon == L"")
			{
				std::wstring var = getVar(L"icon");
				if (var == L"")
				{
					return cachedIcon = L"";
				}
				Matcher *m = Pattern::compile(L"'(.+)'").matcher(var);
				if (m->find())
				{
					cachedIcon = m->group(1);
				}
				else
				{
					cachedIcon = L"";
				}
			}
			return cachedIcon;
		}

		virtual std::wstring getIconState()
		{
			if (cachedIconState == L"")
			{
				Matcher *m = Pattern::compile(L"\"(.+)\"").matcher(getVar(L"icon_state"));
				if (m->find())
				{
					cachedIconState = m->group(1);
				}
				else
				{
					cachedIconState = L"";
				}
			}
			return cachedIconState;
		}

		virtual int getDir()
		{
			if (cachedDir == -1)
			{
				try
				{
					cachedDir = std::stoi(getVar(L"dir"));
				}
				catch (const NumberFormatException &e)
				{
					cachedDir = 2;
				}
			}
			return cachedDir;
		}

		virtual int getPixelX()
		{
			if (cachedPixelX == -1234)
			{
				try
				{
					cachedPixelX = std::stoi(getVar(L"pixel_x"));
				}
				catch (const NumberFormatException &e)
				{
					cachedPixelX = 2;
				}
			}
			return cachedPixelX;
		}

		virtual int getPixelY()
		{
			if (cachedPixelY == -1234)
			{
				try
				{
					cachedPixelY = std::stoi(getVar(L"pixel_y"));
				}
				catch (const NumberFormatException &e)
				{
					cachedPixelY = 2;
				}
			}
			return cachedPixelY;
		}

		virtual float getLayer()
		{
			if (cachedLayer == -1234)
			{
				try
				{
					cachedLayer = std::stof(getVar(L"layer"));
				}
				catch (const NumberFormatException &e)
				{
					cachedLayer = 2;
				}
			}
			return cachedLayer;
		}

		virtual Color *getColor()
		{
			if (cachedColor == nullptr)
			{
				std::wstring var = getVar(L"color");
				Matcher *m = Pattern::compile(L"(#[\\d\\w][\\d\\w][\\d\\w][\\d\\w][\\d\\w][\\d\\w])").matcher(var);
				if (m->find())
				{
					return cachedColor = Color::decode(m->group(1));
				}
				m = Pattern::compile(L"rgb ?\\( ?([\\d]+) ?, ?([\\d]+) ?, ?([\\d]+) ?\\)").matcher(var);
				if (m->find())
				{
					int r = static_cast<int>(m->group(1));
					int g = static_cast<int>(m->group(2));
					int b = static_cast<int>(m->group(3));
					if (r > 255)
					{
						r = 255;
					}
					if (g > 255)
					{
						g = 255;
					}
					if (b > 255)
					{
						b = 255;
					}
					return cachedColor = new Color(r, g, b);
				}
				m = Pattern::compile(L"\"(black|silver|grey|gray|white|maroon|red|purple|fuchsia|magenta|green|lime|olive|gold|yellow|navy|blue|teal|aqua|cyan)\"").matcher(var);
				if (m->find())
				{
//JAVA TO C++ CONVERTER NOTE: The following 'switch' operated on a string and was converted to C++ 'if-else' logic:
//					switch(m.group(1))
//ORIGINAL LINE: case "black":
					if (m->group(1) == L"black")
					{
						return cachedColor = Color::decode(L"#000000");
					}
//ORIGINAL LINE: case "silver":
					else if (m->group(1) == L"silver")
					{
						return cachedColor = Color::decode(L"#C0C0C0");
					}
//ORIGINAL LINE: case "gray":
					else if (m->group(1) == L"gray")
					{
						return cachedColor = Color::decode(L"#808080");
					}
//ORIGINAL LINE: case "grey":
					else if (m->group(1) == L"grey")
					{
						return cachedColor = Color::decode(L"#808080");
					}
//ORIGINAL LINE: case "white":
					else if (m->group(1) == L"white")
					{
						return cachedColor = Color::decode(L"#FFFFFF");
					}
//ORIGINAL LINE: case "maroon":
					else if (m->group(1) == L"maroon")
					{
						return cachedColor = Color::decode(L"#800000");
					}
//ORIGINAL LINE: case "red":
					else if (m->group(1) == L"red")
					{
						return cachedColor = Color::decode(L"#FF0000");
					}
//ORIGINAL LINE: case "purple":
					else if (m->group(1) == L"purple")
					{
						return cachedColor = Color::decode(L"#800080");
					}
//ORIGINAL LINE: case "fuchsia":
					else if (m->group(1) == L"fuchsia")
					{
						return cachedColor = Color::decode(L"#FF00FF");
					}
//ORIGINAL LINE: case "magenta":
					else if (m->group(1) == L"magenta")
					{
						return cachedColor = Color::decode(L"#FF00FF");
					}
//ORIGINAL LINE: case "green":
					else if (m->group(1) == L"green")
					{
						return cachedColor = Color::decode(L"#00C000");
					}
//ORIGINAL LINE: case "lime":
					else if (m->group(1) == L"lime")
					{
						return cachedColor = Color::decode(L"#00FF00");
					}
//ORIGINAL LINE: case "olive":
					else if (m->group(1) == L"olive")
					{
						return cachedColor = Color::decode(L"#808000");
					}
//ORIGINAL LINE: case "gold":
					else if (m->group(1) == L"gold")
					{
						return cachedColor = Color::decode(L"#808000");
					}
//ORIGINAL LINE: case "yellow":
					else if (m->group(1) == L"yellow")
					{
						return cachedColor = Color::decode(L"#FFFF00");
					}
//ORIGINAL LINE: case "navy":
					else if (m->group(1) == L"navy")
					{
						return cachedColor = Color::decode(L"#000080");
					}
//ORIGINAL LINE: case "blue":
					else if (m->group(1) == L"blue")
					{
						return cachedColor = Color::decode(L"#0000FF");
					}
//ORIGINAL LINE: case "teal":
					else if (m->group(1) == L"teal")
					{
						return cachedColor = Color::decode(L"#008080");
					}
//ORIGINAL LINE: case "aqua":
					else if (m->group(1) == L"aqua")
					{
						return cachedColor = Color::decode(L"#00FFFF");
					}
//ORIGINAL LINE: case "cyan":
					else if (m->group(1) == L"cyan")
					{
						return cachedColor = Color::decode(L"#00FFFF");
					}
				}
				if (var != L"" && var != L"null")
				{
					System::err::println(L"Unrecognized color " + var);
				}
				return cachedColor = new Color(255,255,255);
			}
			return cachedColor;
		}

		virtual int getPlane()
		{
			if (cachedPlane == -1234)
			{
				try
				{
					cachedPlane = std::stoi(getVar(L"plane"));
				}
				catch (const NumberFormatException &e)
				{
					cachedPlane = 0;
				}
			}
			return cachedPlane;
		}
	};

}
