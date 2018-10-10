#include <cstdio>
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

const int _n = 200000 + 10;
int n;
int edgenum;
int vet[2 * _n], nextx[2 * _n], head[_n];
int size[_n];
int f[_n];
int root;
int vis[_n];
long long cc[2], ss[2];
long long ans;
int s;

void add(int u, int v)
{
	edgenum++;
	vet[edgenum] = v;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
}

void getroot(int u, int father)
{
	size[u] = 1;
	f[u] = 0;
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (v != father && ! vis[v])
		{
			getroot(v, u);
			size[u] += size[v];
			f[u] = std::max(f[u], size[v]);
		}
	}
	f[u] = std::max(f[u], s - size[u]);
	if (f[u] < f[root])
	{
		root = u;
	}
}

void calcans(int u, int father, int deep)
{
	size[u] = 1;
	ans += (cc[deep & 1] * deep + ss[deep & 1]) / 2;
	ans += (cc[(deep & 1) ^ 1] * deep + ss[(deep & 1) ^ 1] + cc[(deep & 1) ^ 1]) / 2;
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (v != father && ! vis[v])
		{
			calcans(v, u, deep + 1);
			size[u] += size[v];
		}
	}
}

void update(int u, int father, int deep)
{
	cc[deep & 1]++;
	ss[deep & 1] += deep;
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (v != father && ! vis[v])
		{
			update(v, u, deep + 1);
		}
	}
}

void solve(int u, int father)
{
	vis[u] = 1;
	ss[0] = ss[1] = 0;
	cc[0] = cc[1] = 0;
	cc[0]++;
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (! vis[v])
		{
			calcans(v, 0, 1);
			update(v, 0, 1);
		}
	}
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (! vis[v])
		{
			s = size[v];
			root = 0;
			getroot(v, 0);
			solve(root, 0);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		u = read();
		v = read();
		add(u, v);
		add(v, u);
	}
	f[0] = 1000000000;
	s = n;
	root = 0;
	getroot(1, 0);
	solve(root, 0);
	printf("%lld\n", ans);
	return 0;
}
