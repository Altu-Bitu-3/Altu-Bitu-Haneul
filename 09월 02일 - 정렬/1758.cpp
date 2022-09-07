#include <iostream>
#include <vector>
#include <algorithm> //sort ���

using namespace std;

int main() {

	int n;
	int tip_cnt;
	long long tip_sum = 0;
	vector<int> tip;


	//�Է�
	cin >> n;
	tip.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> tip[i];
	}

	sort(tip.begin(), tip.end(), greater<>());

	for (int i = 0; i < tip.size(); i++) { //����� tip ���
		tip_cnt = tip[i] - i;
		if (tip_cnt > 0) { //tip ����� ����� ������� ������� ����
			tip_sum += tip_cnt;
		}
	}

	//���
	cout << tip_sum << "\n";

}