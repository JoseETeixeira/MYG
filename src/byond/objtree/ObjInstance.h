#include <string>
#include <regex>
#include "../exceptionhelper.h"
#include "../../../third_party/color/src/color/color.hpp"
#pragma once



namespace BYOND
{

	class ObjInstance
	{
	public:
		virtual std::wstring getVar(const std::wstring& key) = 0;
		virtual std::wstring typeString() = 0;
		virtual bool istype(const std::wstring& path) = 0;
		virtual std::wstring toStringTGM() = 0;

	private:
		int cachedDir = -1;
		int cachedPixelX = -1234;
		int cachedPixelY = -1234;
		float cachedLayer = -1234;
		int cachedPlane = -1234;
		color::rgb<double> cachedColor;
		std::wstring cachedIconState = L"";
		std::wstring cachedIcon = L"";


	public:
		virtual ~ObjInstance()
		{

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
				std::wsmatch patternMatch;
				std::regex_search(var, patternMatch, std::wregex(L"'(.+)'"));

				if (!patternMatch.empty())
				{
					cachedIcon = patternMatch.str(1);
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
				std::wstring var = getVar(L"icon_state");
				std::wsmatch patternMatch;
				std::regex_search(var , patternMatch, std::wregex(L"\"(.+)\""));

				if (!patternMatch.empty())
				{
					cachedIconState = patternMatch.str(1);
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
				catch (const NumberFormatException& e)
				{
					spdlog::error("Number format exception on getDir()");
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
				catch (const NumberFormatException& e)
				{
					spdlog::error("Number format exception on getPixelX()");
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
				catch (const NumberFormatException& e)
				{
					spdlog::error("Number format exception on getPixelY()");
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
				catch (const NumberFormatException& e)
				{
					spdlog::error("Number format exception on getLayer()");
					cachedLayer = 2;
				}
			}
			return cachedLayer;
		}

		virtual color::rgb<double> getColor()
		{
			
			std::wstring var = getVar(L"color");
			std::wsmatch patternMatch;
			std::regex_search(var, patternMatch, std::wregex(L"(#[\\d\\w][\\d\\w][\\d\\w][\\d\\w][\\d\\w][\\d\\w])"));
			if (!patternMatch.empty())
			{

				std::wstring match = patternMatch.str(1);
				std::stringstream mm;
				mm << match.c_str();
				int r;
				int g;
				int bi;
				sscanf(mm.str().c_str() , "%02x%02x%02x", &r, &g, &bi);
				double rd, gd, bd;
				rd = (double) r;
				gd = (double)g;
				bd = (double) bi;
				cachedColor = color::rgb<double>({ rd, gd, bd });
				return cachedColor;
			}
			std::regex_search(var, patternMatch, std::wregex(L"rgb ?\\( ?([\\d]+) ?, ?([\\d]+) ?, ?([\\d]+) ?\\)"));
			if (!patternMatch.empty())
			{
				int r = std::stoi(patternMatch.str(1));
				int g = std::stoi(patternMatch.str(2));
				int bi = std::stoi(patternMatch.str(3));
				if (r > 255)
				{
					r = 255;
				}
				if (g > 255)
				{
					g = 255;
				}
				if (bi > 255)
				{
					bi = 255;
				}
				double rd, gd, bd;
				rd = (double) r;
				gd = (double)g;
				bd = (double)bi;

				cachedColor = color::rgb<double>({ rd, gd, bd });
				return cachedColor;
			}
			std::regex_search(var, patternMatch, std::wregex(L"\"(black|silver|grey|gray|white|maroon|red|purple|fuchsia|magenta|green|lime|olive|gold|yellow|navy|blue|teal|aqua|cyan)\""));
			if (!patternMatch.empty())
			{
				std::wstring match = patternMatch[1];
					//ORIGINAL LINE: case "black":
				if (match == (L"black"))
					{
						int r;
						int g;
						int bi;
						sscanf("#000000", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double)r;
						gd = (double)g;
						bd = (double)bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "silver":
				if (match == ( L"silver"))
					{
						int r;
						int g;
						int bi;
						sscanf("#C0C0C0", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "gray":
				if (match == ( L"gray"))
					{
						int r;
						int g;
						int bi;
						sscanf("#808080", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "grey":
				if (match == ( L"grey"))
					{
						int r;
						int g;
						int bi;
						sscanf("#808080", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;

					}
					//ORIGINAL LINE: case "white":
				if (match == ( L"white"))
					{
						int r;
						int g;
						int bi;
						sscanf("#FFFFFF", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "maroon":
				if (match == ( L"maroon"))
					{
						int r;
						int g;
						int bi;
						sscanf("#800000", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;

					}
					//ORIGINAL LINE: case "red":
				if (match == ( L"red"))
					{
						int r;
						int g;
						int bi;
						sscanf("#FF0000", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;

					}
					//ORIGINAL LINE: case "purple":
				if (match == ( L"purple"))
					{
						int r;
						int g;
						int bi;
						sscanf("#800080", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "fuchsia":
				if (match == ( L"fuchsia"))
					{
						int r;
						int g;
						int bi;
						sscanf("#FF00FF", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "magenta":
				if (match == (L"magenta")) 
				{
					int r;
					int g;
					int bi;
					sscanf("#FF00FF", "%02x%02x%02x", &r, &g, &bi);
					double rd, gd, bd;
					rd = (double) r;
					gd = (double) g;
					bd = (double) bi;
					cachedColor = color::rgb<double>({ rd, gd, bd });
					return cachedColor;
				}
						
					//ORIGINAL LINE: case "green":
				if (match == ( L"green"))
					{
						int r;
						int g;
						int bi;
						sscanf("#00C000", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "lime":
				if (match == ( L"lime"))
					{
						int r;
						int g;
						int bi;
						sscanf("#00FF00", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "olive":
				if (match == ( L"olive"))
					{
						int r;
						int g;
						int bi;
						sscanf("#808000", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "gold":
				if (match == ( L"gold"))
					{
						int r;
						int g;
						int bi;
						sscanf("#808000", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "yellow":
				if (match == ( L"yellow"))
					{
						int r;
						int g;
						int bi;
						sscanf("#FFFF00", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "navy":
				if (match == ( L"navy"))
					{
						int r;
						int g;
						int bi;
						sscanf("#000080", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "blue":
				if (match == ( L"blue"))
					{
						int r;
						int g;
						int bi;
						sscanf("#0000FF", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "teal":
				if( match == ( L"teal"))
					{
						int r;
						int g;
						int bi;
						sscanf("#008080", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "aqua":
				if (match == ( L"aqua"))
					{
						int r;
						int g;
						int bi;
						sscanf("#00FFFF", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
					//ORIGINAL LINE: case "cyan":
				if (match == ( L"cyan"))
					{
						int r;
						int g;
						int bi;
						sscanf("#00FFFF", "%02x%02x%02x", &r, &g, &bi);
						double rd, gd, bd;
						rd = (double) r;
						gd = (double) g;
						bd = (double) bi;
						cachedColor = color::rgb<double>({ rd, gd, bd });
						return cachedColor;
					}
				}
				if (var != L"" && var != L"null")
				{
					spdlog::error("Unrecognized color ");
				}
				cachedColor = color::rgb<double>({ 255.0, 255.0, 255.0 });
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
				catch (const NumberFormatException& e)
				{
					cachedPlane = 0;
				}
			}
			return cachedPlane;
		}
	};

};