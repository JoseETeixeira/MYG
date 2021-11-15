#pragma once

#include <string>
#include "exceptionhelper.h"
#include "../../third_party/color/src/color/color.hpp"

namespace BYOND
{

	class ObjInstance
	{
	public:
		virtual std::string getVar(const std::string& key) = 0;
		virtual std::string typeString() = 0;
		virtual bool istype(const std::string& path) = 0;
		virtual std::string toStringTGM() = 0;

	private:
		int cachedDir = -1;
		int cachedPixelX = -1234;
		int cachedPixelY = -1234;
		float cachedLayer = -1234;
		int cachedPlane = -1234;
		color::rgb<double> cachedColor;
		std::string cachedIconState = "";
		std::string cachedIcon = "";

	public:
		virtual ~ObjInstance()
		{

		}

		virtual std::string getIcon()
		{
			if (cachedIcon == "")
			{
				std::string var = getVar("icon");
				
				if (var == "")
				{
					return cachedIcon = "";
				}
				std::smatch patternMatch;
				std::regex_search(var, patternMatch, std::regex("'(.+)'"));

				if (!patternMatch.empty())
				{
					cachedIcon = patternMatch[1];
				}
				else
				{
					cachedIcon = "";
				}
			}
			return cachedIcon;
		}

		virtual std::string getIconState()
		{
			if (cachedIconState == "")
			{	
				std::string var = getVar("icon_state");
				std::smatch patternMatch;
				std::regex_search(var , patternMatch, std::regex("\"(.+)\""));

				if (!patternMatch.empty())
				{
					cachedIconState = patternMatch[1];
				}
				else
				{
					cachedIconState = "";
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
					cachedDir = std::stoi(getVar("dir"));
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
					cachedPixelX = std::stoi(getVar("pixel_x"));
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
					cachedPixelY = std::stoi(getVar("pixel_y"));
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
					cachedLayer = std::stof(getVar("layer"));
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
			
			std::string var = getVar("color");
			std::smatch patternMatch;
			std::regex_search(var, patternMatch, std::regex("(#[\\d\\w][\\d\\w][\\d\\w][\\d\\w][\\d\\w][\\d\\w])"));
			if (!patternMatch.empty())
			{
				std::string match = patternMatch[1];
				int r;
				int g;
				int bi;
				sscanf(match.c_str() , "%02x%02x%02x", &r, &g, &bi);
				double rd, gd, bd;
				rd = (double) r;
				gd = (double)g;
				bd = (double) bi;
				cachedColor = color::rgb<double>({ rd, gd, bd });
				return cachedColor;
			}
			std::regex_search(var, patternMatch, std::regex("rgb ?\\( ?([\\d]+) ?, ?([\\d]+) ?, ?([\\d]+) ?\\)"));
			if (!patternMatch.empty())
			{
				int r = std::stoi(patternMatch[1]);
				int g = std::stoi(patternMatch[2]);
				int bi = std::stoi(patternMatch[3]);
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
			std::regex_search(var, patternMatch, std::regex("\"(black|silver|grey|gray|white|maroon|red|purple|fuchsia|magenta|green|lime|olive|gold|yellow|navy|blue|teal|aqua|cyan)\""));
			if (!patternMatch.empty())
			{
				std::string match = patternMatch[1];
					//ORIGINAL LINE: case "black":
				if (match == ("black"))
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
				if (match == ( "silver"))
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
				if (match == ( "gray"))
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
				if (match == ( "grey"))
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
				if (match == ( "white"))
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
				if (match == ( "maroon"))
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
				if (match == ( "red"))
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
				if (match == ( "purple"))
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
				if (match == ( "fuchsia"))
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
				if (match == ("magenta")) 
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
				if (match == ( "green"))
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
				if (match == ( "lime"))
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
				if (match == ( "olive"))
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
				if (match == ( "gold"))
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
				if (match == ( "yellow"))
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
				if (match == ( "navy"))
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
				if (match == ( "blue"))
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
				if( match == ( "teal"))
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
				if (match == ( "aqua"))
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
				if (match == ( "cyan"))
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
				if (var != "" && var != "null")
				{
					spdlog::error("Unrecognized color " + var);
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
					cachedPlane = std::stoi(getVar("plane"));
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
