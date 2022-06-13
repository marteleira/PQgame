#include "GameObjects.h"

GameObjects::GameObjects(int windx, int windy)
{
	//Init WindowInfo vars:
	this->_windx = new int(windx);
	this->_windy = new int(windy);

	//Create Game Objects:
	_perfbarsize = new sf::Vector2f((*_windx / 5), (*_windx / 5) / 6);
	gamefont.loadFromFile("Resources/Arial.ttf");

	_rcircle = new sf::CircleShape((*_windx / 10));
	_bcircle = new sf::CircleShape((*_windx / 10));
	_bbar = new sf::RectangleShape(*_perfbarsize);
	_rbar = new sf::RectangleShape(*_perfbarsize);
	_rtext = new sf::Text("P", gamefont);
	_btext = new sf::Text("Q", gamefont);
	_rcpstext = new sf::Text("CPS:0", gamefont);
	_bcpstext = new sf::Text("CPS:0", gamefont);

	//set attributes:
	//(textstyle)
	_btext->setStyle(sf::Text::Bold);
	_rtext->setStyle(sf::Text::Bold);
	_rcpstext->setStyle(sf::Text::Bold);
	_bcpstext->setStyle(sf::Text::Bold);

	//(textsize)
	_btext->setCharacterSize(_bcircle->getRadius());
	_rtext->setCharacterSize(_rcircle->getRadius());
	_bcpstext->setCharacterSize(_bcircle->getRadius() / 2);
	_rcpstext->setCharacterSize(_rcircle->getRadius() / 2);

	//(color)
	_rbar->setFillColor(sf::Color(0xff, 0x0, 0x0, 0xff));
	_bbar->setFillColor(sf::Color(0x0, 0x0, 0xff, 0xff));
	_rcircle->setFillColor(sf::Color(0xff, 0x0, 0x0, 0xff));
	_bcircle->setFillColor(sf::Color(0x0, 0x0, 0xff, 0xff));
	_rtext->setFillColor(sf::Color::White);
	_btext->setFillColor(sf::Color::White);
	_rcpstext->setFillColor(sf::Color::Black);
	_bcpstext->setFillColor(sf::Color::Black);

	//(position)
	_bcpstext->setPosition(_bcircle->getRadius() / 2, _bcircle->getRadius() / 6);
	_rcpstext->setPosition(*_windx - _bcircle->getRadius() * 2, _bcircle->getRadius() / 6);
	_rbar->setPosition((*_windx / 2), (*_windy / 2) - _bbar->getSize().y);
	_bbar->setPosition((*_windx / 2) - _rbar->getSize().x, (*_windy / 2) - _rbar->getSize().y);
	_bcircle->setPosition(_bcircle->getRadius() / 2, (*_windy / 2) - _bcircle->getRadius());
	_rcircle->setPosition((*_windx - (_rcircle->getRadius() * 2.5)), (*_windy / 2) - _rcircle->getRadius());
	_btext->setPosition(_bcircle->getPosition().x + (_bcircle->getRadius() * 0.6), _bcircle->getPosition().y + (_bcircle->getRadius() * 0.45));
	_rtext->setPosition(_rcircle->getPosition().x + (_rcircle->getRadius() * 0.7), _rcircle->getPosition().y + (_rcircle->getRadius() * 0.45));
	
	MOVSPEDD = *_windx / 256;

	gameclok.restart();
}

void GameObjects::KeyDown_Q()
{
	if (_bbar->getSize().x <= _perfbarsize->x * 2 - 2)
	{
		_bbar->setSize(sf::Vector2f(_bbar->getSize().x + MOVSPEDD, _bbar->getSize().y));
		_rbar->move(this->MOVSPEDD, 0);
		_rbar->setSize(sf::Vector2f(_rbar->getSize().x - MOVSPEDD, _rbar->getSize().y));
		bclickcount++;
	}
	else
	{
		MessageBox(NULL, L"Parabens!\n O Azul Venceu!", L"Parabens!", MB_OK | MB_ICONINFORMATION);
		bclickcount = 0;
		rclickcount = 0;
		_bbar->setSize(sf::Vector2f((*_windx / 5), (*_windx / 5) / 6));
		_rbar->setSize(sf::Vector2f((*_windx / 5), (*_windx / 5) / 6));
		_rbar->setPosition((*_windx / 2), (*_windy / 2) - _bbar->getSize().y);
		_bbar->setPosition((*_windx / 2) - _rbar->getSize().x, (*_windy / 2) - _rbar->getSize().y);
		gameclok.restart();
	}
}

void GameObjects::KeyDown_P()
{
	if (_rbar->getSize().x <= _perfbarsize->x * 2 - 2)
	{
		_bbar->setSize(sf::Vector2f(_bbar->getSize().x - MOVSPEDD, _bbar->getSize().y));
		_rbar->move(-this->MOVSPEDD, 0);
		_rbar->setSize(sf::Vector2f(_rbar->getSize().x + MOVSPEDD, _rbar->getSize().y));
		rclickcount++;
	}
	else
	{
		MessageBox(NULL, L"Parabens!\n O Vermelho Venceu!", L"Parabens!", MB_OK | MB_ICONINFORMATION);
		bclickcount = 0;
		rclickcount = 0;
		_bbar->setSize(sf::Vector2f((*_windx / 5), (*_windx / 5) / 6));
		_rbar->setSize(sf::Vector2f((*_windx / 5), (*_windx / 5) / 6));
		_rbar->setPosition((*_windx / 2), (*_windy / 2) - _bbar->getSize().y);
		_bbar->setPosition((*_windx / 2) - _rbar->getSize().x, (*_windy / 2) - _rbar->getSize().y);
		gameclok.restart();
	}
}

void GameObjects::getcps()
{
	if (gameclok.getElapsedTime().asMilliseconds() / 500 >=1 )
	{
		_bcpstext->setString("CPS:" + std::to_string((int)(bclickcount / gameclok.getElapsedTime().asSeconds())));
		_rcpstext->setString("CPS:" + std::to_string((int)(rclickcount / gameclok.getElapsedTime().asSeconds())));
	}
	if (gameclok.getElapsedTime().asSeconds() >= 1)
	{
		gameclok.restart();
		bclickcount = 0;
		rclickcount = 0;
	}
}

GameObjects::~GameObjects()
{
	delete _bcircle;
	delete _rcircle;
	delete _bcpstext;
	delete _rcpstext;
	delete _btext;
	delete _rtext;
	delete _rbar;
	delete _bbar;
	delete _perfbarsize;
	delete _windx;
	delete _windy;
	delete& rclickcount;
	delete& bclickcount;
	delete& MOVSPEDD;
	delete& gameclok;
	delete& gamefont;
}
