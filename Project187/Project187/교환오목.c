#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

#define LEFT '4'
#define RIGHT '6'
#define UP  '8'
#define DOWN '2'
#define ENTER '5'

void gotoxy(int x, int y);

int xy[16][16]; // 16 * 16 짜리 오목판을 전역변수로 선언을 합니다.
int x = 1, y = 1, x2 = 2; //

void input(int *p) {
	char c;
	int z = 1; // 그냥 마지막에 break문을 사용하면 될것을 왜 선언을 했는지 모르겟네요
		  // 무한 루프를 빠져나가기 위한 변수입니다.

	while (z) { // 태초 z =1 이니 참이므로 반복이 실행됩니다.

		c = getch(); // char c 변수에 문자를 입력 받습니다.
		switch (c) // define에 제시된 문자만을 취급하므로 다른 문자가 들어간다면 무시하고 루프가 돕니다.
		{
		case RIGHT: {
			++x, x2 += 2; // 화면에 표시된 검은돌이나 하얀돌은 2바이트죠? 따라서
				   // 입력을 위한 x변수와 출력을 위한 x2변수가 필요합니다.
		  // 그러니 RIGHT가 입력되면 x는 1씩 증가하며 x2는 2증가하여 표현합니다.
			if (x >= 15) --x, x2 -= 2; // 만약 오목판을 넘어선다면 입력이 무시가 됩니다.
			gotoxy(x2, y); // 아니라면 커서를 입력한 좌표로 이동합니다.
			break; // 그리고 다시 입력을 받기 위해 swtich문을 빠져 나가며 다시 루트가 됩니다.
		}

		case LEFT: { // RIGHT와 같은 형식입니다.
			--x, x2 -= 2;
			if (x <= 0) ++x, x2 += 2;
			gotoxy(x2, y);
			break;
		}
		case UP: {
			--y;
			if (y <= 0) ++y;
			gotoxy(x2, y);
			break;
		}
		case DOWN: {
			++y;
			if (y >= 15) --y;
			gotoxy(x2, y);
			break;
		}


		case ENTER: { //ENTER가 입력되면 현재 위치를 오목 배열에 저장을 해야겠죠?
			if (xy[y][x] != 0) break; // 이미 오목알이 존재하는지 검사합니다. 있다면 입력이 무시됩니다.
			if (*p == 2) { // 2번사용자 차례 였다면 해당 좌표에 2를 입력합니다.
				xy[y][x] = 2;
			}
			else { // 아니라면 1을 입력합니다.
				xy[y][x] = 1;
				// 이렇게 짠 제가 바보입니다 위 조건문은 xy[y][x] = *p와 동일합니다.
			}
			z = 0; // 입력을 하였으니 순서가 바뀌어야겠죠? z에 0을 대입함으로써 위 반복이 거짓이 되므로
			 // 무한루프를 벗어납니다.
		}
					// 참 간단하죠? 이해가 가셨길 바랍니다.


		}
	}
}

void screen() {

	system("cls"); // 화면 지우기
	int j, k;  // 반복을 위한 변수 선언 c++이라면 굳이 이곳에 선언할 필요는 없겠죠?

	for (j = 0; j < 16; j++) {
		for (k = 0; k < 16; k++) { // 배열의 요소를 하나씩 출력해나갑니다.
			if (xy[j][k] == 1) printf("○");
			else if (xy[j][k] == 2) printf("●");
			else if (xy[j][k] == 0) printf("┼"); // 처음 초기화 하였을 경우 모두 0이므로 완전한 오목판이 되겠죠?
		}

		printf("\n"); // k의 반복이 끝이되면 한줄이 완성됩니다 따라서 줄을 띄웁니다.
	}
	gotoxy(0, 21); // gotoxy는 api함수입니다. 괄호 안의 좌표로 커서를 이동시키는
			   // 역할을 합니다 따라서 좌표는 (0,21)로 이동하여 아래 출력문을 실행합니다.
	printf("UP:8  DOWN:2  LEFT:4  RIGHT:6  ENTER:5");

}


