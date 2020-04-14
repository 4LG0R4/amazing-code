#include <stdio.h>
#define TRUE 1
#define FALSE 0

int isprime(int n) {							// �Ҽ��� �Ǻ��� ���ƿ�
	if (n == 1) {
		return FALSE;							// 1�� �Ҽ��� �ƴϹǷ� �� �ٷ� FALSE�� ��ȯ
	}
	for (int i = 2; i < n; i++)	{				// �Ҽ� �Ǻ�
		if (n % i == 0) {
			return FALSE;						// �Ҽ��� �ƴϸ� FALSE�� ��ȯ
		}
	}
	return TRUE;								// �Ҽ��� TRUE�� ��ȯ
}

int main() {
	int from, to, i, j, count = 0;
	int res[100001] = {0, };

	scanf("%d %d", &from, &to);
	for (i = 2; i <= to; i++) {
		if (isprime(i)) {						// ���� i�� �Ҽ����
			res[i] = 1;							// �Ҽ��� ���μ��� 1���̹Ƿ� 1�� �־���
		}
		else if (i % 2 == 0) {					// ���� i�� �Ҽ��� �ƴ� ¦�����
			res[i] = res[i / 2] + 1;			// i�� ���μ��� ������ �ش� ¦���� ���μ��� ���� + 1�̱⿡ �־���
		}
		else {									// ���� i�� �Ҽ��� �ƴ� Ȧ�����
			for (j = (i/3)%2 ? i/3 : (i/3)+1; j >= 3; j -= 2) {		// i/3���� Ȧ���� ���ʴ�� ��������
			// for (j = 3; j < i/3; j++) {
			// for (j = i-2; j >= 3; j -= 2) {
				if (i % j == 0) {				// i�� ���� Ȧ���� ������ �������� ������ ���µ�
					res[i] = res[j] + 1;		// �׷��ٸ� i�� ���μ��� ������ �ش� Ȧ���� ���μ��� ���� + 1��
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