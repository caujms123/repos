#include<stdio.h>
int main() {
	int n, w, L; 
	int t = 0; // �ɸ��� �ð�
	int a[1000]; // ������ ����
	int b = 0; // �ٸ� ���� ���� ����
	int bb = 0; // ������ ���� ��ȣ
	int aa = 0;	// �ٸ� ���� ���� ����
	int tt = 0;	// ���� ���� ��ȣ
	int ttt[1000] = { 0 }; // ���� ���� ������ ���� �ɸ��� �ð� ����� ���� �ʿ��� ����
	scanf("%d %d %d", &n, &w, &L);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	while(1){
		if (b + a[tt] <= L && aa + 1 <= w) {
			if (tt == n - 1) {
				t += w + 1;
				break;
			}
			b += a[tt];
			t++;
			aa++;
			ttt[tt] = t;
			tt++;
			continue;
		}
		if (aa == w) {
			b = b - a[bb];
			t++;
			bb++;
			aa--;
			continue;
		}
		else if (b+a[tt] > L) {
			b = b - a[bb];
			t += w - ( t - ttt[bb+1] ); //**********a[bb+1]�� ������ ���� �ɸ��� �ð�
			bb++;
			aa--;
			continue;
		}
	}
	printf("%d", t);
}