#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>

#define MAX_N 19
#define DRAW_BLACK printf("��")
#define DRAW_WHITE printf("��")
#define CHANGE_BLACK printf("��")
#define CHANGE_WHITE printf("��")
#define WHITE 2
#define WHITE2 3
#define BLACK 1
#define BLACK2 4
#define abs(a) (((a)>0) ? (a) : (-(a)))


int board[MAX_N][MAX_N] = { 0 }; //���� ������
int board2[MAX_N][MAX_N] = { 0 }; // �¸� �Ǵܽ� ���

int drawStone(int y, int x, int stone); // �� �׸���
void Position(int *y, int *x); // ��ǥ ���

int Position_exchange(int *y, int *x); // ����Ͽ��� �� �����
void exchange(int yy, int xx, int y, int x); //��ȯ ����
void checkFinish(int t); //�¸� �Ǵ�
void gotoxy(int x, int y); // Ŀ�� �̵�
void drawBoard(); // �ٵ��� �׸���
void print_turn(int stone);
int white, black;
int main() {
	drawBoard(); //������ ����
	int x, y, count = 0;
	x = 9, y = 9;
	for (;;) {
		print_turn(count % 4 + 1); // ���� ������ ���
		Position(&y, &x); //��ġ ���
		count += drawStone(y, x, count % 4 + 1); // �� �׸���
		checkFinish(0);
	}
}


void Position(int* y, int* x) { // ��ǥ ���
	gotoxy(*x, *y);
	for (;;) {
		int a = _getch();
		if (a == '\n' || a == '\r') {
			break;
		}
		else if (a == 'w' && *y > 0) (*y)--;
		else if (a == 'a' && *x > 0) (*x)--;
		else if (a == 's' && *y < MAX_N - 1) (*y)++;
		else if (a == 'd' && *x < MAX_N - 1) (*x)++;
		else continue;
		gotoxy(*x, *y);
	}
	return;
}

int drawStone(int y, int x, int stone) { // stone�� 1,4 �̸� ��, 2,3�� ��
	if (stone == 4) {
		stone = BLACK;
	}
	if (stone == 3) {
		stone = WHITE;
	}
	int yy = y, xx = x; //�ٲ� �� ������ ����

	if (board[y][x] == stone) { //��ȯ �õ�
		gotoxy(21, 4);
		printf("��ȯ�� �õ��մϴ�.                            ");
		gotoxy(21, 5);
		printf("%c%d �ٵ� ���� ���õǾ����ϴ�.", x + 'A', y + 1);
		gotoxy(21, 6);
		printf("��ȯ�� ������ �ٵϵ��� �������ּ���");
		gotoxy(21, 7);
		printf("��ȯ�� ����Ͻ÷��� x�� ��������");
		while (1) {
			int check = Position_exchange(&y, &x); // y, x �ּҰ� �ѱ�Ƿ� ��ġ�� �ٲ��. ����!// ��ȯ�� y x�� ����. //��Ҵ� 0 ������ 1 ��ȯ
			if (check == 0) { // ��ȯ ��� main���� ���ư�
				return 0;
			}
			else if (check == 1) {
				if ((board[y][x] == BLACK || board[y][x] == WHITE) && ((abs(yy - y) == 1 && abs(xx - x) == 1) || (abs(yy - y) == 0 && abs(xx - x) == 1)
					|| (abs(yy - y) == 1 && abs(xx - x) == 0))) { //���� ��ȯ
					gotoxy(21, 4);
					printf("%c%d �ٵϵ��� %c%d �ٵϵ��� ��ȯ�Ͽ����ϴ�.", xx + 'A', yy + 1, x + 'A', y + 1);
					gotoxy(21, 5);
					printf("                                           ");
					gotoxy(21, 6);
					printf("                                           ");
					gotoxy(21, 7);
					printf("                                           ");
					exchange(yy, xx, y, x);
					return 1;
				}
			}
		}
	}

	else if (board[y][x] == 0) { // ��ȯ X �� ����
		if (stone == BLACK) {
			DRAW_BLACK;
			board[y][x] = BLACK;
			board2[y][x] = BLACK;
			black++;
			gotoxy(21, 19);
			printf("black : %d  ", black);
		}
		else if (stone == WHITE) {
			DRAW_WHITE;
			board[y][x] = WHITE;
			board2[y][x] = WHITE;
			white++;
			gotoxy(31, 19);
			printf("white : %d  ", white);
		}
		else
			return 0;
		return 1;
	}
	return 0;
}

