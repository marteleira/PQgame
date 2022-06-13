#include "gamewindow.h"

gamewindow::gamewindow(int w, int h, const char* _wtext)
{
	//
	// Load Process:
	//

	//Hide ConsoleWindow: (only works on windows)
	HWND CWND = GetConsoleWindow();
	ShowWindow(CWND,HIDE_WINDOW);
	
	//load icon
	_gameicon = new sf::Image();
	_gameicon->loadFromFile("Resources/pqicon.png");

	//init loadscreen:
	_lwim = new sf::Texture();
	_lwvm = new sf::VideoMode(412,250);
	_lwo = new sf::RenderWindow(
	*_lwvm
	,_wtext
	,sf::Style::None
	);
	this->_wtx = _wtext;
	//set process icon:
	_lwo->setIcon(50, 50, _gameicon->getPixelsPtr());

	//Hide on Taskbar: (only works on windows)
	SetWindowLongPtr(_lwo->getSystemHandle(), GWL_EXSTYLE,
		GetWindowLongPtr(_lwo->getSystemHandle(), GWL_EXSTYLE)
		| WS_EX_TOOLWINDOW);

	//Load and display Image/loadscreen:
	_lwim->loadFromFile("Resources/splashlogo.png");
	_lwimenty = new sf::Sprite(*_lwim);
	_lwo->draw(*_lwimenty);
	_lwo->display();

	//delay:
	std::this_thread::sleep_for(std::chrono::seconds(2));
	

	//
	// Runtime_Window:
	//
	
	//set window settings:
	_wevent = new sf::Event();
	_wvideomode = new sf::VideoMode(w,h);
	//init window:
	_window = new sf::RenderWindow(
	*_wvideomode
	,_wtext
	,sf::Style::Fullscreen
	);
	//set window icon:
	_window->setIcon(50,50,_gameicon->getPixelsPtr());
	_window->setPosition(sf::Vector2i(0,0));
	_gameobjs = new GameObjects(w,h);
	_fpstext = new sf::Text("fps:0", _gameobjs->gamefont);
	_fpstext->setPosition(w/2-50,h-50);
	_fpstext->setFillColor(sf::Color::Black);
	_fpstext->setStyle(sf::Text::Style::Bold);
	_window->setFramerateLimit(60);
}

void gamewindow::changeiatcen()
{
	if (this->iatcen == true) iatcen = false;
	else this->iatcen = true;
}

void gamewindow::remfullscreen()
{
	delete _window;
	_window = new sf::RenderWindow(
		*_wvideomode
		, _wtx
		, sf::Style::Default
	);
	//set window icon:
	_window->setIcon(50, 50, _gameicon->getPixelsPtr());
	_window->setPosition(sf::Vector2i(0,0));

	_window->setFramerateLimit(60);
}

void gamewindow::chfullscreen()
{
	delete _window;
	_window = new sf::RenderWindow(
		*_wvideomode
		, _wtx
		, sf::Style::Fullscreen
	);
	//set window icon:
	_window->setIcon(50, 50, _gameicon->getPixelsPtr());

	_window->setFramerateLimit(60);
}

void gamewindow::ExecEvents()
{
	while (_window->pollEvent(*_wevent))
	{
		if (_wevent->type == sf::Event::Closed)
		{
			_window->close();
		}
		//Other events:
		if (_wevent->type == sf::Event::KeyReleased)
		{
			if (_wevent->key.code == sf::Keyboard::Q||_wevent->key.code == sf::Keyboard::Key::W || _wevent->key.code == sf::Keyboard::Key::A || _wevent->key.code == sf::Keyboard::Key::S)
			{
				_gameobjs->KeyDown_Q();
			}

			if (_wevent->key.code == sf::Keyboard::P|| _wevent->key.code == sf::Keyboard::O|| _wevent->key.code == sf::Keyboard::L|| _wevent->key.code == sf::Keyboard::K)
			{
				_gameobjs->KeyDown_P();
			}

			if (_wevent->key.code == sf::Keyboard::B)
			{
				this->changeiatcen();
			}

			if (_wevent->key.code == sf::Keyboard::F11)
			{
				_window->close();
				if (isfullscreen)
				{
					this->remfullscreen();
					isfullscreen = false;
				}
				else { 
					this->chfullscreen(); 
					isfullscreen = true;
				}
			}
		}
	}
	//Extern Events:
}

void gamewindow::ProcessObjects()
{
	//Processed Ai events:
	_gameobjs->getcps();
	currentTime = clock.getElapsedTime();

	if ((int)clock.getElapsedTime().asMilliseconds() % 50==0) 
	 _fpstext->setString("Fps:" + std::to_string((int)(1.0f / (currentTime.asSeconds() - previousTime.asSeconds()))));
	previousTime = currentTime;
	if (iatcen==true)
	{
		//auto c = std::chrono::duration_cast<std::chrono::milliseconds>(lstime - std::chrono::high_resolution_clock::now());
		if (this->lstime.getElapsedTime().asMilliseconds()>=0x4E)
		{
			this->lstime.restart();
			this->_gameobjs->KeyDown_Q();
		}
		//delete &c;
	}
}

void gamewindow::RenderGraphics()
{
	//clear the window:
	_window->clear(sf::Color::White);
	//render objects:
	_window->draw(*_gameobjs->_bbar);
	_window->draw(*_gameobjs->_bcircle);
	_window->draw(*_gameobjs->_bcpstext);
	_window->draw(*_gameobjs->_rbar);
	_window->draw(*_gameobjs->_rcircle);
	_window->draw(*_gameobjs->_rcpstext);
	_window->draw(*_gameobjs->_rtext);
	_window->draw(*_gameobjs->_btext);
	_window->draw(*_fpstext);
	//display the window
	_window->display();
	
	if (gwfl == false)
	{
		_lwo->close();
		gwfl != gwfl;
	}
}

gamewindow::~gamewindow()
{
	delete _window;
	delete _wevent;
	delete _wvideomode;
	delete _gameicon;
	delete _lwim;
	delete _lwimenty;
	delete _lwo;
	delete _lwvm;
	delete _gameobjs;
	delete _fpstext;
	delete& gwfl;
	delete& clock;
	delete& currentTime;
	delete& previousTime;
}