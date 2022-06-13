#pragma once
#include "pch.h"
#include <thread>
#include "GameObjects.h"
class gamewindow
{
public:
	gamewindow(int,int,const char*);
	~gamewindow();
	//Gamewindowstuff:
	sf::RenderWindow *_window;
	sf::Event* _wevent;
	sf::VideoMode* _wvideomode;
	sf::Image* _gameicon;
	GameObjects *_gameobjs;

	void RenderGraphics();
	void ProcessObjects();
	void ExecEvents();
	void chfullscreen();
	void remfullscreen();
	void changeiatcen();

private:
	//Loadscreen stuff:
	bool gwfl=false;
	bool isfullscreen = true;
	bool iatcen = false;
	sf::RenderWindow* _lwo;
	sf::VideoMode* _lwvm;
	sf::Texture* _lwim;
	sf::Sprite* _lwimenty;
	sf::Text* _fpstext;
	const char* _wtx;
	//fps objs:
	sf::Clock clock = sf::Clock::Clock();
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;
	sf::Clock lstime = sf::Clock::Clock();
};