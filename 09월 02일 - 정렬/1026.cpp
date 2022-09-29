#include <iostream>
#include <vector>
#include <algorithm> //sort 사용

using namespace std;


int main() {

	int n, tmp_n;
	vector<int> arr1;
	vector<int> arr2;
	int sum = 0;
	//입력 

	cin >> n;

	arr1.assign(n, 0);
	arr2.assign(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}

	sort(arr2.begin(), arr2.end(), greater<>()); //arr2 내림차순 정렬
	sort(arr1.begin(), arr1.end()); //arr1 오름차순 정렬


	//최솟값 구하기
	for (int i = 0; i < n; i++) {
		sum += arr1[i] * arr2[i];
	}

	//출력
	cout << sum;
}