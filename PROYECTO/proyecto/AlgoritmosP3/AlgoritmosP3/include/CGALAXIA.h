#pragma once
#include "CSISTEMASOLAR.h"
#include "CNODO.h"
#include <vector>
#include <SFML/Graphics.hpp>
class GALAXIA:public CNODO
{
public:
	GALAXIA();
	~GALAXIA();
	void addSistem(SISTEMASOLAR*);

	void setName(std::string name) { nombre = name; };
	std::string getName() { return nombre; };

	void setRatio(float rat) { ratio = rat; };
	float getRatio() { return ratio; };

	void setPosition(sf::Vector2f pos) { position = pos; };
	sf::Vector2f getPosition(sf::Vector2f pos) { return position; };

	int getNumSistems() { return sistemas.size(); };

	void onInit();
	void onUpdate();
	void onDelete();
	void drawGalaxi(sf::RenderWindow &wnd, const float &spped);
	void drawSistem(sf::RenderWindow);
	void drawPlanet(sf::RenderWindow);


	//void calcularCentroMasa();
	//float calcularMasaTotal();

private:
	std::vector<SISTEMASOLAR*> sistemas;
	sf::Vector2f centroDeMasa;
	//sf::Vector2f position;
	//std::string nombre;
	sf::CircleShape galaxi;
	float ratio;
};

