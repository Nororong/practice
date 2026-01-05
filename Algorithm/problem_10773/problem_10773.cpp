#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int k = 0;
	scanf("%d", &k);

	int cash[100000];
	int sum = 0;

	for (int i = 0; i < k; i++) {
		cash[i] = 0;
	}

	int top = -1;

	for (int i = 0; i < k; i++) {
		int money;
		scanf("%d", &money);

		if (money != 0) {
			top++;
			cash[top] = money;
		}
		else {
			cash[top] = 0;
			top--;
		}
	}
	for (int i = 0; i < k; i++) {
		sum += cash[i];
	}
	printf("%d", sum);
}