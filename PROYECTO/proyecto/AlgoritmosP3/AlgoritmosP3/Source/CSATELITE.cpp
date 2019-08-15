#include "../include/CSATELITE.h"
SATELITE::SATELITE()
{
}

SATELITE::~SATELITE()
{
}

void SATELITE::onUpdate()
{
	time += (1/dias)*speed;
	if (relativePosition.x < 0)
	{
		relativePosition.x = perihelio * cos(time);
		if (relativePosition.x < -perihelio)
		{
			relativePosition.x = -perihelio;
		}
	}
	else
	{
		relativePosition.x = Afelio * cos(time);
		if (relativePosition.x > Afelio)
		{
			relativePosition.x = Afelio;
		}
	}
	float por = perihelio + relativePosition.x;
	por = por / ratioTotal;
	speed = speedgHepielio + (difVel*por);
	float ratioTemp;

	ratioTemp = Afelio * (speed / speedAfelio);
	relativePosition.y = ratioTemp * sin(time);
	position = relativePosition + parent->position;
	luna.setPosition(position.x, position.y);
	anteposition = position;
}

void SATELITE::draw(sf::RenderWindow & wnd, const float & spped)
{
	speed *= spped;
	wnd.draw(luna);
}

void SATELITE::setShape()
{
	luna.setRadius(ratio);
	luna.setPosition(position.x, position.y);
	luna.setFillColor(lunaColor);
	luna.setOrigin(sf::Vector2f(ratio, ratio));
}

void SATELITE::setShapeColor(sf::Color color)
{
	lunaColor = color;
	setShape();
}