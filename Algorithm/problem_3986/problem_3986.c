# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int tc;
	scanf("%d", &tc);
	int count=0;
	while (tc--) {
		char str[10001];
		int top = -1;

		scanf("%s", &str);

		char stack[100001];

		int len = (int)strlen(str);

		for (int i = 0; i < len; i++) {
			char word = str[i];

			if (top >= 0 && stack[top] == word) {
				top--;
			}
			else {
				stack[++top] = word;
			}
		}
		if (top == -1) {
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}