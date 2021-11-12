#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>
#define wide 50			//맵넓이
#define high 40			//맵높이
int map[high][wide] = {
		{0, },
		{0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, },
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{0, },
		{0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, },
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{0, },
		{0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, },
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{0, },
		{0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, },
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
};		//맵 0: 빈공간, 1: 벽, 2: 벽돌, 3: 공, 4: 막대기

int map_next[high][wide] = {
		{0, },
		{0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, },
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{0, },
		{0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, },
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{0, },
		{0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, },
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{0, },
		{0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, },
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
};		//움직이고 나서 그려질 맵
int b_state = 3;	//공 진행방향(처음엔 아래로 떨어짐) - 0: 위, 1: 왼쪽위, 2: 오른쪽위, 3: 아래, 4: 왼쪽아래, 5: 오른쪽아래
int b_h;		//공세로좌표
int b_w;		//공가로좌표
int bar_l;		//막대왼쪽끝좌표
int bar_r;		//막대 오른쪽 끝좌표
int game_state = 0;				//1이면 게임종료.
int score;		//점수
int rn = 0;		//랜덤으로 방향바꿨는지(블록여러개사라지는거 방지)

void init() {			//초기화(맵초기화, )
	system("mode con: cols=102 lines=49");

	for (int i = 0; i < high; i++) {
		for (int j = 0; j < wide; j++) {
			if (i == 0 || j == 0 || i == high - 1 || j == wide - 1) {
				map[i][j] = 1;		//벽
				map_next[i][j] = 1;
			}
			else if (i == 30 && j == 24) {
				map[i][j] = 3;		//공
				map_next[i][j] = 3;
				b_h = 30;
				b_w = 24;
			}
			else if (i == 32 && (j == 22 || j == 23 || j == 24 || j == 25 || j == 26)) {
				map[i][j] = 4;		//막대기
				map_next[i][j] = 4;
				bar_l = 22;
				bar_r = 26;
			}
			/*else if (i == 1 || i == 2 || i == 3) {
				map[i][j] = 2;				//벽돌
				map_next[i][j] = 2;
			}*/
			else if (i == high - 2) {			//바닥
				map[i][j] = 7;
				map_next[i][j] = 7;
			}
		}
	}
}

