#include <iostream>

using namespace std;



int main() {
	int r, b,l,w, num, min = 2000000;

	//�Է� 
	cin >> r >> b;

	num = r + b; //Ÿ�� �� ���ϱ�

	for (int i = 1; i <= num; i++) {
		//���̿� ���� ����
		w = i;
		l = num / i;
		
		if (r == (((w - 2) + (l - 2)) * 2) + 4 && b == ((w - 2) * (l - 2))) {
			break;
		}
		
	}

	//���
	cout << l << " " << w;


}