int check(int *p)
{
	int j, sum = 0; // sum은 오목이 종료 되었는지 확인을 위한 변수입니다.

	for (j = -5; j <= 5; j++) { // 현재 x,y의 좌표중 y,x-5부터 y,x+5사이에 오목이 있는지 확인합니다.
		if (x + j <= 0 && x + j >= 16) continue; // 가리키는 y의 좌표가 오목판을 벗어나는지 검사합니다.
		if (xy[y][x + j] == *p) {
			sum++; //가리키는 y의 좌표에 저장된 자료가 *p와 일치하면 증가를 합니다.
			 //*p는 곧 사용자를 뜻합니다 입력시 1번사용자일 경우에는 1을 입력하였으니
	   //연속으로 *p가 5개 나온다면
			if (sum == 5) return 0; //오목이 완성된것입니다. 따라서 게임은 종료되었으니 리턴합니다.
		}
		else sum = 0; // 만약 중간에 다른 숫자가 나와버린다면 sum을 0으로 초기화하며 남은 좌표를
				   // 검사합니다 그리고 sum ==5가 안된다면 다시 실행을 하여 다음 좌표를 검사합니다.

	}

	for (j = -5; j <= 5; j++) { // 위의 반복이 좌우를 검사하였다면 이쪽은 상하를 검사하는군요
		if (y + j <= 0 && y + j >= 16) continue;
		if (xy[y + j][x] == *p) {
			sum++;
			if (sum == 5) return 0;
		}
		else sum = 0;
	}

	for (j = -5; j <= 5; j++) { // 대각선 방향 검사합니다.
		if (y + j <= 0 && y + j >= 16) continue;
		if (x + j <= 0 && x + j >= 16) continue;
		if (xy[y + j][x + j] == *p) {
			sum++;
			if (sum == 5) return 0;
		}
		else sum = 0;
	}
	for (j = -5; j <= 5; j++) { //다른쪽 대각선 방향도 검사를 해야겠죠?
		if (y + j <= 0 && y + j >= 16) continue;
		if (x - j <= 0 && x - j >= 16) continue;
		if (xy[y + j][x - j] == *p) {
			sum++;
			if (sum == 5) return 0;
		}
		else sum = 0;
	}


	return 1; // 위의 반복중에서 sum == 5가 되는것이 없다면 1을 리턴합니다.
}



void main() {
	int a = 1, z = 1;
	int j, k;


	for (j = 0; j < 16; j++) { // 선언한 배열엔 쓰레기값이 있음으로 초기화합니다.
		for (k = 0; k < 6; k++) {
			xy[k][j] = 0;
		}
	}

	screen(); //스크린 함수를 실행합니다.
	while (z) {

		gotoxy(0, 20); // 스크린 함수에서 언급을 했었죠?
		printf("%d 님 번째 차례", a);
		input(&a); // 입력 함수를 확인하세요.
		screen(); // 입력을 받았으니 다시 화면을 뿌려 줍니다.
		z = check(&a); // 오목이 되었는지 확인합니다.위 함수의 설명을 참고하세요
		if (a == 1) a = 2; // 사용자 순서를 바꾸기 위한 조건문입니다.
		else a = 1;


	}
	gotoxy(0, 20); // 누가 승리했는지 검사할 필요는 없겠죠? 종료된 시점에 a값이 승리를 한것입니다!
	printf("%d님의 승리", a); // 그리고 여기서 가장 치명적인 실수를 하는군요.

									  // 오목이 확인된 시점에서 조건문이 한번 더 실행을 하니

									  // 2가 승리하였다면 1번이 승리자로 나오겠군요. 위 조건문 이전에

									  // break문이 반드시 들어가야합니다.

									  // 제가 봐도 어처구니 없군요;;


}

void gotoxy(int x, int y) //api 함수입니다. 씨언어와는 무관하므로 설명을 덧붙이지 않겠습니다.
						   //이 함수는 윈도우api함수이니 다른 운영체제에서는 프로그램이 제대로
		 //실행이 될리는 없겠죠?
{
	COORD Pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}