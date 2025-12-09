#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    int count = 0;
    int result = 666;
    const char* needle = "666";

    scanf("%d", &n);

    while (1) {
        char cresult[20];              // result를 문자열로 바꿔 담을 버퍼

        sprintf(cresult, "%d", result);   // 정수 → 문자열

        if (strstr(cresult, needle) != NULL) {  // "666"이 포함되어 있으면
            count += 1;
        }

        if (count == n) {
            printf("%d\n", result);    // n번째 666이 포함된 수 출력
            break;
        }

        result += 1;                  // 다음 숫자
    }

    return 0;
}
