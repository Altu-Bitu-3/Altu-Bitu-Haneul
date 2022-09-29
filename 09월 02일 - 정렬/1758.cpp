#include <iostream>
#include <vector>
#include <algorithm> //sort 사용

using namespace std;

int main() {

	int n;
	int tip_cnt;
	long long tip_sum = 0;
	vector<int> tip;


	//입력
	cin >> n;
	tip.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> tip[i];
	}

	sort(tip.begin(), tip.end(), greater<>());

	for (int i = 0; i < tip.size(); i++) { //등수별 tip 계산
		tip_cnt = tip[i] - i;
		if (tip_cnt > 0) { //tip 계산한 결과가 음수라면 계산하지 않음
			tip_sum += tip_cnt;
		}
	}

	//출력
	cout << tip_sum << "\n";

}