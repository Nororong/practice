#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int priority;
	int index;
} doc;

int main() {
	int tc;
	(void)scanf("%d", &tc);
	while(tc--)
	{
		int n, m;
		(void)scanf("%d %d", &n, &m);
		
		doc q[10000];
		int front = 0, rear = 0;
		
		for (int i = 0; i < n; i++)
		{
			int pr;
			(void)scanf("%d", &pr);
			q[rear].priority = pr;
			q[rear].index = i;
			rear++;
		}

		int num=0;

		while (1) {
			doc cur = q[front];
			front++;

			int ishigher = 0;
			for (int i = front; i < rear; i++)
			{
				if (q[i].priority > cur.priority) {
					ishigher = 1;
					break;
				}
			}

			if (ishigher) {
				q[rear] = cur;
				rear++;
			}
			else {
				num++;
					if (cur.index == m) {
						printf("%d\n", num);
						break;
					}
			}
		}
	}
}
