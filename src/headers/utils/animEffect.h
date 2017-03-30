#ifndef ANIM_EFFECT_H
#define ANIM_EFFECT_H

#include "../include/const.h"
#include "../include/lib.h"

#include "../GUI/drawable.h"
#include "animation.h"
#include "effect.h"

class Camera;
class Effect;

class AnimEffect : public Animation {
	public:
		AnimEffect(Effect *effect);
		~AnimEffect();

		virtual bool step();
		
	private:
		Effect *effect;
};

#endif