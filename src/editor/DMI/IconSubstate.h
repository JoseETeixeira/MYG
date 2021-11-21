#pragma once

#include "DMI.h"
#include <cmath>

//JAVA TO C++ CONVERTER NOTE: Forward class declarations:
namespace MYG::dmirender { class Scaled; }

namespace MYG::dmirender
{

	using Component = java::awt::Component;
	using Graphics = java::awt::Graphics;
	using Graphics2D = java::awt::Graphics2D;
	using RenderingHints = java::awt::RenderingHints;

	using Icon = javax::swing::Icon;

	class IconSubstate : public Icon
	{
	public:
		DMI *dmi;
		int index = 0;
		int x = 0;
		int y = 0;
		float x1 = 0;
		float x2 = 0;
		float y1 = 0;
		float y2 = 0;
		int i_x1 = 0;
		int i_x2 = 0;
		int i_y1 = 0;
		int i_y2 = 0;

		static constexpr float UV_MARGIN = .000001f;

		virtual ~IconSubstate()
		{
			delete dmi;
			delete cachedScaled;
		}

		IconSubstate(DMI *dmi, int index)
		{
			this->dmi = dmi;
			this->index = index;
			x = (index % dmi->cols);
			y = static_cast<int>(std::floor(static_cast<float>(index) / static_cast<float>(dmi->cols)));
			x1 = (static_cast<float>(x) / static_cast<float>(dmi->cols)) + UV_MARGIN;
			y1 = (static_cast<float>(y) / static_cast<float>(dmi->rows)) + UV_MARGIN;
			x2 = (static_cast<float>(x + 1) / static_cast<float>(dmi->cols)) - UV_MARGIN;
			y2 = (static_cast<float>(y + 1) / static_cast<float>(dmi->rows)) - UV_MARGIN;
			i_x1 = x * dmi->width;
			i_y1 = y * dmi->height;
			i_x2 = (x + 1) * dmi->width - 1;
			i_y2 = (y + 1) * dmi->height - 1;
		}

		int getIconHeight() override
		{
			// TODO Auto-generated method stub
			return dmi->height;
		}

		int getIconWidth() override
		{
			// TODO Auto-generated method stub
			return dmi->width;
		}

		// Return true if substate is fully opaque.
		virtual bool isOpaque()
		{
			if (dmi->image == nullptr)
			{
				return true;
			}
			for (int px = i_x1; px <= i_x2; px++)
			{
				for (int py = i_y1; py <= i_y2; py++)
				{
					if (((dmi->image->getRGB(px,py) >> 24) & 0xFF) < 200)
					{
						return false;
					}
				}
			}
			return true;
		}

		void paintIcon(Component *arg0, Graphics *arg1, int px, int py) override
		{
			arg1->drawImage(dmi->image, px, py, px + dmi->width - 1, py + dmi->height - 1, i_x1, i_y1, i_x2, i_y2, arg0);
		}

		Scaled *cachedScaled;

		virtual Icon *getScaled()
		{
			if (cachedScaled == nullptr)
			{
				cachedScaled = new Scaled(this);
			}
			return cachedScaled;
		}

	public:
		class Scaled : public Icon
		{
		public:
			IconSubstate *parent;
			float scalingFactor = .5f;
			virtual ~Scaled()
			{
				delete parent;
			}

			Scaled(IconSubstate *parent)
			{
				this->parent = parent;
				scalingFactor = 16.0f / parent->dmi->height;
			}

			int getIconHeight() override
			{
				return static_cast<int>(parent->dmi->height * scalingFactor);
			}

			int getIconWidth() override
			{
				return static_cast<int>(parent->dmi->width * scalingFactor);
			}

			void paintIcon(Component *c, Graphics *g, int px, int py) override
			{
				if (dynamic_cast<Graphics2D*>(g) != nullptr)
				{
					(static_cast<Graphics2D*>(g))->setRenderingHint(RenderingHints::KEY_INTERPOLATION, RenderingHints::VALUE_INTERPOLATION_BILINEAR);
				}
				g->drawImage(parent->dmi->image, px, py, px + getIconWidth() - 1, py + getIconHeight() - 1, parent->i_x1, parent->i_y1, parent->i_x2, parent->i_y2, c);
			}

		};
	};

}
