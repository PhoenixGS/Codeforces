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

const int _n = 1000000 + 10;
int n;
int edgenum;
int vet[2 * _n], nextx[2 * _n], head[_n];
int son[_n];
int times;
int pos[_n], len[_n];
int f[_n];
int ans[_n];

void add(int u, int v)
{
	edgenum++;
	vet[edgenum] = v;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
}

void dfs(int u, int father)
{
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (v != father)
		{
			dfs(v, u);
			if (len[v] > len[son[u]])
			{
				son[u] = v;
			}
		}
	}
	len[u] = len[son[u]] + 1;
}

void dfs2(int u, int father)
{
	times++;
	pos[u] = times;
	f[pos[u]] = 1;
	if (son[u])
	{
		dfs2(son[u], u);
		ans[u] = ans[son[u]] + 1;
	}
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (v != father && v != son[u])
		{
			dfs2(v, u);
			for (int j = 0; j < len[v]; j++)
			{
				f[pos[u] + j + 1] += f[pos[v] + j];
				if (f[pos[u] + j + 1] > f[pos[u] + ans[u]] || (f[pos[u] + j + 1] == f[pos[u] + ans[u]] && j + 1 < ans[u]))
				{
					ans[u] = j + 1;
				}
			}
		}
	}
	if (f[pos[u] + ans[u]] == 1)
	{
		ans[u] = 0;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int u = read();
		int v = read();
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}


