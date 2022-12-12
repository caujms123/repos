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
	//if (top == -1) 오류 나중에 기록하기??
	return stack[top--];
}
void push(element position) {
	//if (stack_full()) 오류뜸 고려 안해도 된다.
	top++;
	stack[top] = position;
}
int main() {
	path();
}
void path(void) {
	int i, row, col, nextRow, nextCol, dir, found = 0;
	element position;
	top = 0;
	dir = 1;
	stack[0].row = 0; stack[0].col = 0;
	maze[0][0] = 1;
	while (top > -1 && !found) {
		for (int i = 0; i < numRow; i++) {			////
			for (int j = 0; j < numCol; j++) {
				printf("%d ", maze[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		position = pop();
		row = position.row; col = position.col;
		//printf("%d %d\n", row, col);
		for (int i = 0;i<10;i++) {
			printf("%d %d\n", stack[i].row, stack[i].col);
		}
		dir = 0;
		while (dir < 8 && !found) {
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;
			if (!maze[nextRow][nextCol]&&(-1< nextRow && nextRow < numRow)&&(-1 < nextCol && nextCol < numCol)) {
				push(position); // 스택에 현재 위치 push
				row = nextRow; col = nextCol; dir = 0;
				maze[row][col] = 1; //mark 대신에 maze를 1로 만든다.
				if (row == numRow - 1 && col == numCol - 1) { // 이동 후 도착 체크하는	것으로 바꿈.
					found = 1;
				}
			}
			else ++dir;
		}
	}
	//printf("%d", found); //체크용
	if (found) {
		printf("The path is: \n");
		printf("row col\n");
		for (i = 0; i <= top; i++)
			printf("%2d%5d", stack[i].row, stack[i].col);
		printf("%2d%5d\n", row, col);
		printf("%2d%5d\n", numRow,numCol);
	}
	else
	{
		printf("The maze does not have a path\n");
	}
}