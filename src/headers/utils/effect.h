#ifndef EFFECT_H
#define EFFECT_H

#include "../include/const.h"
#include "../include/lib.h"

#include "textures.h"
#include "point2D.h"
#include "../GUI/drawable.h"
#include "animable.h"
#include "animEffect.h"

//xTile, yTile, frames, duration
static const int effects[1][4] = {
	{0, 0, 12, 16}
};

class Effect : public Drawable, public Animable {
	public:
		Effect(int unitInfo, Point2D position);
		~Effect();

		const Point2D &getPosition() const {return position;}
		const int &getNFrames() const {return nFrames;}
		const int &getDuration() const {return duration;}
		const int &getXTile() const {return xTile;}
		const int &getYTile() const {return yTile;}

		virtual bool render(Camera *camera);

		static std::list<Effect*> effectsController;
		static void cleanEffects();

		sf::Sprite *sprite;
		
	private:
		Point2D position;
		int nFrames;
		int duration;
		int xTile;
		int yTile;

		void effectFactory(int effectInfo);
};

#endif
