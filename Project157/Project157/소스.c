#include <stdio.h>
const int mod = 1e9 + 7;
int n;
long long s, e, x;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &e, &x); // e ��� , x ����
		long long t = 1, p = 2, q = x - 1; 
		while (q) { //q�� 0�� �� ������
			if (q & 1) t = (t * p) % mod; // t�� p�� ���� �������� t�� ����//q�� 0�� �ƴϸ� 
			p = (p * p) % mod, q /= 2; // p�� ������ �������� p�� ����// pq�� 2�� ������.
		}
		if (x) s = (s + (e * x) % mod * t) % mod; // ����� ������ ���ϰ� ��带 ���� �� t�� ���ϰ� s�� ���ؼ� �������� s�� ����
	}
	printf("%lld", s);
	return 0;
}