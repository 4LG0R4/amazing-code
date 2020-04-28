#include <stdio.h>

int main() {
	long long int i = 0, min, max, tmp, cnt = 0;

	scanf("%lld %lld", &min, &max);
	
	if (min > max) {
		tmp = max;
		max = min;
		min = tmp;
	}
	/*
	for (i = min; i >= 1; i--) {
		if (!(max % i) && !(min % i)) {
			printf("%lld %lld, %lld\n", max / i, min / i, i);
			cnt = i;
			break;
		}
	}
	*/

	while (min % max) {
		tmp = min;
		min = max;
		max = tmp % max;
		printf("%lld %lld\n", min, max);
	}

	while (max--)
		printf("1");

	return 0;
}