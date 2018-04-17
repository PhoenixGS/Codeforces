#include <cstdio>
#include <algorithm>
#include <bitset>

struct T
{
	int x, val;
};

int k, n, m;
int x[20][200000];
T v[200000][20];
std::bitset<5000> c[300000];
int num;

bool comp(T x, T y)
{
	return x.val < y.val;
}

int main()
{
	scanf("%d%d%d", &k, &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			scanf("%d", &x[i][j]);
			v[j][i].x = i;
			v[j][i].val = x[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < (1 << n); j++)
		{
			if (j & (1 << (i - 1)))
			{
				c[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= k; i++)
	{
		std::sort(v[i] + 1, v[i] + n + 1, comp);
	}
	num = n;
	for (int i = 1; i <= m; i++)
	{
		int cas;
		scanf("%d", &cas);
		if (cas == 1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			num++;
			c[num] = c[x] | c[y];
		}
		if (cas == 2)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			num++;
			c[num] = c[x] & c[y];
		}
		if (cas == 3)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			int ans = n + 1, ss = 0;
			for (ans = n + 1, ss = 0; ans >= 0 && ! c[x][ss]; ans--, ss |= (1 << (v[y][ans].x - 1)));
			printf("%d\n", v[y][ans].val);
		}
	}
	return 0;
}
