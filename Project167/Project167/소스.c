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
		row = position.row; col = position.col; // ���� ��ġ ����
		dir = 0; //��������
		while (dir < 8 && !found) {
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;
			if (!maze[nextRow][nextCol] && (-1 < nextRow && nextRow < numRow) && (-1 < nextCol && nextCol < numCol)) { // �ش� �������� �̵� ������ ��
				push(position); // ���ÿ� ���� ��ġ push (������ ���� ���ÿ� �����Ѵ�.)
				row = nextRow; col = nextCol; dir = 0; //(���ο� ��ġ ����,���� 0���� �ʱ�ȭ)
				position.row = row; position.col = col; //(���ο� ���� ��ġ ����)
				maze[row][col] = 1; //mark ��ſ� maze�� 1�� �����.
				if (position.row == numRow - 1 && position.col == numCol - 1) { // ���� ��ġ��ǥ�� �ⱸ��ǥ�� ���������� Ȯ���ϴ� ������ �ٲ�.
					found = 1;
				}
			}
			else ++dir; // �ش� �������� �̵� �Ұ����� ��
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