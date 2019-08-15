#pragma once
#include "CSATELITE.h"
#include "SFML/Graphics.hpp"
#include "CNODO.h"
class PLANETA :public CNODO
{
public:
	PLANETA();
	~PLANETA();
	void addSatelite(SATELITE*);

	void setName(std::string name) { nombre = name; };
	std::string getName() { return nombre; };
	
	void setRatio(float rat) { ratio = rat; };
	float getRatio() { return ratio; };
	
	void setPosition(sf::Vector2f pos) { position = pos; };
	sf::Vector2f getPosition(sf::Vector2f pos) { return position; };
	
	int getNumLunas() { return lunas.size(); };

	void setMasa(float ms) { masa = ms; };
	float getMasa() { return masa; };

	void setSpeeds(float max, float min) 
	{ 
		speedAfelio = max; speedgHepielio = min; 
		difVel = max - min;
	};	

	void setDistToFoco(float max, float min) 
	{ 
		Afelio = max; perihelio = min; 
		ratioTotal = min + max;
	};


	void onInit();
	void onUpdate();
	void onDelete();
  void setShape();
  void setShapeColor(sf::Color color);
	void draw(sf::RenderWindow & wnd, const float &spped);

	void calcularCentroMasa();
	float calcularMasaTotal();
	void setDaysToComplete(float days) { dias = days; };

private:
  float time;
	float ratio;
	float Afelio;
	float perihelio;
	float speedAfelio;
	float speedgHepielio;
	float masa;
  float m_direction_X = -1;
	sf::Vector2f centroDeMasa;
  sf::Color planetColor;
	//sf::Vector2f position;
	//std::string nombre;
	sf::CircleShape planeta;
  sf::Transform T;
	std::vector<SATELITE*> lunas;
	float ratioTotal = 0;
	float difVel=0;
	float speed = 0;
	float dias = 1000;
};

