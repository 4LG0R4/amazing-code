#include<iostream>
#include<algorithm>
using namespace std;
int main() {

	int n, k; // 학생의 수, 조의 개수
	int price = 0; // 최소한의 가격
	int student[300000] = { 0 }; // 학생의 키
	int clothing[300000] = { 0 }; // 학생의 키 범위 
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> student[i];
		clothing[i - 1] = student[i] - student[i - 1]; // 차 구하기
	}
	sort(clothing, clothing + n - 1); // 정렬하기
	for (int i = 0; i < n - k; i++) {
		price += clothing[i]; // 더하기
	}
	cout << price;
	return 0;
}