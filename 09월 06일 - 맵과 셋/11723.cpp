#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, x;
	string cmd;
	set<int> s;

	//�Է� 
	cin >> n;

	while (n--) {

		cin >> cmd ;

		if (cmd == "all") { //all
			for (int i = 1; i <= 20; i++) { //s�� {1,2,...,20}���� �ٲ۴�
				s.insert(i);
			}
			continue;
		}

		if (cmd == "empty") { // empty
			s.clear(); //s�� ���������� �ٲ۴�.
			continue;
		}

		cin >> x;

		if (cmd == "add") { //add x
			s.insert(x);
		}
		
		if (cmd == "remove") { //remove x
			s.erase(x);
		}
		
		if (cmd == "check") { // check x
			int cnt = 0;
			for (auto iter = s.begin(); iter != s.end(); iter++) { // S�� x�� ������
				if (*iter == x) {
					cnt++; //cnt ���� 1�� ����
					break;
				}
			}
			cout << cnt <<"\n"; // ���
		}

		if (cmd == "toggle") { //toggle x
			int valid = 0;
			for (auto iter = s.begin(); iter != s.end(); iter++) { // S�� x�� ������
				if (*iter == x) { // cnt���� 1�� �ٲ�
					valid++;
					break;
				}
			}
			if (valid == 0) { // S�� x�� ������
				s.insert(x); // x �߰�
			}
			else { // s�� x�� ������
				s.erase(x); 
			}
		}
	}
}
