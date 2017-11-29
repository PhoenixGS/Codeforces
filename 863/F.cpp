#include <cstdio>
#include <queue>
#include <cstring>

const int INF = 1e9;
int edgenum;
int vet[40000];
int cap[40000];
int val[40000];
int nextx[40000];
int head[200];
int dis[200];
int inque[200];
std::queue<int> que;
int up[200];
int down[200];
int s, t;
int n, m;
int pre[200];
int preedge[200];

void add(int u, int v, int c, int cost)
{
	edgenum++;
	vet[edgenum] = v;
	cap[edgenum] = c;
	val[edgenum] = cost;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
}

bool SPFA(int s, int t)
{
	for (int i = 1; i <= 2 * n + 2; i++)
	{
		dis[i] = INF;
		inque[i] = 0;
		pre[i] = 0;
		preedge[i] = 0;
	}
	que.push(s);
	inque[s] = true;
	dis[s] = 0;
	while (! que.empty())
	{
		int u = que.front();
		que.pop();
		for (int i = head[u]; i; i = nextx[i])
		{
			int v = vet[i];
			int c = cap[i];
			int cost = val[i];
			if (c)
			{
				if (dis[u] + cost < dis[v])
				{
					dis[v] = dis[u] + cost;
					pre[v] = u;
					preedge[v] = i;
					if (! inque[v])
					{
						que.push(v);
						inque[v] = true;
					}
				}
			}
		}
		inque[u] = false;
	}
	return pre[t] != 0;
}

int maxflow(int s, int t)
{
	int ans = 0;
	while (SPFA(s, t))
	{
		int minx = INF;
		int now = t;
		while (now != s)
		{
			minx = std::min(minx, cap[preedge[now]]);
			now = pre[now];
		}
		now = t;
		while (now != s)
		{
			cap[preedge[now]] -= minx;
			cap[preedge[now] ^ 1] += minx;
			ans += val[preedge[now]] * minx;
			now = pre[now];
		}
	}
	return ans;
}

int main()
{
	while (scanf("%d%d", &n, &m) == 2)
	{
		s = n + n + 1;
		t = n + n + 2;
		for (int i = 1; i <= n; i++)
		{
			up[i] = n;
			down[i] = 1;
		}
		for (int i = 1; i <= m; i++)
		{
			int t, l, r, v;
			scanf("%d%d%d%d", &t, &l, &r, &v);
			for (int j = l; j <= r; j++)
			{
				if (t == 1)
				{
					down[j] = std::max(down[j], v);
				}
				else
				{
					up[j] = std::min(up[j], v);
				}
			}
		}
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			if (up[i] < down[i])
			{
				flag = false;
				break;
			}
		}
		if (! flag)
		{
			puts("-1");
			continue;
		}
		edgenum = 1;
		memset(head, 0, sizeof(head));
		for (int i = 1; i <= n; i++)
		{
			add(s, i, 1, 0);
			add(i, s, 0, 0);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = down[i]; j <= up[i]; j++)
			{
				add(i, j + n, 1, 0);
				add(j + n, i, 0, 0);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				add(i + n, t, 1, 2 * j - 1);
				add(t, i + n, 0, 1 - 2 * j);
			}
		}
		printf("%d\n", maxflow(s, t));
	}
	return 0;
}
