# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	long long a, b, c;
	int h = 0;
	long long d[9] = { 0, };
	scanf("%lld %lld %lld", &a, &b, &c);
	long long f = a * b * c;

	for (long long i = 1, h = 0; i <= 100000000 ; i * 10, h++) {
		if (f >= i)
			d[h] = (f % (i * 10)) / i;
	}
	for (int j = 0; j <= 9; j++) {
		printf("%lld \n", d[j]);
	}
	return 0; 
}



// a*b*c =30230    30230 /10000 ==> 3 몫 나머지 230
        //           30230 %10000 / 1000  몫0 나머지 230
      //                 230/ 100           2
	//				   범위 1000000< a*b*c < 1000000000