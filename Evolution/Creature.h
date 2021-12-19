#pragma once
#include "Brain.h"
class Creature
{
private:
	Brain brain;
	float posX, posY;
public:
	Creature(bool first)
	{
		if(first) brain.initialize_params();
	}
};

