#include <iostream>

using namespace std;



int main() {
	int r, b,l,w, num, min = 2000000;

	//입력 
	cin >> r >> b;

	num = r + b; //타일 수 구하기

	for (int i = 1; i <= num; i++) {
		//길이와 넓이 설정
		w = i;
		l = num / i;
		
		if (r == (((w - 2) + (l - 2)) * 2) + 4 && b == ((w - 2) * (l - 2))) {
			break;
		}
		
	}

	//출력
	cout << l << " " << w;


}