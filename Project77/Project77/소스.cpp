# include<iostream>
# include<algorithm>
# include<string>
using namespace std;
pair<int, string>  a[100000];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char b[101];
		scanf("%d", &a[i].first);
		scanf("%s", b);
		a[i].second = b;
	}
	stable_sort(a, a + N);
	for(int i=0;i<N;i++)
		printf("%d %s\n", a[i].first, &a[i].second);
}