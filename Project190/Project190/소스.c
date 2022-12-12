#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>

#define MAX_N 19
#define DRAW_BLACK printf("○")
#define DRAW_WHITE printf("●")
#define CHANGE_BLACK printf("□")
#define CHANGE_WHITE printf("■")
#define WHITE 2
#define WHITE2 3
#define BLACK 1
#define BLACK2 4
#define abs(a) (((a)>0) ? (a) : (-(a)))


int board[MAX_N][MAX_N] = { 0 }; //실제 오목판
int board2[MAX_N][MAX_N] = { 0 }; // 승리 판단시 사용

int drawStone(int y, int x, int stone); // 돌 그리기
void Position(int *y, int *x); // 좌표 계산

int Position_exchange(int *y, int *x); // 취소하였을 때 재실행
void exchange(int yy, int xx, int y, int x); //교환 실행
void checkFinish(int t); //승리 판단
void gotoxy(int x, int y); // 커서 이동
void drawBoard(); // 바둑판 그리기
void print_turn(int stone);
int white, black;
int main() {
	drawBoard(); //오목판 생성
	int x, y, count = 0;
	x = 9, y = 9;
	for (;;) {
		print_turn(count % 4 + 1); // 누구 턴인지 출력
		Position(&y, &x); //위치 잡기
		count += drawStone(y, x, count % 4 + 1); // 돌 그리기
		checkFinish(0);
	}
}


void Position(int* y, int* x) { // 좌표 계산
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

int drawStone(int y, int x, int stone) { // stone이 1,4 이면 흑, 2,3면 백
	if (stone == 4) {
		stone = BLACK;
	}
	if (stone == 3) {
		stone = WHITE;
	}
	int yy = y, xx = x; //바뀔 수 있으니 저장

	if (board[y][x] == stone) { //교환 시도
		gotoxy(21, 4);
		printf("교환을 시도합니다.                            ");
		gotoxy(21, 5);
		printf("%c%d 바둑 돌이 선택되었습니다.", x + 'A', y + 1);
		gotoxy(21, 6);
		printf("교환할 인접한 바둑돌을 선택해주세요");
		gotoxy(21, 7);
		printf("교환을 취소하시려면 x를 누르세요");
		while (1) {
			int check = Position_exchange(&y, &x); // y, x 주소값 넘기므로 위치가 바뀐다. 주의!// 교환할 y x를 얻어낸다. //취소는 0 정상은 1 반환
			if (check == 0) { // 교환 취소 main으로 돌아가
				return 0;
			}
			else if (check == 1) {
				if ((board[y][x] == BLACK || board[y][x] == WHITE) && ((abs(yy - y) == 1 && abs(xx - x) == 1) || (abs(yy - y) == 0 && abs(xx - x) == 1)
					|| (abs(yy - y) == 1 && abs(xx - x) == 0))) { //정상 교환
					gotoxy(21, 4);
					printf("%c%d 바둑돌과 %c%d 바둑돌을 교환하였습니다.", xx + 'A', yy + 1, x + 'A', y + 1);
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

	else if (board[y][x] == 0) { // 교환 X 돌 놓기
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

int Position_exchange(int *y, int *x) { // 취소는 0, 정상은 1 반환
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
			printf("교환이 취소되었습니다.             ");
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
void exchange(int yy, int xx, int y, int x) { // 완성
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
void checkFinish(int t) { //완성
	if (t == MAX_N * MAX_N) return;
	int x = t % MAX_N;
	int y = t / MAX_N;
	int color = board2[y][x];
	int dir[4] = { 0 };
	for (int i = 0; i < 6 && color != 0; i++) {
		if (x + i < MAX_N && color == board2[y][x + i]) // 가로
			dir[0]++;
		if (y + i < MAX_N && color == board2[y + i][x]) // 세로
			dir[1]++;
		if (x + i < MAX_N && y + i < MAX_N && color == board2[y + i][x + i]) // 하강 방향
			dir[2]++;
		if (x - i >= 0 && y + i < MAX_N && color == board2[y + i][x - i]) // 상승방향
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
			printf("종료하시려면 Enter를 누르세요");
			while (_getch() != '\r');

			exit(0);
		}
	checkFinish(t + 1);
}

void gotoxy(int x, int y) { // 커서 움직이기
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void drawBoard() { // 오목판 그리기
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			gotoxy(j, i);
			if (i == 0) {
				if (j == 0)
					printf("┌");
				else if (j == MAX_N - 1)
					printf("┐");
				else
					printf("┬");
			}
			else if (j == 0) {
				if (i == MAX_N - 1)
					printf("└");
				else
					printf("├");
			}
			else if (j == MAX_N - 1) {
				if (i == MAX_N - 1)
					printf("┘");
				else
					printf("┤");
			}
			else if (i == MAX_N - 1) {
				printf("┴");
			}
			else
				printf("┼");
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
		printf("흑돌 차례 입니다.(1)");
		stone = BLACK;
	}
	else if (stone == 3) {
		gotoxy(21, 10);
		printf("                    ");
		gotoxy(21, 12);
		printf("백돌 차례 입니다.(0)");
		stone = WHITE;
	}
	else if (stone == BLACK) {
		gotoxy(21, 12);
		printf("                    ");
		gotoxy(21, 10);
		printf("흑돌 차례 입니다.(0)");
	}
	else if (stone == WHITE) {
		gotoxy(21, 10);
		printf("                    ");
		gotoxy(21, 12);
		printf("백돌 차례 입니다.(1)");
	}
}