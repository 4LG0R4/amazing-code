#include<iostream>
#include<algorithm>
using namespace std;
int main() {

	int n, k; // �л��� ��, ���� ����
	int price = 0; // �ּ����� ����
	int student[300000] = { 0 }; // �л��� Ű
	int clothing[300000] = { 0 }; // �л��� Ű ���� 
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> student[i];
		clothing[i - 1] = student[i] - student[i - 1]; // �� ���ϱ�
	}
	sort(clothing, clothing + n - 1); // �����ϱ�
	for (int i = 0; i < n - k; i++) {
		price += clothing[i]; // ���ϱ�
	}
	cout << price;
	return 0;
}