#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void addStack(string& s, stack<char>& st) {
	for (int i = 0; i < s.size(); i++) { // 문자열 stack에 추가
		switch (s[i]) {
		case '{': // 여는 괄호 stack에 추가
			st.push(s[i]);
			break;
		case '}':
			if (st.empty() || st.top() == '}') { //쌍이 맞지 않을 경우 stack에 추가
				st.push(s[i]);
			}
			else { // 쌍이 맞을 경우 둘 다 stack에서 제거
				st.pop();
			}
			break;
		}
	}
}

void findMin(vector<int>& v, stack<char>& st) { // 최소 연산 수 찾기
	char top;
	int min = 0;

	while (!st.empty()) { // 스택에 남아 있는 문자열 쌍만큼 반복
	//스택이 비어있지 않다면
		top = st.top();
		st.pop();

		if (st.top() == top) { //{{, }} 일 경우, 1 더함
			min = min + 1;
			st.pop();
		}
		else if (top == '{' && st.top() == '}') { // }{ 일 경우, 2 더함
			min = min + 2;
			st.pop();
		}
	}
	v.push_back(min); //최소 연산수 배열에 넣기
}

int main(void) {

	string s;
	stack<char> st;
	vector<int> v;

	while (true) {

		//입력
		cin >> s;

		if (s.find("-") != string::npos) { // -이 한 개 이상 등장하면 프로그램 종료
			break;
		}
		addStack(s, st);

		findMin(v, st);

	}

	//출력
	for (int i = 0; i < v.size(); i++) {
		cout << i + 1 << ". " << v[i] << "\n";
	}
}