#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(vector<vector<int>> board, vector<int> moves);
int main() {
	vector<vector<int>> board = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
	vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
	for (int i = 0;  i< board.size(); i++) {
		//cout << board.size() - 1 << endl;
		for (int j = 0; j < board[i].size(); j++)
			cout << board[i][j];
		cout << endl;
	}
	int ans = solution(board, moves);
	cout << ans << endl;
}
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> save;

	for (int i = 0; i < moves.size(); i++) {
		int pick = 0;
		int move = moves[i]-1;

		//뽑기
		for (int i = 0; i < board.size(); i++) {
			pick = board[i][move];
			if (pick != 0) { // pick 이 0이 아니라면 board에서 삭제
				board[i][move] = 0;
				break;
			}
			else continue;
		}

		// 함수: 같은 게 있으면 점수 추가 후 삭제, 또는 삽입.
		if (pick == 0) continue;
		else if (save.size() == 0 || save[save.size() - 1] != pick) {
			save.push_back(pick);
		}
		else if (save[save.size() - 1] == pick) {
			answer += 2;
			save.pop_back();
		}
	}

	return answer;
}