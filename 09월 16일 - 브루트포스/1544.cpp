#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int findSameWord(vector<string>& str) {
	string tmp;
	int  sum = 0;

	for (int i = 0; i < str.size(); i++) {

		if (str[i]=="0") //문자열이 없으면
			continue;

		tmp = str[i];

		for (int k = 0; k < str[i].size(); k++) {
			for (int j = i + 1; j < str.size(); j++) {// 같은 단어인지 비교
				if (tmp.size() != str[j].size()) {//길이가 같지 않으면
					continue;
				}


				if (str[j] == tmp) { // 같은 단어면 문자열이 없게 처리
					str[j] = "0";
				}
			}

			//시계방향으로 바꾸기
			tmp+=tmp[0];
			tmp.erase(0,1);

		}
		
	}

	for (int k = 0; k < str.size(); k++) { // 남아있는 단어 개수 구하기
		if (str[k] != "0") { //단어가 남아있으면
			sum++;
		}
	}
	
	return sum;
}

int main() {
	int n;
	string s;

	//입력
	cin >> n;

	vector<string> str;

	for (int i = 0; i < n; i++) {
		cin >> s;
		str.push_back(s);
	}

	//출력
	cout << findSameWord(str);
}