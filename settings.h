#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const float length_bat = 20;
const float width_bat = 80;
const float ballradius = 10;
const float otstup = 50;
const float ball_posx = WINDOW_WIDTH / 2 - 10;
const float ball_posy = WINDOW_HEIGHT / 2 - 10;
const Color batcolor1(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
const Color batcolor2(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
const Vector2f batsize(length_bat, width_bat);
const float BAT_SPEED = 5.f;
const float LeftScore_posx = 88.f;
const float LeftScore_posy = 50.f;
const float RightScore_posx = 680.f;
const float RightScore_posy = 50.f;
const Vector2f leftBatStartPos{ otstup, WINDOW_HEIGHT / 2 - 40 };
const Vector2f rightBatStartPos{ WINDOW_WIDTH - otstup - 20, WINDOW_HEIGHT / 2 - 40 };
const Vector2f ballStartPos{ ball_posx,ball_posy };
const Vector2f rightScorePos{ RightScore_posx, RightScore_posy };
const Vector2f leftScorePos{ LeftScore_posx, LeftScore_posy };
const int charSize = 64;
const float leftbatPosYDownBorder = WINDOW_HEIGHT - 80;
const float leftbatPosXDownBorder = otstup;
const float rightbatPosYDownBorder = WINDOW_HEIGHT - 80;
const float rightbatPosXDownBorder = WINDOW_WIDTH-otstup-20;
