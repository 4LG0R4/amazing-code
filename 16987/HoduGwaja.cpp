#include<iostream>
#include<algorithm>
#define Max 8
using namespace std;

int N;
int Eggs = 0;
int attack[Max], health[Max];
void BF(int number)
{
	if (number >= N) { // ����� �� ����?
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			if (health[i] <= 0) cnt++; // ���� ��� ����
		}
		if (Eggs < cnt) Eggs = cnt;  //���� ū ��� ã��
		return;
	}
	if (health[number] <= 0) { // ����� ������ ��
		BF(number + 1);  //���� ������� ���� ��
	}
	else {
		bool f = false; //����� ģ ����
		for (int i = 0; i < N; ++i) {
			if (health[i] <= 0 || i == number) {
				// ����� ĥ �� ���� ����� �� -> ����� �����ų� ���� ����� ��
				continue;
			}
			//����� ��
			health[i] = health[i] - attack[number];
			health[number] = health[number] - attack[i];
			f = true;
			// �����ܰ�� �Ѿ
			BF(number + 1);
			//���󺹱�
			health[i] = health[i] + attack[number];
			health[number] = health[number] + attack[i];
		}
		if (f == false) {
			BF(number + 1); // ����� �ƿ� �� �� ���� ��Ȳ�϶� �����ܰ�� �ٷ� �Ѿ(N�� 1�� ��)
		}
	}
	return;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> health[i] >> attack[i];
	}
	BF(0);
	cout << Eggs;
	return 0;
}