void update_score() {
	COORD pos = { 45, 40 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("score : %d", score);
}
void gotoxy(int x, int y) {			//커서이동
	COORD pos = { y * 2,x };			//가로를 y에 보냄
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void drawmap() {		//화면전체 지우고 그리기
	system("cls");
	for (int i = 0; i < high; i++) {
		for (int j = 0; j < wide; j++) {
			if (map[i][j] == 1) {
				printf("□");
			}
			else if (map[i][j] == 3) {
				printf("●");
			}
			else if (map[i][j] == 4) {
				printf("〓");
			}
			else if (map[i][j] == 0)
				printf("　");
			else if (map[i][j] == 2) {
				printf("■");
			}
			else if (map[i][j] == 7) {
				printf("△");
			}
		}
		printf("\n");
	}
}
void drawmap2() {		//바뀐부분만 다시 그리기
	for (int i = 0; i < high; i++) {
		for (int j = 0; j < wide; j++) {
			if (map[i][j] != map_next[i][j]) {			//이전과 달라진 부분만 바꿔주기
				gotoxy(i, j);		//커서이동
				if (map_next[i][j] == 1) {
					printf("□");
				}
				else if (map_next[i][j] == 3) {
					printf("●");
				}
				else if (map_next[i][j] == 4) {
					printf("〓");
				}
				else if (map_next[i][j] == 0) {
					printf("　");
				}
				else if (map_next[i][j] == 2) {
					printf("■");
				}
				map[i][j] = map_next[i][j];
			}
		}
		//printf("\n");
	}
}
void change_dir(int d) {
	int rand_n;
	if (d == 0) {			//아래랜덤
		srand((unsigned)time(NULL));
		rand_n = rand() % 2;
		b_state = (rand_n + 4);			//4, 5 왼쪽아래나 오른쪽아래
	}
	else if (d == 1) {		//위랜덤
		srand((unsigned)time(NULL));
		rand_n = rand() % 2;
		b_state = rand_n + 1;			// 1, 2 왼쪽위나 오른쪽위
	}

	map_next[b_h][b_w] = 0;
	if (rn == 1) {
		srand((unsigned)time(NULL));
		rand_n = rand() % 3;
		switch (rand_n) {
		case 0:
			break;
		case 1:
			if (map[b_h][b_w + 1] != 1 && map[b_h][b_w + 1] != 2)
				b_w = b_w + 1;
			break;
		case 2:
			if (map[b_h][b_w - 1] != 1 && map[b_h][b_w - 1] != 2)
				b_w = b_w - 1;
			break;
		}
		rn = 0;
	}
	else {
		rn++;
	}

	map_next[b_h][b_w] = 3;
}
void ball_pos() {
	int rand_n;
	srand((unsigned)time(NULL));
	rand_n = rand() % 3;
	switch (rand_n) {
	case 0:
		break;
	case 1:
		b_w = b_w + 1;
		break;
	case 2:
		b_w = b_w - 1;
		break;
	}
}
unsigned _stdcall Thread_Ball(void* arg)
{
	//int cnt = 0;		테스트용

	while (game_state == 0) {
		if (map[b_h - 1][b_w] == 2) {			//블록닿았을 때
			map_next[b_h - 1][b_w] = 0;
			score++;
			update_score();
			change_dir(0);
			drawmap2();
			continue;
		}
		if (map[b_h + 1][b_w] == 2) {
			map_next[b_h + 1][b_w] = 0;
			score++;
			update_score();
			change_dir(1);
			drawmap2();
			continue;
		}
		/*if (map[b_h][b_w + 1] == 2) {
			map_next[b_h][b_w + 1] = 0;
			drawmap2();
			continue;
		}
		if (map[b_h][b_w - 1] == 2) {
			map_next[b_h][b_w - 1] = 0;
			drawmap2();
			continue;
		}*/

		switch (b_state) {		//공 진행방향이

		case 0:					//위쪽이면
			if (map[b_h - 1][b_w] == 0) {		//빈공간이면 위로 이동
				map_next[b_h][b_w] = 0;
				b_h -= 1;
				map_next[b_h][b_w] = 3;
			}
			else if (map[b_h - 1][b_w] == 1) {		//벽이면 방향바꾸기
				if (b_h == 1) {			//천장이면 아래대각선방향 랜덤으로 
					change_dir(0);
				}
				else {						//중간 양옆 벽이면 가던 위대각선방향 랜덤으로 
					change_dir(1);
				}
			}
			break;
		case 1:					//왼쪽 위쪽이면
			if (map[b_h - 1][b_w - 1] == 0 && (map[b_h][b_w - 1] != 2 || map[b_h - 1][b_w] != 2)) {		//빈공간이면 걍가기
				map_next[b_h][b_w] = 0;
				b_h -= 1;
				b_w -= 1;
				map_next[b_h][b_w] = 3;
			}
			else if (map[b_h - 1][b_w - 1] == 1) {		//벽이면 방향바꾸기
				if (b_h == 1) {			//천장이면 아래대각선방향 랜덤으로 
					change_dir(0);
				}
				else {						//중간 왼쪽 벽이면 오른쪽위 대각선 방향으로
					b_state = 2;
				}
			}
			else if (map[b_h - 1][b_w - 1] == 2) {			//블록이면
				map_next[b_h - 1][b_w - 1] = 0;
				score++;
				update_score();
				change_dir(0);
			}
			break;
		case 2:					//오른쪽 위쪽이면
			if (map[b_h - 1][b_w + 1] == 0 && (map[b_h][b_w + 1] != 2 || map[b_h - 1][b_w] != 2)) {		//빈공간이면 걍 이동
				map_next[b_h][b_w] = 0;
				b_h -= 1;
				b_w += 1;
				map_next[b_h][b_w] = 3;
			}
			else if (map[b_h - 1][b_w + 1] == 1) {		//벽이면 방향바꾸기
				if (b_h == 1) {			//천장이면 아래방향 랜덤으로 
					change_dir(0);
				}
				else {						//중간 오른쪽 벽이면 왼쪽위 대각선 방향으로
					b_state = 1;
				}
			}
			else if (map[b_h - 1][b_w + 1] == 2) {			//블록이면
				map_next[b_h - 1][b_w + 1] = 0;
				score++;
				update_score();
				change_dir(0);
			}
			break;
		case 3:					//아래쪽이면
			if (map[b_h + 1][b_w] == 0) {			//빈공간이면 아래이동
				map_next[b_h][b_w] = 0;
				b_h += 1;
				map_next[b_h][b_w] = 3;
			}
			else if (map[b_h + 1][b_w] == 4) {		//막대기면 위대각선방향 랜덤으로 바꾸기
				change_dir(1);
			}
			break;
		case 4:					//왼쪽 아래쪽이면
			if (map[b_h + 1][b_w - 1] == 0) {			//빈공간이면 아래이동
				map_next[b_h][b_w] = 0;
				b_h += 1;
				b_w -= 1;
				map_next[b_h][b_w] = 3;
			}
			else if (map[b_h + 1][b_w - 1] == 4) {		//막대기면 방향바꾸기
				change_dir(1);
			}
			else if (map[b_h + 1][b_w - 1] == 1 || map[b_h + 1][b_w + 1] == 7) {		//벽이면 방향바꾸기
				if ((b_h + 1) == (high - 2)) {			//바닥이면 게임종료
					game_state = 1;
					break;
				}
				else {						//벽이면 오른쪽아래대각선방향으로
					b_state = 5;
				}
			}
			else if (map[b_h + 1][b_w - 1] == 2) {			//벽돌이면
				map_next[b_h + 1][b_w - 1] = 0;
				score++;
				update_score();
				change_dir(1);
			}
			break;
		case 5:					//오른쪽 아래쪽이면
			if (map[b_h + 1][b_w + 1] == 0) {			//빈공간이면 아래이동
				map_next[b_h][b_w] = 0;
				b_h += 1;
				b_w += 1;
				map_next[b_h][b_w] = 3;
			}
			else if (map[b_h + 1][b_w + 1] == 4) {		//막대기면 위대각선방향 랜덤으로
				change_dir(1);
			}
			else if (map[b_h + 1][b_w + 1] == 1 || map[b_h + 1][b_w + 1] == 7) {		//벽이면 방향바꾸기
				if ((b_h + 1) == (high - 2)) {			//바닥이면 위방향 랜덤으로(진짜게임에선 게임오버) 
					game_state = 1;
					break;
				}
				else {						//벽이면 아래왼쪽대각선방향
					b_state = 4;
				}
			}
			else if (map[b_h + 1][b_w + 1] == 2) {			//벽돌이면
				map_next[b_h + 1][b_w + 1] = 0;
				score++;
				update_score();
				change_dir(1);
			}
			break;

		}
		Sleep(80);
		drawmap2();
		/*if (cnt == 1)
			break;*/		//테스트용
	}
	game_state = 1;
	_endthread();
}
int main(void) {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	int n, kd;
	init();			//맵초기화
	//drawmap();		//전체 맵그리기
	printf(" ＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿\n");
	printf("｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 　　　 ｜\n");
	printf("｜　　　　　　　　　　　　　　벽돌깨기　　　　　　　     　　　 　　　｜\n");
	printf("｜　　　　　　　　　　　　시작하려면 1입력 　　　　　　　　　　 　　　｜\n");
	printf("｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　 　 　｜\n");
	printf(" ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n");
	printf("시작하려면 1입력 : ");

	scanf("%d", &n);
	if (n == 1) {
		drawmap();
		_beginthreadex(NULL, 0, Thread_Ball, 0, 0, NULL);		//공과 키보드 각각 동시에 쓰기 때문에 공함수를 쓰레드로 시작

		while (1) {
			if (game_state == 1)		//1이면 게임종료
				break;
			if (_kbhit())			//키보드 눌림감지
			{
				kd = _getch();
				switch (kd) {
				case 75:		//왼쪽방향키를 눌렀을 때
					if (map[32][bar_l - 1] != 1) {			//벽이면 못감
						map_next[32][bar_r] = 0;
						map_next[32][bar_l - 1] = 4;
						bar_r--;
						bar_l--;
						break;
					}
				case 77:		//오른쪽방향키를 눌렀을 때
					if (map[32][bar_r + 1] != 1) {			//벽이면 못감
						map_next[32][bar_l] = 0;
						map_next[32][bar_r + 1] = 4;
						bar_r++;
						bar_l++;
						break;
					}
				}
				drawmap2();		//바뀐부분 그리기
				Sleep(10);
			}
		}
		system("cls");
		if (score >= 20) {
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("■                                                                                                ■\n");
			printf("■                                                                                                ■\n");
			printf("■                                                                                                ■\n");
			printf("■                                                                                                ■\n");
			printf("■      ■      ■   ■    ■■■    ■■■    ■             ■■          ■■                  ■\n");
			printf("■      ■■    ■   ■    ■        ■        ■           ■    ■      ■    ■                ■\n");
			printf("■      ■  ■  ■   ■    ■        ■■■    ■                     ■                          ■\n");
			printf("■      ■    ■■   ■    ■        ■                  ■■         ■          ■■            ■\n");
			printf("■      ■      ■   ■    ■■■    ■■■    ■             ■              ■                  ■\n");
			printf("■                                                              ■■■■■■■                    ■\n");
			printf("■          ■                                                                                    ■\n");
			printf("■          ■     ■                                                                             ■\n");
			printf("■               ■                                                                               ■\n");
			printf("■        ■■          ■■                                                                      ■\n");
			printf("■      ■■■■    ■■                                                                          ■\n");
			printf("■      ■■■                                                                                    ■\n");
			printf("■    ■                                                                                          ■\n");
			printf("■                                                                                                ■\n");
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("\n");
			printf("                                         S C O R E : %d", score);
		}
		else if (score < 20) {
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("■                                                                                                ■\n");
			printf("■    ■■■■      ■      ■          ■  ■■■■                                              ■\n");
			printf("■    ■          ■  ■    ■■      ■■  ■                                                    ■\n");
			printf("■    ■  ■■  ■■■■■  ■  ■  ■  ■  ■■■■                                              ■\n");
			printf("■    ■    ■  ■      ■  ■  ■  ■  ■  ■              ■■■■■      ■■■■■            ■\n");
			printf("■    ■■■■  ■      ■  ■    ■    ■  ■■■■          ■  ■          ■  ■              ■\n");
			printf("■                                                            ■  ■    ■    ■  ■              ■\n");
			printf("■                                                                ■          ■                  ■\n");
			printf("■                                                                ■                              ■\n");
			printf("■    ■■■■  ■      ■  ■■■■  ■■■■                                                    ■\n");
			printf("■    ■    ■  ■      ■  ■        ■    ■                   ■■■■■■■■                 ■\n");
			printf("■    ■    ■  ■      ■  ■■■■  ■■■■               ■■                ■■             ■\n");
			printf("■    ■    ■    ■  ■    ■        ■      ■                                                  ■\n");
			printf("■    ■■■■      ■      ■■■■  ■      ■                                                  ■\n");
			printf("■                                                                                                ■\n");
			printf("■                                                                                                ■\n");
			printf("■                                                                                                ■\n");
			printf("■                                                                                                ■\n");
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
			printf("\n");
			printf("                                         S C O R E : %d", score);
		}

	}
	system("pause>null");

	return 0;
}
