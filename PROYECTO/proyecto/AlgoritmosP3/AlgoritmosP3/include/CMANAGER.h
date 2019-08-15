#pragma once
#include "Window.h"
#include "Camera.h"
#include "CSATELITE.h"
#include "CPLANETA.h"
#include "CFOCO.h"
#include "CSISTEMASOLAR.h"
#include "CGALAXIA.h"
#include "CNODO.h"


class MANAGER
{
public:
	char* namePlan;
	std::string nameToNAME="";
	MANAGER();
	~MANAGER();
	CNODO *NODE;
	void onIniti();
	void onLoop();
	void onDelete();
	void initSearch(std::string namePlanet);
    void onRender(sf::RenderWindow & Wnd);
    void onUpdate();
	CNODO *search(std::string name,CNODO *node);
	CCamera camera;
	float *cameraSpeed;
	float *SpeedWord;
	float *realSpeedWord;
	bool focusPlanet = false;
private:
	GALAXIA* galaxia;
};
