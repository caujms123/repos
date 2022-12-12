#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef struct a {
	int x;
	int y;
	char d;
}
int solution(char* dirs)
{
	int x = 0, y = 0;
	int len = strlen(dirs);
	a aa[501];
	asf[0].x = 0;
	asf[0].y = 0;
	for (int i = 1; i <= len; i++) {
		if (disr[i] = 'U') {
			if (y == 5) continue;
			y++;
			aa[i].x = x;
			aa[i].y = y;
			aa[i].d = 'U';
		}
		else if (disr[i] = 'D') {
			if (y == -5) continue;
			y--;
			aa[i].x = x;
			aa[i].y = y;
			aa[i].d = 'D';
		}
		else if (disr[i] = 'R') {
			if (x == 5) continue;
			x++;
			aa[i].x = x;
			aa[i].y = y;
			aa[i].d = 'R';
		}
		else if (disr[i] = 'L') {
			if (x == -5) continue;
			x--;
			aa[i].x = x;
			aa[i].y = y;
			aa[i].d = 'L';
		}
	}
	int sol = 0;
	for (int i = 1; i < len; i++) {
		for (int j = i + 1; j <= len; j++) {
			if (aa[i].x == aa[j].x && aa[i].y == aa[j].y &&aa[i].d == aa[j].d) {
				sol++;
			}
			if (aa[i].x == aa[j].x && aa[i].y == (aa[j].y) + 1 && aa[i].d == 'D' && aa[j].d == 'U') {
				sol++;
			}
			if (aa[i].x == aa[j].x && aa[i].y == (aa[j].y) - 1 && aa[i].d == 'U' && aa[j].d == 'D') {
				sol++;
			}
			if (aa[i].x == (aa[j].x) + 1 && aa[i].y == (aa[j].y) && aa[i].d == 'L' && aa[j].d == 'R') {
				sol++;
			}
			if (aa[i].x == (aa[j].x) - 1 && aa[i].y == (aa[j].y) && aa[i].d == 'R' && aa[j].d == 'L') {
				sol++;
			}
		}

	}
	int answer = len - sol;
	return answer;
}