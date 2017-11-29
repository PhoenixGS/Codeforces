#include <cstdio>
#include <cstring>
#include <algorithm>

int edgenum;
int vet[90000];
int val[90000];
int nextx[90000];
int head[20000];
int cur[20000];
int que[20000];
int dis[20000];
int x[20000], y[20000];
int n, m;
int ans[20000];
const int INF = 1e9;

void add(int u, int v, int cost)
{
	edgenum++;
	vet[edgenum] = v;
	val[edgenum] = cost;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
}

bool bfs(int s, int t)
{
	memset(dis, -1, sizeof(dis));
	int headx = 1;
	int tailx = 0;
	tailx++;
	que[tailx] = s;
	dis[s] = 0;
	while (headx <= tailx)
	{
		int u = que[headx];
		headx++;
		for (int i = head[u]; i; i = nextx[i])
		{
			int v = vet[i];
			int cost = val[i];
			if (cost && dis[v] == -1)
			{
				dis[v] = dis[u] + 1;
				tailx++;
				que[tailx] = v;
			}
		}
	}
	return dis[t] != -1;
}

int dfs(int u, int t, int flow)
{
	if (u == t)
	{
		return flow;
	}
	int ans = 0;
	for (int i = cur[u]; i; i = nextx[i])
	{
		int v = vet[i];
		int cost = val[i];
		int f;
		if (dis[u] + 1 == dis[v] && (f = dfs(v, t, std::min(flow - ans, cost))) > 0)
		{
			val[i] -= f;
			val[i ^ 1] += f;
			ans += f;
			cur[u] = i;
			if (ans == flow)
			{
				break;
			}
		}
	}
	if (ans < flow)
	{
		dis[u] = -1;
	}
	return ans;
}

int maxflow(int s, int t)
{
	int flow = 0;
	while (bfs(s, t))
	{
		for (int i = 1; i <= n + m + 2; i++)
		{
			cur[i] = head[i];
		}
		flow += dfs(s, t, INF);
	}
	return flow;
}

bool check(int mid)
{
	edgenum = 1;
	memset(head, 0, sizeof(head));
	for (int i = 1; i <= m; i++)
	{
		add(n + m + 1, i, 1);
		add(i, n + m + 1, 0);
		add(i, x[i] + m, 1);
		add(x[i] + m, i, 0);
		add(i, y[i] + m, 1);
		add(y[i] + m, i, 0);
	}
	for (int i = 1; i <= n; i++)
	{
		add(i + m, n + m + 2, mid);
		add(n + m + 2, i + m, 0);
	}
	int ans = maxflow(n + m + 1, n + m + 2);
	return ans == m;
}

int main()
{
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
		}
		int l = 0, r = m;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (check(mid))
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		printf("%d\n", l);
		check(l);
		for (int u = 1; u <= m; u++)
		{
			for (int i = head[u]; i; i = nextx[i])
			{
				int v = vet[i];
				int cost = val[i];
				if (cost == 0)
				{
					ans[u] = v - m;
				}
			}
		}
		for (int i = 1; i <= m; i++)
		{
			printf("%d %d\n", ans[i], ans[i] == x[i] ? y[i] : x[i]);
		}
	}
	return 0;
}
