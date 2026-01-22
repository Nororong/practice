#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
} Node;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs(int **arr, int **visited, int m, int n, int sx, int sy) {
	Node q[2500];
	int front = 0, rear = 0;

	Node start;
	start.x = sx;
	start.y = sy;
	q[rear++] = start;
	visited[sx][sy] = 1;

	while (front < rear) {
		Node cur = q[front++];

		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
				continue;
			}

			if (arr[nx][ny] == 1 && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				
				Node next;
				next.x = nx;
				next.y = ny;
				q[rear++] = next;
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int m, n, k;
		scanf("%d %d %d", &m, &n, &k);

		int** arr = (int**)malloc(sizeof(int*) * m);
		int** visited = (int**)malloc(sizeof(int*) * m);

		for (int i = 0; i < m; i++) {
			arr[i] = (int*)calloc(n, sizeof(int));
			visited[i] = (int*)calloc(n, sizeof(int));
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			arr[x][y] = 1;
		}
		int count = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1 && !visited[i][j]) {
					bfs(arr, visited, m, n, i, j);
					count++;
				}
			}
		}
		printf("%d\n", count);

		for (int i = 0; i < m; i++) {
			free(arr[i]);
			free(visited[i]);
		}
		free(arr);
		free(visited);
	}
	return 0;
}