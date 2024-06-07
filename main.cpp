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
    RenderWindow window(VideoMode(800, 800), "Open Source assignment Chess game"); /* 800*800 크기의 SFML창을 생성, 제목은 " "*/
    Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15; /* 텍스쳐 객체들을 선언. 텍스처는 그래픽 이미지를 메모리에 저장 */

    // 각 텍스처 객체에 이미지 파일을 로드. 'loadFromFIle()'함수는 파일 경로를 인수로 받아 텍스처를 초기화 
    t1.loadFromFile("images/board.png");
    t2.loadFromFile("images/PawnB.png");
    t3.loadFromFile("images/PawnW.png");
    t4.loadFromFile("images/RookB.png");
    t5.loadFromFile("images/RookW.png");
    t6.loadFromFile("images/KnightW.png");
    t7.loadFromFile("images/KnightB.png");
    t8.loadFromFile("images/BishopB.png");
    t9.loadFromFile("images/BishopW.png");
    t10.loadFromFile("images/QueenW.png");
    t11.loadFromFile("images/QueenB.png");
    t12.loadFromFile("images/KingB.png");
    t13.loadFromFile("images/KingW.png");
    t14.loadFromFile("images/PromotionWhite.png");
    t15.loadFromFile("images/PromotionBlack.png");

    // Sprite객체들을 선언하고, 앞서 로드한 텍스처를 사용해 초기화. 스프라이트는 텍스처를 화면에 그리기 위한 것.
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

    float dx = 0, dy = 0; /* 마우스 클릭 위치를 저장하는 변수 초기화 */
    int Movingpiece = 0; /* 이동중인 체스말의 번호를 저장하는 변수 초기화 */

    // 윈도우가 열려있는동안 게임루프 실행
    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window); /* 마우스의 현재 위치 가져오기 */
        x = pos.x / size;
        y = pos.y / size; /* x와 y는 마우스 좌표를 체스판 크기에 맞게 변환한 값 */
        Event e; /* 이벤트 객체 생성, 윈도우에서 발생하는 이벤트 처리 */


        //이벤트가 발생할 때
        while (window.pollEvent(e))
        {
            // 창이 닫히는 이벤트가 발생하면
            if (e.type == Event::Closed)
            {
                window.close(); /* 창을 닫음 */
            }
            window.clear(); /* 화면 새로 고침 */

            // 마우스 버튼이 눌렸을 때의 이벤트 처리
            if (e.type == Event::MouseButtonPressed)
            {
                printf("순서: %d\n", Who_turn);
                if (e.key.code == Mouse::Left) /* 마우스 왼쪽 버튼이 눌렸을 때 */
                {
                    //std::cout << "x=" << x << " y=" << y << "\n";
                    //std::cout << "pos_x=" << pos.x << " pos_y=" << pos.y << "\n";
                    //std::cout << "board[y][x]=" << board[y][x] << "\n";
                    //std::cout << "\n";



                    // 선택한 위치의 체스말을 이동중인 상태로 설정
                    if (board[y][x] != 0)  /* 선택한 위치에 체스말이 있다면 */
                    {
                        dx = pos.x - x * 100;
                        dy = pos.y - y * 100; /* 선택한 위치와 클릭한 위치의 차이 계산 */

                        if (board[y][x] == PawnB && Who_turn == 1) /* 선택한 위치의 체스말이 흑색 폰이고, 흑색의 턴일 때 */
                        {
                            Movingpiece = PawnB; /* 이동 중인 체스말이 흑색 폰임을 저장 */
                            who_turn = Pawnb; /* 현재 이동중인 체스말을 흑색 폰으로 표시 */
                            board[y][x] = 0; /* 해당위치를 빈칸으로 */
                        }
                        if (board[y][x] == PawnW && Who_turn == 0) /* 선택한 위치의 체스말이 백색 폰이고, 백색의 턴일 때 */
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
                        // 선택한 위치가 빈 칸일 때
                        if (board[y][x] == 0)
                        {
                            move = 1;
                            oldPoz.x = x;
                            oldPoz.y = y; /* 이전위치 저장 */
                        }
                    }
                }
            }

            // 체스 말을 이동시킨 후 마우스 버튼이 놓였을 때의 이벤트를 처리
            if (e.type == Event::MouseButtonReleased)
            {
                if (e.key.code == Mouse::Left) /* 마우스 왼쪽 버튼이 놓였을 때 */
                {
                    int ok = 2; /* 체스말의 이동 가능 여부를 확인하는 변수 초기화 */

                    // 이동중 상태인 체스말의 이동 가능 여부 판단
                    if (Movingpiece == PawnW && move == 1) /* 이동 중인 말이 백색 폰일 때 */
                    {
                        ok = PawnWhite(oldPoz.x, oldPoz.y, x, y); /* 이동 가능 여부 확인 (이동가능하면 1을 반환) */
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
                            //std::cout << RookW_Left << "\n";
                        }
                        if (ok == 1 && RookW_Right == 0 && oldPoz.y == 7 && oldPoz.x == 7)
                        {
                            RookW_Right = 1;
                            //std::cout << RookW_Right << "\n";
                        }
                    }
                    if (Movingpiece == RookB && move == 1)
                    {
                        ok = RookBlack(oldPoz.x, oldPoz.y, x, y);
                        if (ok == 1 && RookB_Right == 0 && oldPoz.y == 0 && oldPoz.x == 7)
                        {
                            RookB_Right = 1;
                            //std::cout << RookB_Right<< "\n";
                        }
                        if (ok == 1 && RookB_Left == 0 && oldPoz.y == 0 && oldPoz.x == 0)
                        {
                            RookB_Left = 1;
                            //std::cout << RookB_Left << "\n";
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
                        if (ok == 1 && KingB == 0)
                        {
                            King_B = 1;
                            //   std::cout << KingB << "\n";
                        }
                    }
                    if (Movingpiece == KingW && move == 1)
                    {
                        ok = KingWhiteMove(oldPoz.x, oldPoz.y, x, y);
                        if (ok == 1 && KingW == 0)
                        {
                            King_W = 1;
                            //std::cout << "primaWho_turnKingW=" << KingW << "\n";
                        }
                    }

                    // 이동이 가능할 경우
                    if (ok == 1)
                    {
                        printf("%d", Who_turn);
                        int nr = board[y][x]; /* 이동하려는 위치에 원래 있던 체스말의 번호를 저장 */
                        board[y][x] = Movingpiece; /* 현재 이동 주인 체스말을 새위치에 배치 */

                        // 체크 및 체크메이트처리
                        if (Who_turn == 0)
                        {
                            Who_turn = 1;

                        }
                        if (Who_turn == 1)
                        {

                            Who_turn = 0;

                        }
                    }

                    // 이동이 불가능할 경우
                    else if (ok == 0)

                    {
                        //::cout << "이동불가상태임" ;
                        board[oldPoz.y][oldPoz.x] = Movingpiece; /* 말을 원래 위치로 되돌림 */
                    }
                    move = 0; /* 이동 상태 초기화 */
                }
            }
        }


        // 화면에 그리기
        window.clear(); /* 화면 지우기 */
        window.draw(ChessBoard); /* 체스판 그리기 */

        if (move == 1)
        {
            who_turn.setPosition(pos.x - dx, pos.y - dy);
            window.draw(who_turn);
        }
        for (int i = 0; i < BOARDLEN; i++) /* 체스판의 모든 위치를 순회하며 체스말을 그림 */
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
        window.display(); /* 화면에 그린 내용을 표시 */
    }
    return 0;
}