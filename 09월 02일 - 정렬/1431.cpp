#include <iostream>
#include <vector>
#include <algorithm> //sort 사용
#include <string>

using namespace std;

bool cmp(const string& a, const string& b) {

	if (a.size() != b.size())
		return a.size() < b.size();

	//길이가 같다면
	int a_sum = 0;
	int b_sum = 0;

	for (int i = 0; i < a.size(); i++) { //숫자라면 합 계산
		if ('0' <= a[i] && a[i] <= '9') {
			a_sum += a[i] - '0';
		}
		if ('0' <= b[i] && b[i] <= '9') {
			b_sum += b[i] - '0';
		}
	}

	if (a_sum != b_sum) { // 숫자 합이 같지 않다면
		return a_sum < b_sum; // 숫자 합이 작은 것부터 먼저 정렬
	}

	//숫자 합과 길이 모두 같다면
	return a < b; // 사전식 정렬
}


int main() {
	int n;
	vector<string> v;

	//입력
	cin >> n;
	v.assign(n, "");

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), cmp);

	//출력 
	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}

}