#include "../include/CSISTEMASOLAR.h"


SISTEMASOLAR::SISTEMASOLAR()
{
	capa = galaxia;
}

SISTEMASOLAR::~SISTEMASOLAR()
{
}

void SISTEMASOLAR::addPlanet(PLANETA * newPlanet)
{
	newPlanet->parent = this;
	childrens.push_back(newPlanet);
	planetas.push_back(newPlanet);
}

void SISTEMASOLAR::addFoco(FOCO *newfoco)
{
	newfoco->parent = this;
	childrens.push_back(newfoco);
	focos.push_back(newfoco);
}

void SISTEMASOLAR::onInit()
{
  for (int i = 0; i < planetas.size(); i++)
  {
    planetas[i]->setShape();
  }
}

void SISTEMASOLAR::onUpdate()
{
	for (int i = 0; i < focos.size(); i++)
	{
		focos[i]->onUpdate();
	}
	for (int i = 0; i < planetas.size(); i++)
	{
		planetas[i]->onUpdate();
	}
}

void SISTEMASOLAR::onDelete()
{
	for (int i = 0; i < focos.size(); i++)
	{
		focos[i]->onDelete();
		delete focos[i];
	}
	for (int i = 0; i < planetas.size(); i++)
	{
		planetas[i]->onDelete();
		delete planetas[i];
	}
}

void SISTEMASOLAR::calcularCentroMasa()
{
}

float SISTEMASOLAR::calcularMasaTotal()
{
	float sum=0;
	for (int i = 0; i < focos.size(); i++)
	{
		sum += focos[i]->getMasa();
	}
	for (int i = 0; i < planetas.size(); i++)
	{
		sum += planetas[i]->getMasa();
	}
	return sum;
}

void SISTEMASOLAR::drawSistem(sf::RenderWindow &wnd, const float &spped)
{
	for (int i = 0; i < focos.size(); i++)
	{
		focos[i]->draw(wnd,spped);
	}
	for (int i = 0; i < planetas.size(); i++)
	{
    planetas[i]->draw(wnd,spped);
	}
}
