#include <iostream>
#include <stdlib.h>

#define MAX 300

using namespace std;

extern int makeBlock(int module[][4][4]);

int main(void)
{
	static int module[MAX][4][4];

	srand(3); // 3 will be changed

	for (int tc = 1; tc <= 10; tc++)
	{
		for (int c = 0; c < MAX; c++)
		{
			int base = 1 + (rand() % 6);
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					module[c][y][x] = base + (rand() % 3);
				}
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2; k++) {
				module[0][j][k] = 1;
				module[1][j][k] = 2;
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 2; k < 4; k++) {
				module[0][j][k] = 2;
				module[1][j][k] = 1;
			}
		}
		cout << "#" << tc << " " << makeBlock(module) << endl;
	}

	return 0;
}