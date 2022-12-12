#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[5001] = { 0 };
bool memo[800001];
int main() {
	int n, w;
	scanf("%d %d", &w, &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] > w) break;
			if (memo[w - arr[i] - arr[j]]) {
				printf("YES");
				return 0;
			}
		}
		for (int k = 0; k < i; k++) {
			memo[arr[k] + arr[i]] = 1;
		}
	}
	printf("NO");
	return 0;
