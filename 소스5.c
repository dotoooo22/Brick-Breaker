#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>
#define wide 50			//�ʳ���
#define high 40			//�ʳ���
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
};		//�� 0: �����, 1: ��, 2: ����, 3: ��, 4: �����

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
};		//�����̰� ���� �׷��� ��
int b_state = 3;	//�� �������(ó���� �Ʒ��� ������) - 0: ��, 1: ������, 2: ��������, 3: �Ʒ�, 4: ���ʾƷ�, 5: �����ʾƷ�
int b_h;		//��������ǥ
int b_w;		//��������ǥ
int bar_l;		//������ʳ���ǥ
int bar_r;		//���� ������ ����ǥ
int game_state = 0;				//1�̸� ��������.
int score;		//����
int rn = 0;		//�������� ����ٲ����(��Ͽ�����������°� ����)

void init() {			//�ʱ�ȭ(���ʱ�ȭ, )
	system("mode con: cols=102 lines=49");

	for (int i = 0; i < high; i++) {
		for (int j = 0; j < wide; j++) {
			if (i == 0 || j == 0 || i == high - 1 || j == wide - 1) {
				map[i][j] = 1;		//��
				map_next[i][j] = 1;
			}
			else if (i == 30 && j == 24) {
				map[i][j] = 3;		//��
				map_next[i][j] = 3;
				b_h = 30;
				b_w = 24;
			}
			else if (i == 32 && (j == 22 || j == 23 || j == 24 || j == 25 || j == 26)) {
				map[i][j] = 4;		//�����
				map_next[i][j] = 4;
				bar_l = 22;
				bar_r = 26;
			}
			/*else if (i == 1 || i == 2 || i == 3) {
				map[i][j] = 2;				//����
				map_next[i][j] = 2;
			}*/
			else if (i == high - 2) {			//�ٴ�
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
void gotoxy(int x, int y) {			//Ŀ���̵�
	COORD pos = { y * 2,x };			//���θ� y�� ����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void drawmap() {		//ȭ����ü ����� �׸���
	system("cls");
	for (int i = 0; i < high; i++) {
		for (int j = 0; j < wide; j++) {
			if (map[i][j] == 1) {
				printf("��");
			}
			else if (map[i][j] == 3) {
				printf("��");
			}
			else if (map[i][j] == 4) {
				printf("��");
			}
			else if (map[i][j] == 0)
				printf("��");
			else if (map[i][j] == 2) {
				printf("��");
			}
			else if (map[i][j] == 7) {
				printf("��");
			}
		}
		printf("\n");
	}
}
void drawmap2() {		//�ٲ�κи� �ٽ� �׸���
	for (int i = 0; i < high; i++) {
		for (int j = 0; j < wide; j++) {
			if (map[i][j] != map_next[i][j]) {			//������ �޶��� �κи� �ٲ��ֱ�
				gotoxy(i, j);		//Ŀ���̵�
				if (map_next[i][j] == 1) {
					printf("��");
				}
				else if (map_next[i][j] == 3) {
					printf("��");
				}
				else if (map_next[i][j] == 4) {
					printf("��");
				}
				else if (map_next[i][j] == 0) {
					printf("��");
				}
				else if (map_next[i][j] == 2) {
					printf("��");
				}
				map[i][j] = map_next[i][j];
			}
		}
		//printf("\n");
	}
}
void change_dir(int d) {
	int rand_n;
	if (d == 0) {			//�Ʒ�����
		srand((unsigned)time(NULL));
		rand_n = rand() % 2;
		b_state = (rand_n + 4);			//4, 5 ���ʾƷ��� �����ʾƷ�
	}
	else if (d == 1) {		//������
		srand((unsigned)time(NULL));
		rand_n = rand() % 2;
		b_state = rand_n + 1;			// 1, 2 �������� ��������
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
	//int cnt = 0;		�׽�Ʈ��

	while (game_state == 0) {
		if (map[b_h - 1][b_w] == 2) {			//��ϴ���� ��
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

		switch (b_state) {		//�� ���������

		case 0:					//�����̸�
			if (map[b_h - 1][b_w] == 0) {		//������̸� ���� �̵�
				map_next[b_h][b_w] = 0;
				b_h -= 1;
				map_next[b_h][b_w] = 3;
			}
			else if (map[b_h - 1][b_w] == 1) {		//���̸� ����ٲٱ�
				if (b_h == 1) {			//õ���̸� �Ʒ��밢������ �������� 
					change_dir(0);
				}
				else {						//�߰� �翷 ���̸� ���� ���밢������ �������� 
					change_dir(1);
				}
			}
			break;
		case 1:					//���� �����̸�
			if (map[b_h - 1][b_w - 1] == 0 && (map[b_h][b_w - 1] != 2 || map[b_h - 1][b_w] != 2)) {		//������̸� ������
				map_next[b_h][b_w] = 0;
				b_h -= 1;
				b_w -= 1;
				map_next[b_h][b_w] = 3;
			}
			else if (map[b_h - 1][b_w - 1] == 1) {		//���̸� ����ٲٱ�
				if (b_h == 1) {			//õ���̸� �Ʒ��밢������ �������� 
					change_dir(0);
				}
				else {						//�߰� ���� ���̸� �������� �밢�� ��������
					b_state = 2;
				}
			}
			else if (map[b_h - 1][b_w - 1] == 2) {			//����̸�
				map_next[b_h - 1][b_w - 1] = 0;
				score++;
				update_score();
				change_dir(0);
			}
			break;
		case 2:					//������ �����̸�
			if (map[b_h - 1][b_w + 1] == 0 && (map[b_h][b_w + 1] != 2 || map[b_h - 1][b_w] != 2)) {		//������̸� �� �̵�
				map_next[b_h][b_w] = 0;
				b_h -= 1;
				b_w += 1;
				map_next[b_h][b_w] = 3;
			}
			else if (map[b_h - 1][b_w + 1] == 1) {		//���̸� ����ٲٱ�
				if (b_h == 1) {			//õ���̸� �Ʒ����� �������� 
					change_dir(0);
				}
				else {						//�߰� ������ ���̸� ������ �밢�� ��������
					b_state = 1;
				}
			}
			else if (map[b_h - 1][b_w + 1] == 2) {			//����̸�
				map_next[b_h - 1][b_w + 1] = 0;
				score++;
				update_score();
				change_dir(0);
			}
			break;
		case 3:					//�Ʒ����̸�
			if (map[b_h + 1][b_w] == 0) {			//������̸� �Ʒ��̵�
				map_next[b_h][b_w] = 0;
				b_h += 1;
				map_next[b_h][b_w] = 3;
			}
			else if (map[b_h + 1][b_w] == 4) {		//������ ���밢������ �������� �ٲٱ�
				change_dir(1);
			}
			break;
		case 4:					//���� �Ʒ����̸�
			if (map[b_h + 1][b_w - 1] == 0) {			//������̸� �Ʒ��̵�
				map_next[b_h][b_w] = 0;
				b_h += 1;
				b_w -= 1;
				map_next[b_h][b_w] = 3;
			}
			else if (map[b_h + 1][b_w - 1] == 4) {		//������ ����ٲٱ�
				change_dir(1);
			}
			else if (map[b_h + 1][b_w - 1] == 1 || map[b_h + 1][b_w + 1] == 7) {		//���̸� ����ٲٱ�
				if ((b_h + 1) == (high - 2)) {			//�ٴ��̸� ��������
					game_state = 1;
					break;
				}
				else {						//���̸� �����ʾƷ��밢����������
					b_state = 5;
				}
			}
			else if (map[b_h + 1][b_w - 1] == 2) {			//�����̸�
				map_next[b_h + 1][b_w - 1] = 0;
				score++;
				update_score();
				change_dir(1);
			}
			break;
		case 5:					//������ �Ʒ����̸�
			if (map[b_h + 1][b_w + 1] == 0) {			//������̸� �Ʒ��̵�
				map_next[b_h][b_w] = 0;
				b_h += 1;
				b_w += 1;
				map_next[b_h][b_w] = 3;
			}
			else if (map[b_h + 1][b_w + 1] == 4) {		//������ ���밢������ ��������
				change_dir(1);
			}
			else if (map[b_h + 1][b_w + 1] == 1 || map[b_h + 1][b_w + 1] == 7) {		//���̸� ����ٲٱ�
				if ((b_h + 1) == (high - 2)) {			//�ٴ��̸� ������ ��������(��¥���ӿ��� ���ӿ���) 
					game_state = 1;
					break;
				}
				else {						//���̸� �Ʒ����ʴ밢������
					b_state = 4;
				}
			}
			else if (map[b_h + 1][b_w + 1] == 2) {			//�����̸�
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
			break;*/		//�׽�Ʈ��
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
	init();			//���ʱ�ȭ
	//drawmap();		//��ü �ʱ׸���
	printf(" �ߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣ�\n");
	printf("�������������������������������������������������������������� ������ ��\n");
	printf("�������������������������������������⡡������������     ������ ��������\n");
	printf("�������������������������������Ϸ��� 1�Է� �������������������� ��������\n");
	printf("���������������������������������������������������������������� �� ����\n");
	printf(" ����������������������������������������������������������������������\n");
	printf("�����Ϸ��� 1�Է� : ");

	scanf("%d", &n);
	if (n == 1) {
		drawmap();
		_beginthreadex(NULL, 0, Thread_Ball, 0, 0, NULL);		//���� Ű���� ���� ���ÿ� ���� ������ ���Լ��� ������� ����

		while (1) {
			if (game_state == 1)		//1�̸� ��������
				break;
			if (_kbhit())			//Ű���� ��������
			{
				kd = _getch();
				switch (kd) {
				case 75:		//���ʹ���Ű�� ������ ��
					if (map[32][bar_l - 1] != 1) {			//���̸� ����
						map_next[32][bar_r] = 0;
						map_next[32][bar_l - 1] = 4;
						bar_r--;
						bar_l--;
						break;
					}
				case 77:		//�����ʹ���Ű�� ������ ��
					if (map[32][bar_r + 1] != 1) {			//���̸� ����
						map_next[32][bar_l] = 0;
						map_next[32][bar_r + 1] = 4;
						bar_r++;
						bar_l++;
						break;
					}
				}
				drawmap2();		//�ٲ�κ� �׸���
				Sleep(10);
			}
		}
		system("cls");
		if (score >= 20) {
			printf("���������������������������������������������������\n");
			printf("��                                                                                                ��\n");
			printf("��                                                                                                ��\n");
			printf("��                                                                                                ��\n");
			printf("��                                                                                                ��\n");
			printf("��      ��      ��   ��    ����    ����    ��             ���          ���                  ��\n");
			printf("��      ���    ��   ��    ��        ��        ��           ��    ��      ��    ��                ��\n");
			printf("��      ��  ��  ��   ��    ��        ����    ��                     ��                          ��\n");
			printf("��      ��    ���   ��    ��        ��                  ���         ��          ���            ��\n");
			printf("��      ��      ��   ��    ����    ����    ��             ��              ��                  ��\n");
			printf("��                                                              ��������                    ��\n");
			printf("��          ��                                                                                    ��\n");
			printf("��          ��     ��                                                                             ��\n");
			printf("��               ��                                                                               ��\n");
			printf("��        ���          ���                                                                      ��\n");
			printf("��      �����    ���                                                                          ��\n");
			printf("��      ����                                                                                    ��\n");
			printf("��    ��                                                                                          ��\n");
			printf("��                                                                                                ��\n");
			printf("���������������������������������������������������\n");
			printf("\n");
			printf("                                         S C O R E : %d", score);
		}
		else if (score < 20) {
			printf("���������������������������������������������������\n");
			printf("��                                                                                                ��\n");
			printf("��    �����      ��      ��          ��  �����                                              ��\n");
			printf("��    ��          ��  ��    ���      ���  ��                                                    ��\n");
			printf("��    ��  ���  ������  ��  ��  ��  ��  �����                                              ��\n");
			printf("��    ��    ��  ��      ��  ��  ��  ��  ��  ��              ������      ������            ��\n");
			printf("��    �����  ��      ��  ��    ��    ��  �����          ��  ��          ��  ��              ��\n");
			printf("��                                                            ��  ��    ��    ��  ��              ��\n");
			printf("��                                                                ��          ��                  ��\n");
			printf("��                                                                ��                              ��\n");
			printf("��    �����  ��      ��  �����  �����                                                    ��\n");
			printf("��    ��    ��  ��      ��  ��        ��    ��                   ���������                 ��\n");
			printf("��    ��    ��  ��      ��  �����  �����               ���                ���             ��\n");
			printf("��    ��    ��    ��  ��    ��        ��      ��                                                  ��\n");
			printf("��    �����      ��      �����  ��      ��                                                  ��\n");
			printf("��                                                                                                ��\n");
			printf("��                                                                                                ��\n");
			printf("��                                                                                                ��\n");
			printf("��                                                                                                ��\n");
			printf("���������������������������������������������������\n");
			printf("\n");
			printf("                                         S C O R E : %d", score);
		}

	}
	system("pause>null");

	return 0;
}
