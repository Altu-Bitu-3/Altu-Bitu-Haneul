#include <iostream>
#include <vector>
#include <algorithm> //sort 사용

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {

	if (a.second != b.second) {//y좌표가 같지 않으면
		return a.second < b.second;
	}

	//y좌표가 같으면
	return a.first < b.first; // x좌표 증가하는 순서로 정렬
}

int main() {
	vector <pair<int, int>> v;

	int n;
	pair<int, int> p;

	//입력

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p.first >> p.second;
		v.push_back(p);
	}

	sort(v.begin(), v.end(), cmp);

	//출력
	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}