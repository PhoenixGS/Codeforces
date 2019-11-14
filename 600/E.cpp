#include <cstdio>

const int _n = 100000 + 10;
int n;
int edgenum;
int vet[2 * _n], nextx[2 * _n], head[_n];
int size[_n], cnt[_n], col[_n], son[_n];
int maxx;
long long sum;
int sson;
long long ans[_n];

void add(int u, int v)
{
	edgenum++;
	vet[edgenum] = v;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
}

void dfs(int u, int father)
{
	size[u] = 1;
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (v != father)
		{
			dfs(v, u);
			size[u] += size[v];
			if (size[v] > size[son[u]])
			{
				son[u] = v;
			}
		}
	}
}

void add(int u, int father, int cas)
{
	cnt[col[u]] += cas;
	if (cnt[col[u]] > maxx)
	{
		maxx = cnt[col[u]];
		sum = col[u];
	}
	else
	{
		if (cnt[col[u]] == maxx)
		{
			sum += col[u];
		}
	}
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (v != father && v != sson)
		{
			add(v, u, cas);
		}
	}
}

void dfs2(int u, int father, int cas)
{
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (v != father && v != son[u])
		{
			dfs2(v, u, 0);
		}
	}
	if (son[u])
	{
		dfs2(son[u], u, 1);
		sson = son[u];
	}
	add(u, father, 1);
	sson = 0;
	ans[u] = sum;
	if (! cas)
	{
		add(u, father, -1);
		sum = 0;
		maxx = 0;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &col[i]);
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	dfs2(1, 0, 0);
	for (int i = 1; i <= n; i++)
	{
		printf("%lld ", ans[i]);
	}
	return 0;
}
