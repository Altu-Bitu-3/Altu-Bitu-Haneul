#include <iostream>
#include <vector>
#include <algorithm> //sort ���

using namespace std;

int main() {

	int T, n;

	cin >> T;//T �Է�

	vector<int> result;
	result.assign(T, 0);


	for (int i = 0; i < T; i++) {// Testcase��ŭ �ݺ�

		//�Է� 
		int cnt = 0;
		int tmp = 0;

		vector <pair<int, int>> v;
		pair<int, int> p;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> p.first >> p.second;
			v.push_back(p);
		}

		sort(v.begin(), v.end()); //���� ������ ���� ����

		for (int i = 1; i < n; i++) {
			if (v[i].second > v[tmp].second) { //�������� �� ���� ���� ��� �ջ������ ���� ���
				cnt++;
			}
			else {
				tmp = i; //���� ���� ���� ������ ����
			}
		}

		result[i] = n - cnt;

	}

	//���

	for (int i = 0; i < T; i++) {
		cout << result[i] << "\n";
	}
}