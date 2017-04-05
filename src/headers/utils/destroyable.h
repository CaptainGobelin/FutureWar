#ifndef DESTROYABLE_H
#define DESTROYABLE_H

#include "../include/const.h"
#include "../include/lib.h"

class Destroyable {
	public:
		Destroyable();
		virtual ~Destroyable();

		static std::list<Destroyable*> destroyables;
		static void cleanDestroyables();
		
	protected:
		bool toDestroy;
};

#endif