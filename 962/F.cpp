#include <cstdio>
#include <stack>

int n, m;
int edgenum;
int vet[300000], nextx[300000], head[200000];
int times;
int dfn[200000], low[200000], vis[200000];
int knumber;
std::stack<int> vertex, edge;
int cx[200000], cy[200000];
int ansn;
int belong[200000];

void add(int u, int v)
{
	edgenum++;
	vet[edgenum] = v;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
}

void dfs(int u, int father)
{
	times++;
	dfn[u] = times;
	low[u] = times;
	vis[u] = 1;
	vertex.push(u);
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (v != father)
		{
			if (! dfn[v])
			{
				edge.push(i);
				dfs(v, u);
				if (low[v] >= dfn[u])
				{
					knumber++;
					cx[knumber]++;
					int tmp;
					do
					{
						tmp = vertex.top();
						vertex.pop();
						cx[knumber]++;
					}while (tmp != v);
					do
					{
						tmp = edge.top();
						edge.pop();
						belong[tmp / 2] = knumber;
						cy[knumber]++;
					}while (tmp != i);
				}
				low[u] = std::min(low[u], low[v]);
			}
			else
			{
				if (dfn[v] <= dfn[u])
				{
					edge.push(i);
				}
				low[u] = std::min(low[u], dfn[v]);
			}
		}
	}
}

int main()
{
	edgenum = 1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	for (int i = 1; i <= n; i++)
	{
		if (! vis[i])
		{
			dfs(i, 0);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (cx[belong[i]] == cy[belong[i]])
		{
			ansn++;
		}
	}
	printf("%d\n", ansn);
	for (int i = 1; i <= m; i++)
	{
		if (cx[belong[i]] == cy[belong[i]])
		{
			printf("%d ", i);
		}
	}
	puts("");
	return 0;
}
