#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max3(int a, int b, int c) {
    int m = (a > b) ? a : b;
    return (m > c) ? m : c;
}

int main() {
    int n;
    scanf("%d", &n);

    int* a = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int dp0 = 0;
    int dp1 = 0;
    int dp2 = 0;

    for (int i = 0; i < n; i++) {
        int cur0 = max3(dp0, dp1, dp2);
        int cur1 = dp0 + a[i];
        int cur2 = dp1 + a[i];

        dp0 = cur0;
        dp1 = cur1;
        dp2 = cur2;
    }

    int ans = max3(dp0, dp1, dp2);
    printf("%d\n", ans);

    free(a);
    return 0;
}
