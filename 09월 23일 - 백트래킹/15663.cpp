#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;// n,m의 범위의 최대

int n, m;
vector<int> number;
vector<int> seq(SIZE);
vector<int> check(SIZE);


void backtracking(int cnt) { // 수열 인덱스 -> cnt
	//기저조건
	if (cnt == m) { //m개의 수열을 만들었다면 출력
		for (int i = 0; i < cnt; i++) {
			cout << seq[i] << " ";
		}
		cout << "\n";
		return;
	}

	// 수열의 마지막 값이 중복되면 중복 수열이므로
	int last = 0; // seq 항의 마지막 값

	for (int i = 0; i < n; i++) {

		if (!check[i]&& number[i] != last) { //check 안되어 있고, 마지막 항과 같은 수가 아니라면
			seq[cnt] = number[i]; // 첫번째 인덱스에 number 값 입력
			last = seq[cnt];
			check[i] = true;
			backtracking(cnt + 1); // 다음 인덱스 호출
			check[i] = false; // 원상태 복귀
		}
	}
}

int main() {
	int num;

	//입력
	cin >> n >> m;

	for (int i = 0; i < n; i++) { // number에 n개의 수 집어 넣기
		cin >> num;
		number.push_back(num);
	}
	
	// number 정렬
	sort(number.begin(), number.end());
	//연산
	backtracking(0);

	return 0;
}