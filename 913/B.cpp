#include <cstdio>

int n;
int edgenum;
int vet[10000];
int nextx[10000];
int head[10000];
int vis[10000];
int size[10000];

void add(int u, int v)
{
	edgenum++;
	vet[edgenum] = v;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
}

bool dfs(int u)
{
	vis[u] = true;
	int cnt = 0;
	size[u] = 1;
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (vis[v])
		{
			return false;
		}
		if (! dfs(v))
		{
			return false;
		}
		size[u] += size[v];
		if (size[v] == 1)
		{
			cnt++;
		}
	}
	if (size[u] != 1 && cnt < 3)
	{
		return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		int father;
		scanf("%d", &father);
		add(father, i);
	}
	if (dfs(1))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
