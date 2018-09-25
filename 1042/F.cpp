#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>

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
const int INF = 1000000000;
int n, k;
int edgenum;
int vet[2 * _n], nextx[2 * _n], head[_n];
int f[_n];
int degree[_n];
int root;
int ans;

void add(int u, int v)
{
	edgenum++;
	vet[edgenum] = v;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
}

void dfs(int u, int father)
{
	std::vector<int> vec;
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (v != father)
		{
			dfs(v, u);
			vec.push_back(f[v] + 1);
		}
	}
	if ((int)vec.size() == 0)
	{
		f[u] = 0;
		return;
	}
	std::sort(vec.begin(), vec.end());
	while ((int)vec.size() >= 2)
	{
		if (vec[vec.size() - 1] + vec[vec.size() - 2] <= k)
		{
			break;
		}
		ans++;
		vec.pop_back();
	}
	f[u] = vec[vec.size() - 1];
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		u = read();
		v = read();
		add(u, v);
		add(v, u);
		degree[u]++;
		degree[v]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] >= 2)
		{
			root = i;
		}
	}
	ans = 0;
	dfs(root, 0);
	printf("%d\n", ans + 1);
	return 0;
}
