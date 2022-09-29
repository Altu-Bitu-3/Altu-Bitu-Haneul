#include <iostream>
#include <vector>
#include <algorithm> //sort ���
#include <string>

using namespace std;

bool cmp(const string& a, const string& b) {

	if (a.size() != b.size())
		return a.size() < b.size();

	//���̰� ���ٸ�
	int a_sum = 0;
	int b_sum = 0;

	for (int i = 0; i < a.size(); i++) { //���ڶ�� �� ���
		if ('0' <= a[i] && a[i] <= '9') {
			a_sum += a[i] - '0';
		}
		if ('0' <= b[i] && b[i] <= '9') {
			b_sum += b[i] - '0';
		}
	}

	if (a_sum != b_sum) { // ���� ���� ���� �ʴٸ�
		return a_sum < b_sum; // ���� ���� ���� �ͺ��� ���� ����
	}

	//���� �հ� ���� ��� ���ٸ�
	return a < b; // ������ ����
}


int main() {
	int n;
	vector<string> v;

	//�Է�
	cin >> n;
	v.assign(n, "");

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), cmp);

	//��� 
	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}

}