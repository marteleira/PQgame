#pragma once
#include "pch.h"
#include "gamewindow.h"
/*
float btnx=0, btny=0, btnlimitx=0, btnlimity=0;
sf::Vector2i *crpos=(sf::Vector2i*) malloc(sizeof(sf::Vector2i));

bool ismouseouver(sf::RectangleShape btn)
{
	btnx = btn.getPosition().x;
	btny = btn.getPosition().y;
	btnlimitx = btn.getPosition().x + btn.getSize().x;
	btnlimity = btn.getPosition().y + btn.getSize().y;
	*crpos = sf::Mouse::getPosition();
	bool state=false;
	if(btnx<=crpos->x && crpos->x<=btnlimitx && btny <= crpos->y && crpos->y <= btnlimity)
		state = true;
	return state;
}
*/
int main(int argc, char* argv[])
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop); //Adaptive Size
	/*
	sf::RenderWindow* _mainwindow;
	sf::Event *_mwevent=new sf::Event();
	sf::VideoMode* _mwvm;
	sf::RectangleShape* _bgimgshape;
	sf::RectangleShape* _btnclose;
	sf::Texture* _bgimage;
	sf::Texture* _btncloseimage;
	sf::Image appicon;

	appicon.loadFromFile("\\Resources\\pqicon.png");
	_mwvm = new sf::VideoMode(854,480);
	_mainwindow = new sf::RenderWindow(
		*_mwvm
		,"QP_GAME-Menu"
		,sf::Style::Default
	);

	_bgimgshape = new sf::RectangleShape(sf::Vector2f(854, 480));
	_btnclose = new sf::RectangleShape(sf::Vector2f(40,40));
	_bgimage = new sf::Texture();
	_btncloseimage = new sf::Texture();
	//_bgimage->loadFromFile("");
	//_btncloseimage->loadFromFile("");
	
	while (_mainwindow->isOpen())
	{
		while (_mainwindow->pollEvent(*_mwevent))
		{
			if (_mwevent->type == sf::Event::Closed)
			{
				_mainwindow->close();
			}

			if (_mwevent->type == sf::Event::MouseButtonReleased)
			if (_mwevent->mouseButton.button==sf::Mouse::Left)
			{
				if (ismouseouver(*_btnclose))
				{
					_mainwindow->close();
				}
			}
		}
		_mainwindow->clear();
		_mainwindow->draw(*_btnclose);
		_mainwindow->display();
	}
	*/
	gamewindow *_game = new gamewindow(desktop.right,desktop.bottom,"Jogo Divertido");
	while (_game->_window->isOpen())
	{
		_game->ExecEvents();
		_game->ProcessObjects();
		_game->RenderGraphics();
	}
	return 0x0;
}