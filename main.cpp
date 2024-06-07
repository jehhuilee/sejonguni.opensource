#include "basic.h"
#include "Bishop.h"
#include "knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "king.h"
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

	Sprite ChessBoard(t1);
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
					if (PromotionWhite == 1)
					{
						if (pos.y >= transformW.y * size && pos.y <= (transformW.y + 1) * size && pos.x >= transformW.x * size && pos.x <= (transformW.x + 1) * size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								board[transformW.y][transformW.x] = RookW;
								PromotionWhite = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								board[transformW.y][transformW.x] = QueenW;
								PromotionWhite = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								board[transformW.y][transformW.x] = KnightW;
								PromotionWhite = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								board[transformW.y][transformW.x] = BishopW;
								PromotionWhite = 0;
							}
							if (PromotionWhite == 0)
							{
								pozKingB();
								int h = KingBlackCheck(KingBlackPoz.x, KingBlackPoz.y);
								if (h == 0)
								{
									KingB_Check = 1;
								}
							}
						}
					}
					if (PromotionBlack == 1)
					{
						if (pos.y >= transformB.y * size && pos.y <= (transformB.y + 1) * size && pos.x >= transformB.x * size && pos.x <= (transformB.x + 1) * size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								board[transformB.y][transformB.x] = RookB;
								PromotionBlack = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								board[transformB.y][transformB.x] = QueenB;
								PromotionBlack = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								board[transformB.y][transformB.x] = KnightB;
								PromotionBlack = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								board[transformB.y][transformB.x] = BishopB;
								PromotionBlack = 0;
							}
							if (PromotionBlack == 0)
							{
								pozKingW();
								int h = KingWhiteCheck(KingWhitePoz.x, KingWhitePoz.y);
								if (h == 0)
								{
									KingW_Check = 1;
								}
							}
						}
					}
					if (board[y][x] != 0)
					{
						dx = pos.x - x * 100;
						dy = pos.y - y * 100;
						if (board[y][x] == PawnB && Who_turn == 1)
						{
							Movingpiece = PawnB;
							who_turn = Pawnb;
							board[y][x] = 0;
						}
						if (board[y][x] == PawnW && Who_turn == 0)
						{
							Movingpiece = PawnW;
							who_turn = Pawnw;
							board[y][x] = 0;
						}
						if (board[y][x] == RookB && Who_turn == 1)
						{
							Movingpiece = RookB;
							who_turn = Rookb;
							board[y][x] = 0;

						}
						if (board[y][x] == RookW && Who_turn == 0)
						{
							Movingpiece = RookW;
							who_turn = Rookw;
							board[y][x] = 0;

						}
						if (board[y][x] == KnightW && Who_turn == 0)
						{
							Movingpiece = KnightW;
							who_turn = Knightw;
							board[y][x] = 0;
						}
						if (board[y][x] == KnightB && Who_turn == 1)
						{
							Movingpiece = KnightB;
							who_turn = Knightb;
							board[y][x] = 0;
						}
						if (board[y][x] == BishopB && Who_turn == 1)
						{
							Movingpiece = BishopB;
							who_turn = Bishopb;
							board[y][x] = 0;
						}
						if (board[y][x] == BishopW && Who_turn == 0)
						{
							Movingpiece = BishopW;
							who_turn = Bishopw;
							board[y][x] = 0;
						}
						if (board[y][x] == QueenW && Who_turn == 0)
						{
							Movingpiece = QueenW;
							who_turn = Queenw;
							board[y][x] = 0;
						}
						if (board[y][x] == QueenB && Who_turn == 1)
						{
							Movingpiece = QueenB;
							who_turn = Queenb;
							board[y][x] = 0;
						}
						if (board[y][x] == KingB && Who_turn == 1)
						{
							Movingpiece = KingB;
							who_turn = Kingb;
							board[y][x] = 0;
						}
						if (board[y][x] == KingW && Who_turn == 0)
						{
							Movingpiece = KingW;
							who_turn = Kingw;
							board[y][x] = 0;
						}
						if (board[y][x] == 0)
						{
							move = 1;
							oldPoz.x = x;
							oldPoz.y = y;
						}
					}
				}
			}
			if (e.type == Event::MouseButtonReleased)
			{
				if (e.key.code == Mouse::Left)
				{
					int ok = 2;
					if (Movingpiece == PawnW && move == 1)
					{
						ok = PawnWhite(oldPoz.x, oldPoz.y, x, y);
					}
					if (Movingpiece == PawnB && move == 1)
					{
						ok = PawnBlack(oldPoz.x, oldPoz.y, x, y);
					}
					if (Movingpiece == RookW && move == 1)
					{
						ok = RookWhite(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && RookW_Left == 0 && oldPoz.y == 7 && oldPoz.x == 0)
						{
							RookW_Left = 1;
						}
						if (ok == 1 && RookW_Right == 0 && oldPoz.y == 7 && oldPoz.x == 7)
						{
							RookW_Right = 1;
						}
					}
					if (Movingpiece == RookB && move == 1)
					{
						ok = RookBlack(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && RookB_Right == 0 && oldPoz.y == 0 && oldPoz.x == 7)
						{
							RookB_Right = 1;
						}
						if (ok == 1 && RookB_Left == 0 && oldPoz.y == 0 && oldPoz.x == 0)
						{
							RookB_Left = 1;
						}
					}
					if (Movingpiece == BishopW && move == 1)
					{
						ok = BishopWhite(oldPoz.x, oldPoz.y, x, y);
					}
					if (Movingpiece == BishopB && move == 1)
					{
						ok = BishopBlack(oldPoz.x, oldPoz.y, x, y);
					}
					if (Movingpiece == QueenW && move == 1)
					{
						ok = QueenWhite(oldPoz.x, oldPoz.y, x, y);
					}
					if (Movingpiece == QueenB && move == 1)
					{
						ok = QueenBlack(oldPoz.x, oldPoz.y, x, y);
					}
					if (Movingpiece == KnightW && move == 1)
					{
						ok = KnightWhite(oldPoz.x, oldPoz.y, x, y);
					}
					if (Movingpiece == KnightB && move == 1)
					{
						ok = KnightBlack(oldPoz.x, oldPoz.y, x, y);
					}
					if (Movingpiece == KingB && move == 1)
					{
						ok = KingBlackMove(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && King_B == 0)
						{
							King_B = 1;
							//	std::cout << King_B << "\n";
						}
					}
					if (Movingpiece == KingW && move == 1)
					{
						ok = KingWhiteMove(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && King_W == 0)
						{
							King_W = 1;
							//std::cout << "primaMutareREGEalb=" << King_W << "\n";
						}
					}
					if (ok == 1)
					{
						int nr = board[y][x];
						board[y][x] = Movingpiece;
						if (y == 0 && Movingpiece == PawnW)
						{
							PromotionWhite = 1;
							transformW.x = x;
							transformW.y = y;
							board[y][x] = 0;
						}
						if (y == 7 && Movingpiece == PawnB)
						{
							PromotionBlack = 1;
							transformB.x = x;
							transformB.y = y;
							board[y][x] = 0;
						}
						if (Who_turn == 0)
						{
							if (KingW_Check == 1)
							{
								pozKingW();
								int s = KingWhiteCheck(KingWhitePoz.x, KingWhitePoz.y);
								if (s == 0)
								{
									board[oldPoz.y][oldPoz.x] = Movingpiece;
									board[y][x] = nr;
								}
								else
								{
									KingW_Check = 0;
									pozKingB();
									int sah = KingBlackCheck(KingBlackPoz.x, KingBlackPoz.y);
									if (sah == 0)
									{
										KingB_Check = 1;
									}
									Who_turn = 1;
								}
							}
							else
							{
								pozKingW();
								int sa = KingWhiteCheck(KingWhitePoz.x, KingWhitePoz.y);
								if (sa == 0)
								{
									board[oldPoz.y][oldPoz.x] = Movingpiece;
									board[y][x] = nr;
								}
								else
								{
									pozKingB();
									int sah = KingBlackCheck(KingBlackPoz.x, KingBlackPoz.y);
									if (sah == 0)
									{
										KingB_Check = 1;
									}
									Who_turn = 1;
								}
							}
						}
						else
						{
							if (KingB_Check == 1)
							{
								pozKingB();
								int s = KingBlackCheck(KingBlackPoz.x, KingBlackPoz.y);
								if (s == 0)
								{
									board[oldPoz.y][oldPoz.x] = Movingpiece;
									board[y][x] = nr;
								}
								else
								{
									KingB_Check = 0;
									pozKingW();
									int sah = KingWhiteCheck(KingWhitePoz.x, KingWhitePoz.y);
									if (sah == 0)
									{
										KingW_Check = 1;
									}
									Who_turn = 0;
								}
							}
							else
							{
								pozKingB();
								int sa = KingBlackCheck(KingBlackPoz.x, KingBlackPoz.y);
								if (sa == 0)
								{
									board[oldPoz.y][oldPoz.x] = Movingpiece;
									board[y][x] = nr;
								}
								else
								{
									pozKingW();
									int sah = KingWhiteCheck(KingWhitePoz.x, KingWhitePoz.y);
									if (sah == 0)
									{
										KingW_Check = 1;
									}
									Who_turn = 0;
								}
							}
						}
					}
					else if (ok == 0)
					{
						board[oldPoz.y][oldPoz.x] = Movingpiece;
					}
					move = 0;
				}
			}
		}

		window.clear();
		window.draw(ChessBoard);
		if (PromotionWhite == 1)
		{
			Promotionwhite.setPosition(transformW.x * size, transformW.y * size);
			window.draw(Promotionwhite);
		}
		if (PromotionBlack == 1)
		{
			Promotionblack.setPosition(transformB.x * size, transformB.y * size);
			window.draw(Promotionblack);
		}
		if (move == 1)
		{
			who_turn.setPosition(pos.x - dx, pos.y - dy);
			window.draw(who_turn);
		}
		for (int i = 0; i < BOARDLEN; i++)
		{
			for (int j = 0; j < BOARDLEN; j++)
			{

				if (board[i][j] != 0)
				{
					if (board[i][j] == PawnB)
					{
						Pawnb.setPosition(j * size, i * size);
						window.draw(Pawnb);
					}
					if (board[i][j] == PawnW)
					{
						Pawnw.setPosition(j * size, i * size);
						window.draw(Pawnw);
					}
					if (board[i][j] == RookB)
					{
						Rookb.setPosition(j * size, i * size);
						window.draw(Rookb);

					}
					if (board[i][j] == RookW)
					{
						Rookw.setPosition(j * size, i * size);
						window.draw(Rookw);

					}
					if (board[i][j] == KnightW)
					{
						Knightw.setPosition(j * size, i * size);
						window.draw(Knightw);
					}
					if (board[i][j] == KnightB)
					{
						Knightb.setPosition(j * size, i * size);
						window.draw(Knightb);
					}
					if (board[i][j] == BishopB)
					{
						Bishopb.setPosition(j * size, i * size);
						window.draw(Bishopb);
					}
					if (board[i][j] == BishopW)
					{
						Bishopw.setPosition(j * size, i * size);
						window.draw(Bishopw);
					}
					if (board[i][j] == QueenW)
					{
						Queenw.setPosition(j * size, i * size);
						window.draw(Queenw);
					}
					if (board[i][j] == QueenB)
					{
						Queenb.setPosition(j * size, i * size);
						window.draw(Queenb);
					}
					if (board[i][j] == KingB)
					{
						Kingb.setPosition(j * size, i * size);
						window.draw(Kingb);
					}
					if (board[i][j] == KingW)
					{
						Kingw.setPosition(j * size, i * size);
						window.draw(Kingw);
					}
				}
			}
		}
		window.display();
	}
	return 0;
}