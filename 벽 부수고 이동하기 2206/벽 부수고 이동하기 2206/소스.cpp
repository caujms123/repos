#include <iostream>
#include <queue>
#include<string>
using namespace std;
#define MAX 10000000
int n, m;
struct offsets {
	short int vert;
	short int horiz;
};
typedef struct dpinfo {
	int dis;
	int dis_wall;
}dpinfo;
typedef struct que {
	short int y;
	short int x;
	short int wall;
	que& operator=(const que& input) { // 대입연산자 오버로딩
		y = input.y;
		x = input.x;
		wall = input.wall;
		return *this;
	}
}que;
short int map[1000][1000];
dpinfo dp[1000][1000];
int main() {
	offsets move[4] = { // 이유는 모르겠는데 전역번수 시 모호하다고 뜸.
	{-1,0}, // 위
	{0,1}, //  오른쪽
	{1,0}, // 아래
	{0,-1},  // 왼쪽
	};
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		string b;
		cin >> b;
		for (int j = 0; j < m; j++) {
			dp[i][j].dis = MAX;
			dp[i][j].dis_wall = MAX;
			map[i][j] = b[j] - '0';
		}
	}
	queue<que> q;
	q.push({ 0, 0, 0 });
	que now;
	dp[0][0] = { 1,1 };
	while (!q.empty()) {
		now = q.front();
		q.pop(); // now(x,y,check)
		for (int i = 0; i < 4; i++) {
			int next_y = now.y + move[i].vert;
			int next_x = now.x + move[i].horiz;
			if ((next_y < 0) || (next_y > n - 1) || (next_x < 0) || (next_x > m - 1)) continue;
			dpinfo dpnow = dp[now.y][now.x];
			dpinfo dpnext = dp[next_y][next_x];
			que next = { short(next_y), short(next_x), now.wall };

			if (now.wall) { //현재 벽을 지난 상태
				if (map[next_y][next_x]) continue; // 벽을 지났는데 다음에 벽이면 패스
				if (dpnext.dis_wall <= (dpnow.dis_wall + 1)) continue; // dis_wall 비교 했을 때 거리가 같거나 더 크면 패스
				q.push(next);
				dp[next.y][next.x].dis_wall = (dpnow.dis_wall + 1);
			}
			else if (!now.wall) { // 현재 벽을 안지난 상태
				if (dpnext.dis <= (dpnow.dis + 1)) continue; // dis_wall 비교 했을 때 거리가 같거나 더 크면 패스
				if (map[next_y][next_x]) { // 현재 0이고 다음이 벽인 경우
					next.wall = 1;
					q.push(next);
					dp[next.y][next.x].dis_wall = (dpnow.dis + 1);
				}
				else {
					q.push(next);
					dp[next.y][next.x].dis = (dpnow.dis + 1);
				}
			}
			if ((dp[n][m].dis == n + m - 1) || (dp[n][m].dis_wall == n + m - 1)) {
				printf("%d", n + m - 1);
				return 0;
			}
		}
	}
	if ((dp[n - 1][m - 1].dis_wall == MAX) && (dp[n - 1][m - 1].dis == MAX)) {
		printf("-1");
		return 0;
	}
	if (dp[n - 1][m - 1].dis <= dp[n - 1][m - 1].dis_wall) printf("%d", dp[n - 1][m - 1].dis);
	else printf("%d", dp[n - 1][m - 1].dis_wall);
	return 0;
}