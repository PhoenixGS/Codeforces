#include <cstdio>

int n, q, c;
int xx[11][105][105];
int s[11][105][105];

void init(int k)
{
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			s[k][i][j] = s[k][i][j - 1] + s[k][i - 1][j] - s[k][i - 1][j - 1] + xx[k][i][j];
		}
	}
}

int calc(int k, int x1, int y1, int x2, int y2)
{
	return s[k][x2][y2] - s[k][x1 - 1][y2] - s[k][x2][y1 - 1] + s[k][x1 - 1][y1 - 1];
}

int main()
{
	scanf("%d%d%d", &n, &q, &c);
	for (int i = 1; i <= n; i++)
	{
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		xx[k][x][y]++;
	}
	for (int i = 0; i <= c; i++)
	{
		init(i);
	}
	while (q--)
	{
		int times, x1, y1, x2, y2;
		scanf("%d%d%d%d%d", &times, &x1, &y1, &x2, &y2);
		int ans = 0;
		for (int i = 0; i <= c; i++)
		{
			int tmp = calc(i, x1, y1, x2, y2);
			int kkk = (i + times) % (c + 1);
			ans += tmp * kkk;
		}
		printf("%d\n", ans);
	}
	return 0;
}
