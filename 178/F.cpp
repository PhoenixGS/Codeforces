#include <cstdio>
#include <cstring>
#include <algorithm>

int n, K;
int ch[60000][26];
int val[60000];
char st[1000];
int f[60000][1000];
int knum;

void add(char *st)
{
	int m = strlen(st + 1);
	int u = 0;
	for (int i = 1; i <= m; i++)
	{
		if (! ch[u][st[i] - 'a'])
		{
			knum++;
			ch[u][st[i] - 'a'] = knum;
		}
		u = ch[u][st[i] - 'a'];
	}
	val[u]++;
}

void dfs(int u)
{
	for (int i = 0; i < 26; i++)
	{
		int v = ch[u][i];
		if (v)
		{
			dfs(v);
		}
	}
	for (int i = 0; i <= K; i++)
	{
		f[u][i] = -1000000000;
	}
	f[u][0] = 0;
	for (int i = 0; i < 26; i++)
	{
		int v = ch[u][i];
		if (v)
		{
			for (int j = K; j >= 0; j--)
			{
				for (int k = 0; k <= j; k++)
				{
					f[u][j] = std::max(f[u][j], f[u][j - k] + f[v][k] + k * (k - 1) / 2);
				}
			}
		}
	}
	for (int i = K; i >= 0; i--)
	{
		for (int j = 0; j <= std::min(i, val[u]); j++)
		{
			f[u][i] = std::max(f[u][i], f[u][i - j]);
		}
	}
}

int main()
{
	knum = 0;
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", st + 1);
		add(st);
	}
	dfs(0);
	printf("%d\n", f[0][K]);
	return 0;
}
