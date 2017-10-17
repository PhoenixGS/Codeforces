#include <cstdio>

int n;
int x[10][10];
int ans;

int main()
{
	scanf("%d", &n);
	scanf("%d", &x[1][2]);
	x[2][1] = x[1][2];
	scanf("%d", &x[1][3]);
	x[3][1] = x[1][3];
	scanf("%d", &x[2][3]);
	x[3][2] = x[2][3];
	x[1][1] = x[2][2] = x[3][3] = 1000000000;
	int now = 1;
	ans = 0;
	for (int i = 1; i < n; i++)
	{
		int k = 1;
		for (int j = 1; j <= 3; j++)
		{
			if (x[now][j] < x[now][k])
			{
				k = j;
			}
		}
		ans += x[now][k];
		now = k;
	}
	printf("%d\n", ans);
	return 0;
}
