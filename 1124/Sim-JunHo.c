#include <stdio.h>
#define TRUE 1
#define FALSE 0

int isprime(int n) {							// 소수를 판별해 보아요
	if (n == 1) {
		return FALSE;							// 1은 소수가 아니므로 걍 바로 FALSE를 반환
	}
	for (int i = 2; i < n; i++)	{				// 소수 판별
		if (n % i == 0) {
			return FALSE;						// 소수가 아니면 FALSE를 반환
		}
	}
	return TRUE;								// 소수면 TRUE를 반환
}

int main() {
	int from, to, i, j, count = 0;
	int res[100001] = {0, };

	scanf("%d %d", &from, &to);
	for (i = 2; i <= to; i++) {
		if (isprime(i)) {						// 만약 i가 소수라면
			res[i] = 1;							// 소수의 소인수는 1개이므로 1을 넣어줌
		}
		else if (i % 2 == 0) {					// 만약 i가 소수가 아닌 짝수라면
			res[i] = res[i / 2] + 1;			// i의 소인수의 갯수는 해당 짝수의 소인수의 갯수 + 1이기에 넣어줌
		}
		else {									// 만약 i가 소수가 아닌 홀수라면
			for (j = (i/3)%2 ? i/3 : (i/3)+1; j >= 3; j -= 2) {		// i/3부터 홀수를 차례대로 내려가며
			// for (j = 3; j < i/3; j++) {
			// for (j = i-2; j >= 3; j -= 2) {
				if (i % j == 0) {				// i가 무슨 홀수로 나뉘어 떨어지는 순간이 오는데
					res[i] = res[j] + 1;		// 그렇다면 i의 소인수의 갯수는 해당 홀수의 소인수의 갯수 + 1임
					break;
				}
			}
		}
	}

	for (i = from; i <= to; i++) {
		if (isprime(res[i]))
			count++;
	}

	printf("%d", count);

	return 0;
}