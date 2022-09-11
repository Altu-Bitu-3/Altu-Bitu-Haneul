#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string n1, n2;
	vector <int> result;


	//�Է�
	cin >> n1 >> n2;

	if (n1.size() < n2.size()) { // n2�� ���� �� ����
		swap(n1, n2);
	}

	//�ڿ������� ����ϱ� ���� �迭 ������ 
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	for (int i = 0; i < n2.size(); i++) { //n2 ���� ��ŭ �ݺ�
		int a = n1[i] - '0'; 
		int b = n2[i] - '0'; 
		result.push_back(a + b); // �ڸ������ ���ؼ� �߰�
	}

	for (int i = 0; i < n1.size() - n2.size(); i++) { // ���� �ڸ��� �߰�
		result.push_back(n1[n2.size()+i] - '0');
	}


	for (int i = 0; i < result.size(); i++) {
		if (result[i] >= 10) {// ���� ���� 10�̻��̸� �ø��ϱ�
			result[i] -= 10;
			if (i == result.size() - 1) { // ������ �ڸ����� ��� �ڸ��� �߰�
				result.push_back(1);
				break;
			}
			result[i + 1] += 1;
		}
	}

	//��� 

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i];
	}
}