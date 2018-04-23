#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#pragma G++ optimize (2)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

int n, m;
char s[200000], t[200000];
int nextx[200000], ch[200000][30];
std::vector<int> f[200000];
int ans;

void getnextx()
{
	int j = 0;
	for (int i = 2; i <= m; i++)
	{
		while (j && t[j + 1] != t[i])
		{
			j = nextx[j];
		}
		if (t[j + 1] == t[i])
		{
			j++;
		}
		nextx[i] = j;
	}
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	scanf("%s", t + 1);
	m = strlen(t + 1);
	getnextx();
	ch[0][t[1] - 'a'] = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (t[i + 1] - 'a' == j)
			{
				ch[i][j] = i + 1;
			}
			else
			{
				ch[i][j] = ch[nextx[i]][j];
			}
		}
	}
	f[0].push_back(0);
	for (int j = 1; j < m + 10; j++)
	{
		f[0].push_back(-1000000000);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m + 10; j++)
		{
			f[i].push_back(-1000000000);
		}
		for (int j = 0; j < m; j++)
		{
			if (s[i] != '?')
			{
				if (ch[j][s[i] - 'a'] == m)
				{
					f[i][nextx[m]] = std::max(f[i][nextx[m]], f[i - 1][j] + 1);
				}
				else
				{
					f[i][ch[j][s[i] - 'a']] = std::max(f[i][ch[j][s[i] - 'a']], f[i - 1][j]);
				}
			}
			else
			{
				for (int k = 0; k < 26; k++)
				{
					if (ch[j][k] == m)
					{
						f[i][nextx[m]] = std::max(f[i][nextx[m]], f[i - 1][j] + 1);
					}
					else
					{
						f[i][ch[j][k]] = std::max(f[i][ch[j][k]], f[i - 1][j]);
					}
				}
			}
		}
	}
	ans = 0;
	for (int i = 0; i < m; i++)
	{
		ans = std::max(ans, f[n][i]);
	}
	printf("%d\n", ans);
	return 0;
}
