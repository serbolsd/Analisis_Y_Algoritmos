#pragma once
#include "CNODO.h"
#include "CFOCO.h"
#include "CPLANETA.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
class SISTEMASOLAR :public CNODO
{
public:
	SISTEMASOLAR();
	~SISTEMASOLAR();
	void addPlanet(PLANETA*);
	void addFoco(FOCO*);

	void setName(std::string name) { nombre = name; };
	std::string getName() { return nombre; };
	
	void setRatio(float rat) { ratio = rat; };
	float getRatio() { return ratio; };
	
	void setPosition(sf::Vector2f pos) { position = pos; };
	sf::Vector2f getPosition(sf::Vector2f pos) { return position; };
	
	int getNumFocos() { return focos.size(); };
	int getNumPlanets() { return planetas.size(); };

	void onInit();
	void onUpdate();
	void onDelete();

  
	void calcularCentroMasa();
	float calcularMasaTotal();
	void drawSistem(sf::RenderWindow &wnd, const float &spped);
	

private:

	std::vector<FOCO*> focos;
	std::vector<PLANETA*> planetas;
	sf::Vector2f centroDeMasa;
	float masaTotal;
	//sf::Vector2f position;
	//std::string nombre;
	float ratio;
	sf::CircleShape sistem;
};
