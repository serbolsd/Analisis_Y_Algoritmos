#include "../include/CMANAGER.h"

MANAGER::MANAGER()
{
}

MANAGER::~MANAGER()
{
	delete cameraSpeed;
	delete SpeedWord;
	delete realSpeedWord;
	delete[]namePlan;
}

void MANAGER::onIniti()
{
	namePlan = new char[255];
	for (int i = 0; i < 255; i++)
	{
		namePlan[i] = '\0';
	}
	camera;
	camera.initCamera(0,0,1920,1080);
	cameraSpeed = new float(10);
	SpeedWord = new float(0.1);
	realSpeedWord = new float((*SpeedWord)/10);
	SISTEMASOLAR* sis1 = new SISTEMASOLAR;
	sis1->setName("VIA LACTEA");
  // Sun
	FOCO* sol = new FOCO;
  sis1->addFoco(sol);
	sol->setName("SOL");
	sol->setRatio(200);
	sol->setPosition(sf::Vector2f(0,0));
  sol->setShapeColor(sf::Color::Yellow);
  // Mercury
  PLANETA* Mercurio = new PLANETA;
  sis1->addPlanet(Mercurio);
  Mercurio->setMasa(2);
  Mercurio->setName("MERCURIO");
  Mercurio->setRatio(2.439);
  Mercurio->setDistToFoco(698, 460);
  Mercurio->setPosition(sf::Vector2f(698, 0));
  Mercurio->setShapeColor(sf::Color::Blue);
  Mercurio->setSpeeds(48,47.74);
  Mercurio->setDaysToComplete(55.25);
  
  // Venus
  PLANETA* Venus = new PLANETA;
  sis1->addPlanet(Venus);
  Venus->setMasa(4);
  Venus->setName("VENUS");
  Venus->setRatio(6.52);
  Venus->setDistToFoco(1090, 1074);
  Venus->setPosition(sf::Vector2f(1090, 0));
  Venus->setShapeColor(sf::Color(255, 153, 51));
  Venus->setSpeeds(36, 34.06);
  Venus->setDaysToComplete(224);
 
  // Earth
  SATELITE* luna = new SATELITE();
  luna->setName("LUNA");
  luna->setRatio(1.737);
  luna->distToPlanet(40.6,35.6);
  luna->setPosition(sf::Vector2f(40.6,0));
  luna->setShapeColor(sf::Color::White);
  luna->setSpeeds(1.300,1.250);
  luna->setDaysToComplete(1);
	PLANETA* tierra = new PLANETA;
	sis1->addPlanet(tierra);
	tierra->setMasa(10);
	tierra->setName("TIERRA");
	tierra->setRatio(6.378);
	tierra->setDistToFoco(1520, 1470);
  tierra->setPosition(sf::Vector2f(1520,0));
  tierra->setShapeColor(sf::Color(00, 102, 255));
  tierra->setSpeeds(30, 39.58);
  tierra->addSatelite(luna);
  tierra->setDaysToComplete(365);

  // Mars
  SATELITE* fobos = new SATELITE();
  fobos->setName("FOBOS");
  fobos->setRatio(0.011267);
  fobos->distToPlanet(19.6, 9.4);
  fobos->setPosition(sf::Vector2f(100, 0));
  fobos->setShapeColor(sf::Color::White);
  fobos->setSpeeds(2.13, 1.90);
  fobos->setDaysToComplete(0.3189);
  SATELITE* deimos = new SATELITE();
  deimos->setName("DEIMOS");
  deimos->setRatio(0.0062);
  deimos->distToPlanet(23.460, 23.0);
  deimos->setPosition(sf::Vector2f(232.60, 0));
  deimos->setShapeColor(sf::Color::White);
  deimos->setSpeeds(1.36, 1.12);
  deimos->setDaysToComplete(1.2625);
  PLANETA* Marte = new PLANETA;
  sis1->addPlanet(Marte);
  Marte->setMasa(6);
  Marte->setName("MARTE");
  Marte->setRatio(3.397);
  Marte->setDistToFoco(2491, 2067);
  Marte->setPosition(sf::Vector2f(2491, 0));
  Marte->setShapeColor(sf::Color::Red);
  Marte->setSpeeds(25, 23.26);
  Marte->setDaysToComplete(687);
  Marte->addSatelite(fobos);
  Marte->addSatelite(deimos);
  // Jupiter
  PLANETA* Jupiter = new PLANETA;
  sis1->addPlanet(Jupiter);
  Jupiter->setMasa(14);
  Jupiter->setName("JUPITER");
  Jupiter->setRatio(71.5);
  Jupiter->setDistToFoco(8157, 7409);
  Jupiter->setPosition(sf::Vector2f(8157, 0));
  Jupiter->setShapeColor(sf::Color(217, 179, 140));
  Jupiter->setSpeeds(14, 12.12);
  Jupiter->setDaysToComplete(4380);
  // Saturn
  PLANETA* Saturno = new PLANETA;
  sis1->addPlanet(Saturno);
  Saturno->setMasa(17);
  Saturno->setName("SATURNO");
  Saturno->setRatio(60.3);
  Saturno->setDistToFoco(15070, 13470);
  Saturno->setPosition(sf::Vector2f(15070, 0));
  Saturno->setShapeColor(sf::Color(255, 187, 51));
  Saturno->setSpeeds(10, 9.28);
  Saturno->setDaysToComplete(10252);
  // Uranus
  PLANETA* Urano = new PLANETA;
  sis1->addPlanet(Urano);
  Urano->setMasa(11);
  Urano->setName("URANO");
  Urano->setRatio(25.6);
  Urano->setDistToFoco(30040, 27350);
  Urano->setPosition(sf::Vector2f(30040, 0));
  Urano->setShapeColor(sf::Color(204, 255, 255));
  Urano->setSpeeds(7, 6.62);
  Urano->setDaysToComplete(30660);
  // Neptune
  PLANETA* Neptuno = new PLANETA;
  sis1->addPlanet(Neptuno);
  Neptuno->setMasa(12);
  Neptuno->setName("NEPTUNO");
  Neptuno->setRatio(24.8);
  Neptuno->setDistToFoco(45370, 44560);
  Neptuno->setPosition(sf::Vector2f(4537, 0));
  Neptuno->setShapeColor(sf::Color::Green);
  Neptuno->setSpeeds(6, 4.86);
  Neptuno->setDaysToComplete(59860);
  galaxia = new GALAXIA;
  galaxia->setName("ANDROMEDA");
  galaxia->addSistem(sis1);
  galaxia->onInit();


}

void MANAGER::onDelete()
{
	galaxia->onDelete();
	delete galaxia;
}

void MANAGER::initSearch(std::string namePlanet)
{
	std::string str = namePlanet;
	CNODO* FIND = search(namePlanet,galaxia);
	nameToNAME = "nodo ";
	nameToNAME += str;
	if (FIND==nullptr)
	{
		
		nameToNAME += " NO encontrado";

		std::cout << "nodo " << namePlanet << " NO encontrado\n";
	}
	else
	{
		nameToNAME += " SI encontrado";
		std::cout << "nodo " << namePlanet << " SI encontrado\n";
		focusPlanet = true;
		//delete FIND;
	}
	
}

void MANAGER::onRender(sf::RenderWindow & Wnd)
{
  galaxia->drawGalaxi(Wnd,*realSpeedWord);
}

void MANAGER::onUpdate()
{
	galaxia->onUpdate();
}



CNODO * MANAGER::search(std::string name, CNODO * node)
{
	if (node->nombre != name)
	{
		for (int i = 0; i < node->childrens.size(); i++)
		{
			NODE = search(name, node->childrens[i]);
			if (NODE !=nullptr)
			{
				return NODE;
			}
		}
	}
	else
	{
		return node;
	}
	return nullptr;
}

