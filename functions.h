#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include "game.h"
void initBat(Bat& bat, const sf::Color batColor, const sf::Vector2f batPosition) 
{
	bat.batShape.setSize(batsize);
	bat.batShape.setFillColor(batColor);
	bat.batShape.setPosition(batPosition);
	bat.BàtSpeedY
}
void initBall(sf::CircleShape& ball, const sf::Vector2f ballPosition)
{
	ball.setRadius(ballradius);
	ball.setFillColor(Color::White);
	ball.setPosition(ballPosition);
}

void initText(sf::Text& scoreText, int score, sf::Font& font, const int charSize, const sf::Vector2f textStartPos) {
	scoreText.setString(std::to_string(score));
	scoreText.setFont(font);
	scoreText.setCharacterSize(charSize);
	scoreText.setPosition(textStartPos);
}
void ballReboundX(float& ballSpeed,int& playerScore,sf::Text& scoreText) {
	ballSpeed = -ballSpeed;
	playerScore++;
	scoreText.setString(std::to_string(playerScore));
}
void ControlBat(float& batspeed,sf::RectangleShape& bat, sf::Keyboard::Key up_key, sf::Keyboard::Key down_key,const float PosYDownBorder, const float PosXDownBorder) {
	if (Keyboard::isKeyPressed(up_key)){
		batspeed = -BAT_SPEED;
		if (bat.getPosition().y <= 0) bat.setPosition(PosXDownBorder, 0);
	}
	if (Keyboard::isKeyPressed(down_key))
	{
		batspeed = BAT_SPEED;
		if (bat.getPosition().y >= (WINDOW_HEIGHT - 80)) bat.setPosition(PosXDownBorder, PosYDownBorder);
	}
	bat.move(0, batspeed);
	batspeed = 0.f;
}
//void ballmove()
//if ((leftbat.getPosition().x <= midLeftX) && (midLeftX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y <= midLeftY) && (midLeftY <= leftbat.getPosition().y + width_bat))
//{
//	ball_speedx = -ball_speedx;
//}
//if ((leftbat.getPosition().x <= midRightX) && (midRightX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y <= midRightY) && (midRightY <= leftbat.getPosition().y + width_bat))
//{
//	ball_speedx = -ball_speedx;
//}
//if ((leftbat.getPosition().x <= midUpX) && (midUpX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y <= midUpY) && (midUpY <= leftbat.getPosition().y + width_bat))
//{
//	if (ball_speedy < 0) {
//		ball_speedy = -ball_speedy;
//	}
//}
//if ((leftbat.getPosition().x <= midDownX) && (midDownX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y >= midDownY) && (midDownY > leftbat.getPosition().y - 1))
//{
//	if (ball_speedy > 0) {
//		ball_speedy = -ball_speedy;
//	}
//}
void windowUpdate(sf::RenderWindow& window,const sf::CircleShape& ball,const sf::RectangleShape& rightbat,const sf::Text& rightscoreText,const sf::RectangleShape& leftbat, const sf::Text& leftscoreText) {
	window.clear(Color::Black);
	window.draw(ball);
	window.draw(rightbat);
	window.draw(rightscoreText);
	window.draw(leftbat);
	window.draw(leftscoreText);
	window.display();
}
