#include <cstdio>
#include <queue>
#include <cstring>

int n, m;
int edgenum;
int vet[300000];
int nextx[300000];
int head[300000];
int len[3];
int x[3][300000];
int dis[300000];
std::queue<int> que;
int in[300000];
int ans[300000];

void add(int u, int v)
{
	edgenum++;
	vet[edgenum] = v;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
	in[v]++;
}

int main()
{
	edgenum = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &len[i & 1]);
		for (int j = 1; j <= len[i & 1]; j++)
		{
			scanf("%d", &x[i & 1][j]);
		}
		if (i != 1)
		{
			int k = 1;
			for (; k <= len[0] && k <= len[1] && x[0][k] == x[1][k]; k++);
			if (k >	len[(i - 1) & 1])
			{
				continue;
			}
			if (k > len[i & 1])
			{
				printf("No\n");
				return 0;
			}
			add(x[(i - 1) & 1][k], x[i & 1][k]);
		}
	}
	memset(dis, -1, sizeof(dis));
	for (int i = 1; i <= m; i++)
	{
		if (in[i] == 0)
		{
			que.push(i);
			dis[i] = 0;
		}
	}
	while (! que.empty())
	{
		int u = que.front();
		que.pop();
		for (int i = head[u]; i; i = nextx[i])
		{
			int v = vet[i];
			dis[v] = std::max(dis[v], dis[u] + (u > v));
			in[v]--;
			if (in[v] == 0)
			{
				que.push(v);
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (dis[i] > 1 || dis[i] == -1)
		{
			printf("No\n");
			return 0;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		if (dis[i] == 0)
		{
			cnt++;
			ans[cnt] = i;
		}
	}
	printf("Yes\n");
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
