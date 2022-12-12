#include <stdio.h>
const int mod = 1e9 + 7;
int n;
long long s, e, x;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &e, &x); // e 계수 , x 지수
		long long t = 1, p = 2, q = x - 1; 
		while (q) { //q가 0이 될 때까지
			if (q & 1) t = (t * p) % mod; // t와 p의 곱의 나머지를 t에 저장//q가 0이 아니면 
			p = (p * p) % mod, q /= 2; // p의 제곱의 나머지를 p에 저장// pq를 2로 나눈다.
		}
		if (x) s = (s + (e * x) % mod * t) % mod; // 계수와 지수를 곱하고 모드를 구한 후 t를 곱하고 s를 더해서 나눈다음 s에 저장
	}
	printf("%lld", s);
	return 0;
}