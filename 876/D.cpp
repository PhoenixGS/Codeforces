#include <cstdio>

int n;
int x[400000];
int f[400000];

int main()
{
	scanf("%d", &n);
	int front = n + 1;
	printf("1 ");
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		f[x[i]] = 1;
		while (f[front - 1])
		{
			front--;
		}
		printf("%d ", i - (n - front + 1) + 1);
	}
	printf("\n");
	return 0;
}
