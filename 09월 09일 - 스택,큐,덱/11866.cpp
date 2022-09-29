#include <iostream>
#include <queue>
#include <vector>

using namespace std;



int main() {
	int n, k;
	queue<int> q;
	vector<int> v;


	//입력
	cin >> n >> k;

	for (int i = 1; i <= n; i++) { //q에 n번까지 원소 삽입
		q.push(i);
	}

	while (q.size() != 1) { //q에 원소가 하나 남아 있을 때까지
		for (int i = 0; i < k - 1; i++) { // k-1번 만큼 앞에 있는 원소 뒤로 보내기
			q.push(q.front());
			q.pop();
		}
		//k번째에 해당하는 원소 제거
		v.push_back(q.front());
		q.pop();
	}

	v.push_back(q.front()); // 마지막 남은 원소 배열에 넣어주기



	//출력
	cout << "<";
	for (int i = 0; i < v.size() - 1; i++) {
		cout << v[i] << ", ";
	}
	cout << v[n - 1] << ">";
}