int Position_exchange(int *y, int *x) { // ��Ҵ� 0, ������ 1 ��ȯ
	gotoxy(*x, *y);
	for (;;) {
		int a = _getch();
		if (a == '\n' || a == '\r') {
			break;
		}
		else if (a == 'w' && *y > 0) (*y)--;
		else if (a == 'a' && *x > 0) (*x)--;
		else if (a == 's' && *y < MAX_N - 1) (*y)++;
		else if (a == 'd' && *x < MAX_N - 1) (*x)++;
		else if (a == 'x') {
			gotoxy(21, 4);
			printf("��ȯ�� ��ҵǾ����ϴ�.             ");
			gotoxy(21, 5);
			printf("                                           ");
			gotoxy(21, 6);
			printf("                                           ");
			gotoxy(21, 7);
			printf("                                           ");
			return 0;
		}
		else continue;
		gotoxy(*x, *y);
	}
	return 1;
}
void exchange(int yy, int xx, int y, int x) { // �ϼ�
	int a = board[y][x];
	if (board[yy][xx] == BLACK) {
		board[y][x] = BLACK2;
		board2[y][x] = BLACK;
		gotoxy(x, y);
		CHANGE_BLACK;
	}
	else if (board[yy][xx] == WHITE) {
		board[y][x] = WHITE2;
		board2[y][x] = WHITE;
		gotoxy(x, y);
		CHANGE_WHITE;
	}

	if (a == BLACK) {
		board[yy][xx] = BLACK2;
		board2[yy][xx] = BLACK;
		gotoxy(xx, yy);
		CHANGE_BLACK;
	}
	else if (a == WHITE) {
		board[yy][xx] = WHITE2;
		board2[yy][xx] = WHITE;
		gotoxy(xx, yy);
		CHANGE_WHITE;
	}
}
void checkFinish(int t) { //�ϼ�
	if (t == MAX_N * MAX_N) return;
	int x = t % MAX_N;
	int y = t / MAX_N;
	int color = board2[y][x];
	int dir[4] = { 0 };
	for (int i = 0; i < 6 && color != 0; i++) {
		if (x + i < MAX_N && color == board2[y][x + i]) // ����
			dir[0]++;
		if (y + i < MAX_N && color == board2[y + i][x]) // ����
			dir[1]++;
		if (x + i < MAX_N && y + i < MAX_N && color == board2[y + i][x + i]) // �ϰ� ����
			dir[2]++;
		if (x - i >= 0 && y + i < MAX_N && color == board2[y + i][x - i]) // ��¹���
			dir[3]++;
	}
	for (int i = 0; i < 4; i++)
		if (dir[i] == 6) {
			gotoxy(21, 20);
			printf("GAME OVER.. ");
			if (color == WHITE)
				printf("WHITE "), DRAW_WHITE;
			else if (color == BLACK)
				printf("BLACK "), DRAW_BLACK;
			printf(" WIN!!!                                 ");
			gotoxy(21, 21);
			printf("�����Ͻ÷��� Enter�� ��������");
			while (_getch() != '\r');

			exit(0);
		}
	checkFinish(t + 1);
}

void gotoxy(int x, int y) { // Ŀ�� �����̱�
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void drawBoard() { // ������ �׸���
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			gotoxy(j, i);
			if (i == 0) {
				if (j == 0)
					printf("��");
				else if (j == MAX_N - 1)
					printf("��");
				else
					printf("��");
			}
			else if (j == 0) {
				if (i == MAX_N - 1)
					printf("��");
				else
					printf("��");
			}
			else if (j == MAX_N - 1) {
				if (i == MAX_N - 1)
					printf("��");
				else
					printf("��");
			}
			else if (i == MAX_N - 1) {
				printf("��");
			}
			else
				printf("��");
		}
	}
	for (int i = 0; i < MAX_N; i++) {
		gotoxy(MAX_N, i);
		printf("%d", i + 1);
		gotoxy(i, MAX_N);
		printf("%c", i + 'A');
	}
	gotoxy(21, 19);
	printf("black : %d  ", black);
	gotoxy(31, 19);
	printf("white : %d  ", white);
}
void print_turn(int stone) {
	if (stone == 4) {
		gotoxy(21, 12);
		printf("                     ");
		gotoxy(21, 10);
		printf("�浹 ���� �Դϴ�.(1)");
		stone = BLACK;
	}
	else if (stone == 3) {
		gotoxy(21, 10);
		printf("                    ");
		gotoxy(21, 12);
		printf("�鵹 ���� �Դϴ�.(0)");
		stone = WHITE;
	}
	else if (stone == BLACK) {
		gotoxy(21, 12);
		printf("                    ");
		gotoxy(21, 10);
		printf("�浹 ���� �Դϴ�.(0)");
	}
	else if (stone == WHITE) {
		gotoxy(21, 10);
		printf("                    ");
		gotoxy(21, 12);
		printf("�鵹 ���� �Դϴ�.(1)");
	}
}