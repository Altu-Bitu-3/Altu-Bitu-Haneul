#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;
int n;
vector<vector<int>>w(SIZE, vector<int>(SIZE, 0)); // 행렬 입력
vector<int>check(SIZE); 
vector<int>route(SIZE);
vector<int>result;

void findMin() { //최소 비용 계산
	int min = result[0];

	for (int i = 1; i < result.size(); i++) { 
		if (min > result[i]) {
			min = result[i];
		}
	}
	cout << min;
}

void backtracking(int cnt) {// cnt -> 거쳐간 도시 수
	int sum = 0; 
	//기저조건
	if (cnt == n) { // 만약 도시를 다 돌았다면
		for (int i = 1; i < n; i++) { // 비용 계산
			if (w[route[i - 1]][route[i]] == 0) { // 갈 수 있는 길이 없다면 그 route 버림
				break;
			}
			sum += w[route[i - 1]][route[i]];

			if (i == n - 1 && w[route[n - 1]][route[0]] != 0) { // 마지막 도시에서 원래 도시로 돌아갈 때 갈 수 있는 길이 있다면 그 비용까지 더함
				sum += w[route[n - 1]][route[0]];
				result.push_back(sum);
			}
		}
	}

	for (int i = 1; i < n; i++) { // 첫 값을 고정시켰으므로 1부터 비교하며 길의 경우의 수를 만들어나감
		if (!check[i]) { 
			route[cnt] = i;
			check[i] = true;
			backtracking(cnt + 1);
			check[i] = false;
		}
	}
}

int main() {
	//입력
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	//연산
	check[0] = true;
	route[0] = 0; // 원순열이므로 첫번째 값을 고정시킨다.
	backtracking(1);
	findMin();

	return 0;
}