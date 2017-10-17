#include <cstdio>

int n, k, m;
int x[200000];
int f[200000];

int main()
{
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		f[x[i] % m]++;
	}
	bool flag = 0;
	int tt;
	for (int i = 0; i < m; i++)
	{
		if (f[i] >= k)
		{
			flag = 1;
			tt = i;
			break;
		}
	}
	if (flag)
	{
		printf("Yes\n");
		int cnt = 0;
		for (int i = 1; i <= n && cnt < k; i++)
		{
			if (x[i] % m == tt)
			{
				printf("%d ", x[i]);
				cnt++;
			}
		}
		printf("\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
