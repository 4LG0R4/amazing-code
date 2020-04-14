#include <stdio.h>
#include <string.h>
int arr[2000001], a;
int fro = 0, rear = 0;
void push() {
	scanf("%d", &a);
	arr[rear] = a;
	rear++;
}
void pop() {
	if (rear - fro> 0) {
		printf("%d\n", arr[fro]);
		fro++;
	}
	else {
		printf("-1\n");
	}
}
void size() {
	printf("%d\n", rear - fro);
}
void empty() {
	if (rear - fro > 0) {
		printf("0\n");
	}
	else {
		printf("1\n");
	}
}
void front() {
	if (rear - fro > 0) {
		printf("%d\n", arr[fro]);
	}
	else {
		printf("-1\n");
	}
}
void back() {
	if (rear - fro > 0) {
		printf("%d\n", arr[rear - 1]);
	}
	else {
		printf("-1\n");
	}
}
int main() {
	int i, t;
	char a[11] = { NULL };
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%s", a);
		if (!strcmp(a, "push")) {
			push();
		}
		else if (!strcmp(a, "pop")) {
			pop();
		}
		else if (!strcmp(a, "size")) {
			size();
		}
		else if (!strcmp(a, "empty")) {
			empty();
		}
		else if (!strcmp(a, "front")) {
			front();
		}
		else {
			back();
		}
	}
	return 0;
}