#include "../include/CGALAXIA.h"
GALAXIA::GALAXIA()
{
	capa = mundial;
}

GALAXIA::~GALAXIA()
{
}

void GALAXIA::addSistem(SISTEMASOLAR *newsistem)
{
	newsistem->parent = this;
	childrens.push_back(newsistem);
	sistemas.push_back(newsistem);
}

void GALAXIA::onInit()
{
  for (size_t i = 0; i < sistemas.size(); i++)
  {
    sistemas[i]->onInit();
  }
}

void GALAXIA::onUpdate()
{
	for (size_t i = 0; i < sistemas.size(); i++)
	{
		sistemas[i]->onUpdate();
	}
}

void GALAXIA::onDelete()
{
	for (size_t i = 0; i < sistemas.size(); i++)
	{
		sistemas[i]->onDelete();
		delete sistemas[i];
	}
}

void GALAXIA::drawGalaxi(sf::RenderWindow & wnd,const float &spped)
{
	for (int i = 0; i < sistemas.size(); i++)
	{
		sistemas[i]->drawSistem(wnd,spped);
	}
}



void GALAXIA::drawSistem(sf::RenderWindow)
{

}
