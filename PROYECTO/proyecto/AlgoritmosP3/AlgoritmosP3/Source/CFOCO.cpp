#include "../include/CFOCO.h"

FOCO::FOCO()
{
}

FOCO::~FOCO()
{
}

void FOCO::onUpdate()
{
}

void FOCO::setShape()
{
  foco.setRadius(ratio);
  foco.setPosition(position.x, position.y);
  foco.setFillColor(focoColor);
  foco.setOrigin(sf::Vector2f(ratio, ratio));
}

void FOCO::setShapeColor(sf::Color color)
{
  focoColor = color;
  setShape();
}

void FOCO::draw(sf::RenderWindow & wnd, const float &spped)
{
  wnd.draw(foco);
}
