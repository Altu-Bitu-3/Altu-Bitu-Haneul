#include <iostream>
#include <vector>
#include <algorithm> //sort 사용

using namespace std;

int main() {

	int T, n;

	cin >> T;//T 입력

	vector<int> result;
	result.assign(T, 0);


	for (int i = 0; i < T; i++) {// Testcase만큼 반복

		//입력 
		int cnt = 0;
		int tmp = 0;

		vector <pair<int, int>> v;
		pair<int, int> p;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> p.first >> p.second;
			v.push_back(p);
		}

		sort(v.begin(), v.end()); //서류 점수로 먼저 정렬

		for (int i = 1; i < n; i++) {
			if (v[i].second > v[tmp].second) { //서류점수 및 면접 점수 모두 앞사람보다 낮을 경우
				cnt++;
			}
			else {
				tmp = i; //면접 점수 높은 순위로 갱신
			}
		}

		result[i] = n - cnt;

	}

	//출력

	for (int i = 0; i < T; i++) {
		cout << result[i] << "\n";
	}
}