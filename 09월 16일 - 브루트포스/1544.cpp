#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int findSameWord(vector<string>& str) {
	string tmp;
	int  sum = 0;

	for (int i = 0; i < str.size(); i++) {

		if (str[i]=="0") //���ڿ��� ������
			continue;

		tmp = str[i];

		for (int k = 0; k < str[i].size(); k++) {
			for (int j = i + 1; j < str.size(); j++) {// ���� �ܾ����� ��
				if (tmp.size() != str[j].size()) {//���̰� ���� ������
					continue;
				}


				if (str[j] == tmp) { // ���� �ܾ�� ���ڿ��� ���� ó��
					str[j] = "0";
				}
			}

			//�ð�������� �ٲٱ�
			tmp+=tmp[0];
			tmp.erase(0,1);

		}
		
	}

	for (int k = 0; k < str.size(); k++) { // �����ִ� �ܾ� ���� ���ϱ�
		if (str[k] != "0") { //�ܾ ����������
			sum++;
		}
	}
	
	return sum;
}

int main() {
	int n;
	string s;

	//�Է�
	cin >> n;

	vector<string> str;

	for (int i = 0; i < n; i++) {
		cin >> s;
		str.push_back(s);
	}

	//���
	cout << findSameWord(str);
}