#include<iostream>
#include<algorithm>
#define Max 8
using namespace std;

int N;
int Eggs = 0;
int attack[Max], health[Max];
void BF(int number)
{
	if (number >= N) { // 계란을 다 깼나?
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			if (health[i] <= 0) cnt++; // 깨진 계란 정산
		}
		if (Eggs < cnt) Eggs = cnt;  //가장 큰 경우 찾기
		return;
	}
	if (health[number] <= 0) { // 계란이 깨졌을 때
		BF(number + 1);  //다음 계란으로 가게 됨
	}
	else {
		bool f = false; //계란을 친 여부
		for (int i = 0; i < N; ++i) {
			if (health[i] <= 0 || i == number) {
				// 계란을 칠 수 없는 경우의 수 -> 계란이 깨졌거나 같은 계란일 때
				continue;
			}
			//계란을 깸
			health[i] = health[i] - attack[number];
			health[number] = health[number] - attack[i];
			f = true;
			// 다음단계로 넘어감
			BF(number + 1);
			//원상복귀
			health[i] = health[i] + attack[number];
			health[number] = health[number] + attack[i];
		}
		if (f == false) {
			BF(number + 1); // 계란을 아예 깰 수 없는 상황일때 다음단계로 바로 넘어감(N이 1일 때)
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