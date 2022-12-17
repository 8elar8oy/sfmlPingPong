#pragma once
#include "SFML/Graphics.hpp"
struct Bat {
	sf::RectangleShape bat;
	float BàtSpeedY;
};
struct Ball {
	sf::CircleShape ball;
	float ball_speedx ;
	
	float ball_speedy ;

};
struct Game
{
	sf::RenderWindow window;
	Bat leftbat, rightbat;
	Ball ball;
	sf::Text LeftPlayerScoreText, RightPlayerScoreText;
	sf::Font font;
};