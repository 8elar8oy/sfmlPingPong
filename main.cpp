#include "settings.h"
#include "functions.h"
#include "game.h"
using namespace sf;

int main()
{
	srand(time(nullptr));
	// Объект, который, собственно, является главным окном приложения
	/*RenderWindow window(VideoMode(length, width), "SFML Works!");
	*/
	Game game;
	game.window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),"SFML Works!");
	game.window.setFramerateLimit(60);
	//шарик
	CircleShape ball;
	initBall(ball, ballStartPos);
	float arr_speed[]{ -5.f,5.f };
	int index = rand() % 2;
	float ball_speedx = arr_speed[index];
	index = rand() % 2;
	float ball_speedy = arr_speed[index];
	//ракетки
	RectangleShape leftbat, rightbat;
	{
		initBat(game.leftbat, batcolor1, leftBatStartPos);
		initBat(game.rightbat, batcolor2, rightBatStartPos);
	}
	float leftBаtSpeedY = 0.f;
	float rightBаtSpeedY = 0.f;
	//счет
	int LeftPlayerScore = 0;
	int RightPlayerScore = 0;
	Font font;
	font.loadFromFile("ds-digib.ttf");
	Text LeftPlayerScoreText, RightPlayerScoreText;
	{
		initText(LeftPlayerScoreText,LeftPlayerScore,font,charSize,leftScorePos);
		initText(RightPlayerScoreText, RightPlayerScore, font, charSize, rightScorePos);
	}
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (game.window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (game.window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				game.window.close();
		}
		//проверка нажатий клавиш
		ControlBat(leftBаtSpeedY, leftbat, Keyboard::W, Keyboard::S,leftbatPosYDownBorder, leftbatPosXDownBorder);
		ControlBat(rightBаtSpeedY, rightbat, Keyboard::Up, Keyboard::Down,rightbatPosYDownBorder, rightbatPosXDownBorder);
		// движение шарика
		ball.move(ball_speedx, ball_speedy);
		if (ball.getPosition().x <= 0) 
			ballReboundX(ball_speedx, RightPlayerScore, RightPlayerScoreText);
		if (ball.getPosition().x >= (WINDOW_WIDTH - 2 * ballradius)) 
			ballReboundX(ball_speedx, LeftPlayerScore, LeftPlayerScoreText);
		if (ball.getPosition().y <= 0 || ball.getPosition().y >= (WINDOW_HEIGHT - 2 * ballradius))
			ball_speedy = -ball_speedy;
		float midLeftX = ball.getPosition().x;
		float midLeftY = ball.getPosition().y + ballradius;
		float midRightX = ball.getPosition().x + 2 * ballradius;
		float midRightY = ball.getPosition().y + ballradius;
		float midUpX = ball.getPosition().x + ballradius;
		float midUpY = ball.getPosition().y;
		float midDownX = ball.getPosition().x + ballradius;
		float midDownY = ball.getPosition().y + 2 * ballradius;
		//левая ракетка
		if ((leftbat.getPosition().x <= midLeftX) && (midLeftX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y <= midLeftY) && (midLeftY <= leftbat.getPosition().y + width_bat))
		{
			ball_speedx = -ball_speedx;
		}
		if ((leftbat.getPosition().x <= midRightX) && (midRightX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y <= midRightY) && (midRightY <= leftbat.getPosition().y + width_bat))
		{
			ball_speedx = -ball_speedx;
		}
		if ((leftbat.getPosition().x <= midUpX) && (midUpX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y <= midUpY) && (midUpY <= leftbat.getPosition().y + width_bat))
		{
			if (ball_speedy < 0) {
				ball_speedy = -ball_speedy;
			}
		}
		if ((leftbat.getPosition().x <= midDownX) && (midDownX <= (leftbat.getPosition().x + length_bat)) && (leftbat.getPosition().y >= midDownY) && (midDownY > leftbat.getPosition().y - 1))
		{
			if (ball_speedy > 0) {
				ball_speedy = -ball_speedy;
			}
		}
		//правая ракетка
		if ((rightbat.getPosition().x <= midLeftX) && (midLeftX <= (rightbat.getPosition().x + length_bat)) && (rightbat.getPosition().y <= midLeftY) && (midLeftY <= rightbat.getPosition().y + width_bat))
		{
			ball_speedx = -ball_speedx;

		}
		if ((rightbat.getPosition().x <= midRightX) && (midRightX <= (rightbat.getPosition().x + length_bat)) && (rightbat.getPosition().y <= midRightY) && (midRightY <= rightbat.getPosition().y + width_bat))
		{
			ball_speedx = -ball_speedx;
		}
		if ((rightbat.getPosition().x <= midUpX) && (midUpX <= (rightbat.getPosition().x + length_bat)) && (rightbat.getPosition().y <= midUpY) && (midUpY <= rightbat.getPosition().y + width_bat))
		{
			if (ball_speedy < 0) {
				ball_speedy = -ball_speedy;
			}
		}
		if ((rightbat.getPosition().x <= midDownX) && (midDownX <= (rightbat.getPosition().x + length_bat)) && (rightbat.getPosition().y <= midDownY) && (midDownY <= rightbat.getPosition().y + width_bat))
		{
			if (ball_speedy > 0) {
				ball_speedy = -ball_speedy;
			}
		}
		//отрисовка обьектов

		windowUpdate(game.window, ball,rightbat,RightPlayerScoreText,leftbat, LeftPlayerScoreText);
	}
	return 0;
}