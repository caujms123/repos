#include<stdio.h>
#define numRow 10
#define numCol 10
#define stack_size 100
int maze[numRow][numCol] = {
{ 0,0,1,0,1,1,1,0,1,0 },
{ 1,0,0,1,1,1,0,1,0,1 },
{ 1,1,0,1,1,0,1,0,1,1 },
{ 0,0,1,0,1,1,1,0,0,0 },
{ 0,1,1,0,1,0,1,0,1,0 },
{ 1,0,1,1,1,1,0,0,1,0 },
{ 1,1,0,1,0,1,0,0,1,0 },
{ 1,0,0,0,1,0,1,0,0,0 },
{ 0,1,0,1,1,1,0,1,1,0 },
{ 1,0,0,1,1,1,0,0,0,0 }
};
int top = -1;
void path(void);
typedef struct {
	short int row;
	short int col;
}element;
element stack[stack_size];
typedef struct {
	short int vert;
	short int horiz;
}offsets;
offsets move[8] = {
	{-1,0},
	{-1,1},
	{0,1},
	{1,1},
	{1,0},
	{1,-1},
	{0,-1},
	{-1,-1},
};
element pop(void) {
	return stack[top--];
}
void push(element position) {
	top++;
	stack[top] = position;
}
int main(void) {
	path();
}
void path(void) {
	int i, row, col, nextRow, nextCol, dir, found = 0;
	element position;
	stack[0].row = 0; stack[0].col = 0;
	top = 0;
	maze[0][0] = 1;
	while (top > -1 && !found) {
		position = pop();
		row = position.row; col = position.col; // 현재 위치 저장
		dir = 0; //방향정보
		while (dir < 8 && !found) {
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;
			if (!maze[nextRow][nextCol] && (-1 < nextRow && nextRow < numRow) && (-1 < nextCol && nextCol < numCol)) { // 해당 방향으로 이동 가능할 때
				push(position); // 스택에 현재 위치 push (지나간 길을 스택에 저장한다.)
				row = nextRow; col = nextCol; dir = 0; //(새로운 위치 갱신,방향 0으로 초기화)
				position.row = row; position.col = col; //(새로운 현재 위치 저장)
				maze[row][col] = 1; //mark 대신에 maze를 1로 만든다.
				if (position.row == numRow - 1 && position.col == numCol - 1) { // 현재 위치좌표가 출구좌표와 동일한지를 확인하는 것으로 바꿈.
					found = 1;
				}
			}
			else ++dir; // 해당 방향으로 이동 불가능할 때
		}
	}
	if (found) {
		printf("The path is: \n");
		printf("row  col\n");
		for (i = 0; i <= top; i++)
			printf("%2d%5d\n", stack[i].row, stack[i].col);
		printf("%2d%5d\n", position.row, position.col);
	}
	else
	{
		printf("The maze does not have a path\n");
	}
}