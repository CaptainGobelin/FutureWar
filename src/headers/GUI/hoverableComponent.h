#ifndef HOVERABLE_COMP_H
#define HOVERABLE_COMP_H

#include "../include/const.h"
#include "../include/lib.h"

#include "hoverable.h"

class HoverableComponent {
	public:
		HoverableComponent(Hoverable* parent);

		const bool &isHover() const {return hover;}
		void setHover(bool hover) {this->hover = hover;}

		virtual int hoverEvent() = 0;
		virtual int leftClickEvent() = 0;

		Hoverable* parent;

	protected:
		bool hover;
};

#endif
