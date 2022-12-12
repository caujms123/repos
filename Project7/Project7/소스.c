# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	
	int g = 0;
	int h = 0;
	long long e = 0;
	long long count[10] = { 0, };
	long long d[10] = { 0, };
	long long f ;   // 방번호 f
	scanf("%lld", &f);

	for (long long i = 1; i <= 100000; i *= 10, h++) {               //555            5 5 5 -1 -1 -1
		if (f >= i)
			d[h] = (f % (i * 10)) / i;          //
		else d[h] = -1;
	}
	for (int j = 0; j <= 6; j++) {
		for (long long z = 0; z <= 9; z++) {        //     z++ --> 빠져나올 때 count[10] 이 생김. count 
			if (d[j] == z)
				count[z]++;                         //    count [5]=3 나머지는 0
		}
	}
	count[0]--;
	long long y = count[6] + count[9];
	for (int u = 0; u <= 9; u++) {
		for (int x = 0; x <= 9; x++) {
			if (count[u] >= count[x]) {
				g++;
			}
		}
		if (g == 10 && u != 6 && u != 9)
		{
			e = count[u];
			break;
		}
		else if ((g == 10 && u == 6) || (g==10 && u == 9)) {
			if ((y % 2) == 0){
				e = y / 2;
			}
			else if ((y % 2)== 1)
				e = (y / 2) +1;
		}
		g = 0;
	}
	if (f == 0)		printf("%d",1);
	else printf("%lld", e);
	return 0;
}
//  96969