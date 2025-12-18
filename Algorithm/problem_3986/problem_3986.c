#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	char name;
} array;

int main() {
	int tc;
	scanf("%d", &tc);

	int count = 0;

	while (tc--) {
		char str[100001];
		scanf("%s", str);

		int len = (int)strlen(str);
		
		array stack[100001];
		
		int top = -1;

		for (int i = 0; i < len; i++) {
			char now = str[i];
				if (top>=0 && (stack[top].name == now)) {
					top--;
				}
				else {
					stack[++top].name = now;
				}
			}
		if (top == -1) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}