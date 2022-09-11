#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, x;
	string cmd;
	set<int> s;

	//입력 
	cin >> n;

	while (n--) {

		cin >> cmd ;

		if (cmd == "all") { //all
			for (int i = 1; i <= 20; i++) { //s를 {1,2,...,20}으로 바꾼다
				s.insert(i);
			}
			continue;
		}

		if (cmd == "empty") { // empty
			s.clear(); //s를 공집합으로 바꾼다.
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
			for (auto iter = s.begin(); iter != s.end(); iter++) { // S에 x가 있으면
				if (*iter == x) {
					cnt++; //cnt 값을 1로 변경
					break;
				}
			}
			cout << cnt <<"\n"; // 출력
		}

		if (cmd == "toggle") { //toggle x
			int valid = 0;
			for (auto iter = s.begin(); iter != s.end(); iter++) { // S에 x가 있으면
				if (*iter == x) { // cnt값을 1로 바꿈
					valid++;
					break;
				}
			}
			if (valid == 0) { // S에 x가 없으면
				s.insert(x); // x 추가
			}
			else { // s에 x가 없으면
				s.erase(x); 
			}
		}
	}
}
