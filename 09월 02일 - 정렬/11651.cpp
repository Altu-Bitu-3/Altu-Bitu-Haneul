#include <iostream>
#include <vector>
#include <algorithm> //sort ���

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {

	if (a.second != b.second) {//y��ǥ�� ���� ������
		return a.second < b.second;
	}

	//y��ǥ�� ������
	return a.first < b.first; // x��ǥ �����ϴ� ������ ����
}

int main() {
	vector <pair<int, int>> v;

	int n;
	pair<int, int> p;

	//�Է�

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p.first >> p.second;
		v.push_back(p);
	}

	sort(v.begin(), v.end(), cmp);

	//���
	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}