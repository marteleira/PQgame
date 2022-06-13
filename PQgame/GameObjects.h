#pragma once
#include "pch.h"
class GameObjects
{
public:
	GameObjects(int, int);
	~GameObjects();
	sf::CircleShape* _bcircle, *_rcircle;
	sf::Text* _bcpstext, * _rcpstext, * _btext, * _rtext;
	sf::Font gamefont;
	sf::RectangleShape* _rbar, * _bbar;
	sf::Vector2f* _perfbarsize;
	void getcps();
	void KeyDown_P();
	void KeyDown_Q();
private:
	 int MOVSPEDD = 2;
	sf::Clock gameclok = sf::Clock::Clock();
	int* _windx, * _windy;
	int rclickcount=0;
	int bclickcount=0;
};

