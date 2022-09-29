#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void addStack(string& s, stack<char>& st) {
	for (int i = 0; i < s.size(); i++) { // ���ڿ� stack�� �߰�
		switch (s[i]) {
		case '{': // ���� ��ȣ stack�� �߰�
			st.push(s[i]);
			break;
		case '}':
			if (st.empty() || st.top() == '}') { //���� ���� ���� ��� stack�� �߰�
				st.push(s[i]);
			}
			else { // ���� ���� ��� �� �� stack���� ����
				st.pop();
			}
			break;
		}
	}
}

void findMin(vector<int>& v, stack<char>& st) { // �ּ� ���� �� ã��
	char top;
	int min = 0;

	while (!st.empty()) { // ���ÿ� ���� �ִ� ���ڿ� �ָ�ŭ �ݺ�
	//������ ������� �ʴٸ�
		top = st.top();
		st.pop();

		if (st.top() == top) { //{{, }} �� ���, 1 ����
			min = min + 1;
			st.pop();
		}
		else if (top == '{' && st.top() == '}') { // }{ �� ���, 2 ����
			min = min + 2;
			st.pop();
		}
	}
	v.push_back(min); //�ּ� ����� �迭�� �ֱ�
}

int main(void) {

	string s;
	stack<char> st;
	vector<int> v;

	while (true) {

		//�Է�
		cin >> s;

		if (s.find("-") != string::npos) { // -�� �� �� �̻� �����ϸ� ���α׷� ����
			break;
		}
		addStack(s, st);

		findMin(v, st);

	}

	//���
	for (int i = 0; i < v.size(); i++) {
		cout << i + 1 << ". " << v[i] << "\n";
	}
}