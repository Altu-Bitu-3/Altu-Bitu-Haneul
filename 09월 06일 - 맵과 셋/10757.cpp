#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string n1, n2;
	vector <int> result;


	//입력
	cin >> n1 >> n2;

	if (n1.size() < n2.size()) { // n2에 작은 수 놓기
		swap(n1, n2);
	}

	//뒤에서부터 계산하기 위해 배열 뒤집음 
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	for (int i = 0; i < n2.size(); i++) { //n2 길이 만큼 반복
		int a = n1[i] - '0'; 
		int b = n2[i] - '0'; 
		result.push_back(a + b); // 자릿수대로 더해서 추가
	}

	for (int i = 0; i < n1.size() - n2.size(); i++) { // 남은 자릿수 추가
		result.push_back(n1[n2.size()+i] - '0');
	}


	for (int i = 0; i < result.size(); i++) {
		if (result[i] >= 10) {// 더한 값이 10이상이면 올림하기
			result[i] -= 10;
			if (i == result.size() - 1) { // 마지막 자릿수일 경우 자릿수 추가
				result.push_back(1);
				break;
			}
			result[i + 1] += 1;
		}
	}

	//출력 

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i];
	}
}