
#include "include/CMANAGER.h"
#include <chrono>
#include <imgui-SFML.h>
#include <imgui.h>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
void imguiWind();
void sfmlInput(const sf::Event &event);
MANAGER g_manager;
int main()
{

	sf::RenderWindow window(sf::VideoMode(1920, 1080),"win");
	sf::Event even;
	g_manager.onIniti();
	ImGui::SFML::Init(window);
	sf::Clock deltaClock;
	g_manager.camera.moveCam(1, 0, 0);
	window.setView(*g_manager.camera.getView());
	g_manager.camera.moveCam(-1, 0, 0);
	while (window.isOpen())
	{
		window.setView(*g_manager.camera.getView());
		while (window.pollEvent(even))
		{
			ImGui::SFML::ProcessEvent(even);
			ImGuiIO& io = ImGui::GetIO();
			if (io.WantCaptureMouse)
			{

			}
			else
			{
				// "close requested" event: we close the window
				if (even.type == sf::Event::Closed)
				{
					window.close();
				}
				if (even.type== sf::Event::KeyPressed)
				{
					sfmlInput(even);
				}
			}
			
		}
		if (g_manager.focusPlanet)
		{
			if (g_manager.NODE!=nullptr)
			{
				g_manager.camera.setPosition(g_manager.NODE->position);
			}
		}
		ImGui::SFML::Update(window, deltaClock.restart());
		imguiWind();
		window.clear(sf::Color(0, 0, 0));
		g_manager.onUpdate();
		g_manager.onRender(window);
		ImGui::SFML::Render(window);
		window.display();
	}
	return 0;
}
void imguiWind()
{
	ImGui::Begin("Universe");
	if (ImGui::Button("EXIT"))
	{
		exit(1);
	}
	ImGui::SliderFloat("CAMERA SPEED", g_manager.cameraSpeed, 1,100);

	ImGui::SliderFloat("SPEED WORLD", g_manager.SpeedWord, 0,5);
	*g_manager.realSpeedWord = (*g_manager.SpeedWord) / 1000;
	//ImGui::InputDouble("SPEED WORLD", g_manager.SpeedWord);
	ImGui::InputText("name", g_manager.namePlan,255);
	if (ImGui::Button("Search Planet"))
	{
		int i = 0;
		while (g_manager.namePlan[i]!='\0')
		{
			if (g_manager.namePlan[i]>='a'&&g_manager.namePlan[i] <= 'z')
			{
				g_manager.namePlan[i] -= 32;
			}
			i++;
		}
		g_manager.nameToNAME = (g_manager.namePlan);
		g_manager.initSearch(g_manager.nameToNAME);
	}
	ImGui::Text(g_manager.nameToNAME.c_str());
	if (g_manager.focusPlanet)
	{
		if (ImGui::Button("off Focus"))
		{
			g_manager.focusPlanet = false;
		}
	}
	else
	{
		if (ImGui::Button("on Focus"))
		{
			g_manager.focusPlanet = true;
		}
	}
	ImGui::End();
}
void sfmlInput(const sf::Event &event)
{
	
	if (event.key.code == sf::Keyboard::Escape)
		exit(1);
	if (event.key.code == sf::Keyboard::D)
		g_manager.camera.moveCam(*g_manager.cameraSpeed, 0, 0);
	if (event.key.code == sf::Keyboard::A)
		g_manager.camera.moveCam(-*g_manager.cameraSpeed, 0, 0);
	if (event.key.code == sf::Keyboard::S)
		g_manager.camera.moveCam(0, *g_manager.cameraSpeed, 0);
	if (event.key.code == sf::Keyboard::W)
		g_manager.camera.moveCam(0, -*g_manager.cameraSpeed, 0);
	if (event.key.code == sf::Keyboard::E)
		g_manager.camera.decrementZoom();
	if (event.key.code == sf::Keyboard::Q)
		g_manager.camera.incrementZoom();

}