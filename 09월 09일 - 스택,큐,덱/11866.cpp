#include <iostream>
#include <queue>
#include <vector>

using namespace std;



int main() {
	int n, k;
	queue<int> q;
	vector<int> v;


	//�Է�
	cin >> n >> k;

	for (int i = 1; i <= n; i++) { //q�� n������ ���� ����
		q.push(i);
	}

	while (q.size() != 1) { //q�� ���Ұ� �ϳ� ���� ���� ������
		for (int i = 0; i < k - 1; i++) { // k-1�� ��ŭ �տ� �ִ� ���� �ڷ� ������
			q.push(q.front());
			q.pop();
		}
		//k��°�� �ش��ϴ� ���� ����
		v.push_back(q.front());
		q.pop();
	}

	v.push_back(q.front()); // ������ ���� ���� �迭�� �־��ֱ�



	//���
	cout << "<";
	for (int i = 0; i < v.size() - 1; i++) {
		cout << v[i] << ", ";
	}
	cout << v[n - 1] << ">";
}