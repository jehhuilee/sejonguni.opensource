#include "basic.h"
#include "Bishop.h"
#include "knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
using namespace sf;

int main()
{

	RenderWindow window(VideoMode(800, 800), "Open Source assignment Chess game");
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;

	t1.loadFromFile("images/board.png");
	t2.loadFromFile("images/Pawnb.png");
	t3.loadFromFile("images/Pawnw.png");
	t4.loadFromFile("images/Rookb.png");
	t5.loadFromFile("images/Rookw.png");
	t6.loadFromFile("images/Knightw.png");
	t7.loadFromFile("images/Knightb.png");
	t8.loadFromFile("images/Bishopb.png");
	t9.loadFromFile("images/Bishopw.png");
	t10.loadFromFile("images/Queenw.png");
	t11.loadFromFile("images/Queenb.png");
	t12.loadFromFile("images/Kingb.png");
	t13.loadFromFile("images/Kingw.png");
	t14.loadFromFile("images/Promotionwhite.png");
	t15.loadFromFile("images/Promotionblack.png");

	Sprite tabla(t1);
	Sprite Pawnb(t2);
	Sprite Pawnw(t3);
	Sprite Rookb(t4);
	Sprite Rookw(t5);
	Sprite Knightw(t6);
	Sprite Knightb(t7);
	Sprite Bishopb(t8);
	Sprite Bishopw(t9);
	Sprite Queenw(t10);
	Sprite Queenb(t11);
	Sprite Kingb(t12);
	Sprite Kingw(t13);
	Sprite who_turn;
	Sprite Promotionwhite(t14);
	Sprite Promotionblack(t15);

	float dx = 0, dy = 0;
	int Movingpiece = 0;

	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window);
		x = pos.x / size;
		y = pos.y / size;
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			window.clear();
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.key.code == Mouse::Left)
				{
					std::cout << "click press check" << "\n"; 
				}
			}
			if (e.type == Event::MouseButtonReleased)
			{
				if (e.key.code == Mouse::Left)
				{
					std::cout << "click release check" << "\n";

				}
			}
		}

	

		window.display();
	}
	return 0;
}