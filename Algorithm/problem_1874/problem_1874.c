#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int number[100000];
	int stack[100000];
	char result[200000];
	int anstop = 0;


	for (int i = 0; i < n; i++) {
		scanf("%d", &number[i]);
	}

	int top = -1;
	int current = 1;

	for (int i = 0; i < n; i++) {
		while (current<=number[i]) {
			stack[++top] = current++;
			result[anstop++] = '+';
		}

		if (top >= 0 && stack[top] == number[i]) {
			top--;
			result[anstop++] = '-';

		}
		else {
			printf("NO\n");
			return 0;
		}
	}

	for (int i = 0; i < anstop; i++) {
		printf("%c\n", result[i]);
	}

}
