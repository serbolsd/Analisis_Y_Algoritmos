#include "../include/CPLANETA.h"
PLANETA::PLANETA()
{
}

PLANETA::~PLANETA()
{
}

void PLANETA::addSatelite(SATELITE * newSatelite)
{
	newSatelite->parent = this;
	childrens.push_back(newSatelite);
	lunas.push_back(newSatelite);
}

void PLANETA::onInit()
{
}

void PLANETA::onUpdate()
{
	time +=(1/dias)*speed;
	if (position.x < 0)
	{
		position.x = perihelio * cos(time);
		if (position.x < -perihelio)
		{
			position.x = -perihelio;
		}
	}
	else
	{
		position.x = Afelio * cos(time);
		if (position.x > Afelio)
		{
			position.x = Afelio;
		}
	}
	float por = perihelio + position.x;
	por = por / ratioTotal;
	speed = speedgHepielio+(difVel*por);
	float ratioTemp;

	ratioTemp = Afelio * (speed / speedAfelio);
	position.y = ratioTemp*sin(time);
  planeta.setPosition(position.x, position.y  );
  anteposition = position;
  for (int i = 0; i < lunas.size(); i++)
  {
	  lunas[i]->onUpdate();
  }
}

void PLANETA::onDelete()
{
	for (int i = 0; i < lunas.size(); i++)
	{
		lunas[i]->onDelete();
		delete lunas[i];
	}
}

void PLANETA::setShape()
{
  planeta.setRadius(ratio);
  planeta.setPosition(position.x, position.y);
  planeta.setFillColor(planetColor);
  planeta.setOrigin(sf::Vector2f(ratio, ratio));
}

void PLANETA::setShapeColor(sf::Color color)
{
  planetColor = color;
  setShape();
}

void PLANETA::draw(sf::RenderWindow & wnd, const float &spped)
{
  speed *= spped;
  //onUpdate();
  wnd.draw(planeta);
  for (int i = 0; i < lunas.size(); i++)
  {
	  lunas[i]->draw(wnd, spped);
  }
}
