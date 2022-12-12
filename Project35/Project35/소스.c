#include<stdio.h>
int main() {
	int n, w, L; 
	int t = 0; // 걸리는 시간
	int a[1000]; // 차량의 개수
	int b = 0; // 다리 위의 차의 무게
	int bb = 0; // 나가는 차의 번호
	int aa = 0;	// 다리 위의 차의 개수
	int tt = 0;	// 들어가는 차의 번호
	int ttt[1000] = { 0 }; // 들어온 차가 나가는 데에 걸리는 시간 계산할 때에 필요한 변수
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
			t += w - ( t - ttt[bb+1] ); //**********a[bb+1]이 나가는 데에 걸리는 시간
			bb++;
			aa--;
			continue;
		}
	}
	printf("%d", t);
}