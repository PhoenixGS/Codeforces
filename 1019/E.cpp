#include <cstdio>
#include <cstring>
#include <vector>
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

const int INF = 1000000000;
const int _n = 100000 + 10;
int n, m;
int edgenum;
int vet[4 * _n], nextx[4 * _n], head[2 * _n];
long long vala[4 * _n], valb[4 * _n];
int size[2 * _n];
int root;
std::vector<std::pair<int, std::pair<long long, long long> > > vec[_n];
int last[2], now[2];
std::pair<long long, long long> v[2][2 * _n];
int ls;
std::pair<long long, long long> vv[20 * _n];
int f[4 * _n];
int vis[4 * _n];

void add(int u, int v, long long costa, long long costb)
{
//	printf("MM%d %d %lld %lld\n", u, v, costa, costb);
	edgenum++;
	vet[edgenum] = v;
	vala[edgenum] = costa;
	valb[edgenum] = costb;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
}

long long up(std::pair<long long, long long> *v, int x, int y)
{
	return v[x].second - v[y].second;
}

long long down(std::pair<long long, long long> *v, int x, int y)
{
	return v[y].first - v[x].first;
}

void build(int &last, std::pair<long long, long long> *v)
{
	std::sort(v + 1, v + last + 1);
	int newlast = 0;
	for (int i = 1; i <= last; i++)
	{
		while (newlast >= 1 && v[newlast].first == v[i].first)
		{
			newlast--;
		}
		while (newlast >= 2 && (long long)up(v, newlast - 1, newlast) * down(v, newlast, i) >= (long long)up(v, newlast, i) * down(v, newlast - 1, newlast))
		{
			newlast--;
		}
		newlast++;
		v[newlast] = v[i];
	}
	last = newlast;
}

void getroot(int u, int father, int S)
{
	size[u] = 1;
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		if (v != father && ! vis[i])
		{
			getroot(v, u, S);
			f[i >> 1] = std::max(size[v], S - size[v]);
			if (f[i >> 1] < f[root >> 1])
			{
				root = i;
			}
			size[u] += size[v];
		}
	}
}

void dfs1(int u, int father)
{
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		long long costa = vala[i];
		long long costb = valb[i];
		if (v != father && ! vis[i])
		{
			vec[u].push_back(std::make_pair(v, std::make_pair(costa, costb)));
			dfs1(v, u);
		}
	}
}

void dfs(int u, int father, long long sa, long long sb, int cas)
{
	size[u] = 1;
	for (int i = head[u]; i; i = nextx[i])
	{
		int v = vet[i];
		long long costa = vala[i];
		long long costb = valb[i];
		if (v != father && ! vis[i])
		{
			dfs(v, u, sa + costa, sb + costb, cas);
			size[u] += size[v];
		}
	}
	if (size[u] == 1)
	{
		last[cas]++;
		v[cas][last[cas]] = std::make_pair(sa, sb);
	}
}

void solve(int rt, int father, int S)
{
	if (! rt)
	{
		return;
	}
	vis[rt] = vis[rt ^ 1] = 1;
	for (int i = 0; i < 2; i++)
	{
		last[i] = 0;
		dfs(vet[rt ^ i], 0, 0, 0, i);
		build(last[i], v[i]);
	}
	now[0] = now[1] = 1;
	while (now[0] <= last[0] && now[1] <= last[1])
	{
		ls++;
		vv[ls].first = v[0][now[0]].first + v[1][now[1]].first + vala[rt];
		vv[ls].second = v[0][now[0]].second + v[1][now[1]].second + valb[rt];
		if (now[0] < last[0] && now[1] < last[1])
		{
			if ((long long)up(v[0], now[0], now[0] + 1) * down(v[1], now[1], now[1] + 1) <= (long long)up(v[1], now[1], now[1] + 1) * down(v[0], now[0], now[0] + 1))
			{
				now[0]++;
			}
			else
			{
				now[1]++;
			}
		}
		else
		{
			if (now[0] < last[0])
			{
				now[0]++;
			}
			else
			{
				now[1]++;
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		root = 0;
		int ss = size[vet[rt ^ i]];
		getroot(vet[rt ^ i], 0, ss);
		solve(root, 0, ss);
	}
}

int main()
{
#ifdef debug
	freopen("E.in", "r", stdin);
#endif
	n = read();
	m = read();
	for (int i = 1; i < n; i++)
	{
		int u, v;
		long long a, b;
		u = read();
		v = read();
		a = read();
		b = read();
		add(u, v, a, b);
		add(v, u, a, b);
	}

	dfs1(1, 0);
	int nn = n;
	edgenum = 1;
	memset(head, 0, sizeof(head));
	for (int u = 1; u <= n; u++)
	{
		if ((int)vec[u].size() <= 2)
		{
			for (int i = 0; i < (int)vec[u].size(); i++)
			{
				add(u, vec[u][i].first, vec[u][i].second.first, vec[u][i].second.second);
				add(vec[u][i].first, u, vec[u][i].second.first, vec[u][i].second.second);
			}
		}
		else
		{
			int pre = u;
			for (int i = 0; i < (int)vec[u].size() - 2; i++)
			{
				add(pre, vec[u][i].first, vec[u][i].second.first, vec[u][i].second.second);
				add(vec[u][i].first, pre, vec[u][i].second.first, vec[u][i].second.second);
				nn++;
				add(pre, nn, 0, 0);
				add(nn, pre, 0, 0);
				pre = nn;
			}
			add(pre, vec[u][vec[u].size() - 2].first, vec[u][vec[u].size() - 2].second.first, vec[u][vec[u].size() - 2].second.second);
			add(vec[u][vec[u].size() - 2].first, pre, vec[u][vec[u].size() - 2].second.first, vec[u][vec[u].size() - 2].second.second);
			add(pre, vec[u][vec[u].size() - 1].first, vec[u][vec[u].size() - 1].second.first, vec[u][vec[u].size() - 1].second.second);
			add(vec[u][vec[u].size() - 1].first, pre, vec[u][vec[u].size() - 1].second.first, vec[u][vec[u].size() - 1].second.second);
		}
	}
	n = nn;
	f[0] = INF;
	root = 0;
	getroot(1, 0, n);
	solve(root, 0, n);
	build(ls, vv);
	int now = 1;
	for (int i = 0; i < m; i++)
	{
		while (now < ls && (long long)i * down(vv, now, now + 1) >= up(vv, now, now + 1))
		{
			now++;
		}
		printf("%lld ", (long long)vv[now].first * i + vv[now].second);
	}
	puts("");
	return 0;
}
