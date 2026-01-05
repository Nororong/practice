#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int weight;
	int height;
	int rank;
}profile;

int main() {
	int n;
	scanf("%d", &n);

	profile profiles[50];

	for (int i = 0; i < n; i++) {
		int w, h;
		scanf("%d %d", &w, &h);
		profiles[i].weight = w;
		profiles[i].height = h;
		profiles[i].rank = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			else {
				if (profiles[i].weight < profiles[j].weight && profiles[i].height < profiles[j].height)
					profiles[i].rank++;
			}
		}
		printf("%d ", profiles[i].rank);
	}
	return 0;
}