#include <cstdio>

long long read()
{
	char last = '+', ch = getchar();
	while (ch < '0' || ch > '9') last = ch, ch = getchar();
	long long tmp = 0;
	while (ch >= '0' && ch <= '9') tmp = tmp * 10 + ch - 48, ch = getchar();
	if (last == '-') tmp = -tmp;
	return tmp;
}

const int M = 1000000007;
const int _n = 50 + 10;
int n, p;
int x[_n];
int mi[_n];
int f[_n][2][2][2];
int ans;

int main()
{
	n = read();
	p = read();
	for (int i = 1; i <= n; i++)
	{
		x[i] = read();
	}
	mi[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		mi[i] = (long long)mi[i - 1] * 2 % M;
	}
	f[0][0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (x[i] != 0)
		{
			for (int w = 0; w < 2; w++)
			{
				for (int k = 0; k < 2; k++)
				{
					(f[i][w | 1][0][k ^ 1] += (long long)f[i - 1][w][0][k] * mi[i - 1] % M) %= M;
					(f[i][w | 0][1][k ^ 0] += (long long)f[i - 1][w][1][k] * mi[i - 2] % M) %= M;
					(f[i][w | 1][1][k ^ 1] += (long long)f[i - 1][w][1][k] * mi[i - 2] % M) %= M;
				}
			}
		}
		if (x[i] != 1)
		{
			for (int b = 0; b < 2; b++)
			{
				for (int k = 0; k < 2; k++)
				{
					(f[i][0][b | 1][k ^ 1] += (long long)f[i - 1][0][b][k] * mi[i - 1] % M) %= M;
					(f[i][1][b | 0][k ^ 0] += (long long)f[i - 1][1][b][k] * mi[i - 2] % M) %= M;
					(f[i][1][b | 1][k ^ 1] += (long long)f[i - 1][1][b][k] * mi[i - 2] % M) %= M;
				}
			}
		}
	}
	ans = 0;
	for (int w = 0; w < 2; w++)
	{
		for (int b = 0; b < 2; b++)
		{
			(ans += f[n][w][b][p]) %= M;
		}
	}
	printf("%d\n", ans);
	return 0;
}
