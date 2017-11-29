#include <cstdio>
#include <cstring>
#include <algorithm>

int f[2][3000][3000];
char st[2][3000];
char t[3000];
int ans;
int n, m;
const int M = 1e9 + 7;

bool check(char *st, int cas, int len, int start)
{
	for (int i = 1; i <= len; i++)
	{
		if (*(st + i * cas) != t[start + i])
		{
			return false;
		}
	}
	return true;
}

void solve()
{
	memset(f, 0, sizeof(f));
//	printf("%s %s\n", st[0] + 1, st[1] + 1);
	for (int i = 1; i <= m / 2; i++)
	{
		for (int j = 1; i + j - 1 <= n; j++)
		{
			if (check(st[0] + i + j, -1, i, 0) && check(st[1] + j - 1, 1, i, i))
			{
				printf("%d %d %d\n", 1, i + j - 1, 2 * i);
				(f[1][i + j - 1][2 * i] += 1) %= M;
			}
//			if (i + j - 1 == 3 && i == 1)
//			{
//				printf("%d %d\n", check(st[0] + i + j, -1, i, 0), check(st[1] + j - 1, 1, i, i));
//			}
			if (check(st[1] + i + j, -1, i, 0) && check(st[0] + j - 1, 1, i, i))
			{
				printf("%d %d %d\n", 0, i + j - 1, 2 * i);
				(f[0][i + j - 1][2 * i] += 1) %= M;
			}
		}
	}
	for (int pos = 1; pos <= m; pos++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (st[j][i] == t[pos])
				{
					if (pos == 1)
					{
						(f[j][i][pos] += 1) %= M;
					}
					else
					{
						(f[j][i][pos] += (f[j ^ 1][i][pos - 1] + f[j][i - 1][pos - 1]) % M) %= M;
					}
				}
			}
		}
	}
	for (int i = 1; i <= m / 2; i++)
	{
		for (int j = 1; i + j - 1 <= n; j++)
		{
			if (check(st[0] + j - 1, 1, i, m - i - i) && check(st[1] + i + j, -1, i, m - i))
			{
				(ans += f[1][j - 1][m - i - i]) %= M;
			}
			if (check(st[1] + j - 1, 1, i, m - i - i) && check(st[0] + i + j, -1, i, m - i))
			{
				(ans += f[0][j - 1][m - i - i]) %= M;
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
	{
		printf("%d %d\n", f[0][i][m], f[1][i][m]);
		(ans += (f[0][i][m] + f[1][i][m]) % M) %= M;
	}
	printf("%d\n", ans);
}

int main()
{
	scanf("%s", st[0] + 1);
	scanf("%s", st[1] + 1);
	scanf("%s", t + 1);
	n = strlen(st[0] + 1);
	m = strlen(t + 1);
	if (m == 1)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (st[0][i] == t[1])
				{
					ans++;
				}
			}
		}
		printf("%d\n", ans);
		return 0;
	}
	if (m == 2)
	{
		int ans = 0;
		for (int i = 1; i < n; i++)
		{
			ans += (st[0][i] == t[1] && st[0][i + 1] == t[2]) + (st[0][i + 1] == t[1] && st[0][i] == t[2]);
			ans += (st[1][i] == t[1] && st[1][i + 1] == t[2]) + (st[1][i + 1] == t[1] && st[1][i] == t[2]);
		}
		for (int i = 1; i <= n; i++)
		{
			ans += (st[0][i] == t[1] && st[1][i] == t[2]) + (st[1][i] == t[1] && st[0][i] == t[2]);
		}
		printf("%d\n", ans);
		return 0;
	}
	ans = 0;
	solve();
	for (int i = 1; i <= n / 2; i++)
	{
		std::swap(st[0][i], st[0][n - i + 1]);
	}
	for (int i = 1; i <= n / 2; i++)
	{
		std::swap(st[1][i], st[1][n - i + 1]);
	}
	solve();
	printf("%d\n", ans);
	return 0;
}
