#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "CNODO.h"
class SATELITE :public CNODO
{
public:
	SATELITE();
	~SATELITE();
	void setName(std::string name) { nombre = name; };
	std::string getName() { return nombre; };

	void setRatio(float rat) { ratio = rat; };
	float getRatio() { return ratio; };

	void setPosition(sf::Vector2f pos) { relativePosition = pos; };
	sf::Vector2f getPosition(sf::Vector2f pos) { return position; };

	void setMasa(float ms) { masa = ms; };
	float getMasa() { return masa; };

	void setSpeeds(float max, float min) 
	{ speedAfelio = max; speedgHepielio = min; 
	difVel = max - min;
	};
	
	void distToPlanet(float max, float min) 
	{ Afelio = max; perihelio = min; 
	ratioTotal = min + max;
	};

	void onInit() {};
	void onUpdate();
	void onDelete() {};
	void draw(sf::RenderWindow & wnd, const float &spped);
	void setShape();
	void setShapeColor(sf::Color color);
	void setDaysToComplete(float days) { dias = days; };
private:
	float ratio;
	float Afelio;
	float perihelio;
	float speedAfelio;
	float speedgHepielio;
	float masa;
	sf::Vector2f centroDeMasa;
	//sf::Vector2f position;
	//std::string nombre;
	sf::CircleShape luna;
	sf::Color lunaColor;
	float ratioTotal = 0;
	float difVel = 0;
	float speed = 0;
	float time;
	float dias=1;
};

