#include <cstdio>
#include <algorithm>

struct T
{
	int x, id;
};

T vv[2000000];
int rank[2000000];
int f[2000000], s[2000000];
int edgenum;
int vet[3000000], nextx[3000000], head[2000000];
int n;

void add(int u, int v)
{
	edgenum++;
	vet[edgenum] = v;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
}

int findfather(int x)
{
	return f[x] == x ? x : f[x] = findfather(f[x]);
}

void unionx(int x, int y)
{
	int xx = findfather(x);
	int yy = findfather(y);
	f[xx] = yy;
	s[yy] += s[xx];
}

bool compmax(T x, T y)
{
	return x.x < y.x;
}

bool compmin(T x, T y)
{
	return x.x > y.x;
}

long long query(int cas)
{
	long long ans = 0;
	if (cas == 1)
	{
		std::sort(vv + 1, vv + n + 1, compmax);
	}
	else
	{
		std::sort(vv + 1, vv + n + 1, compmin);
	}
	for (int i = 1; i <= n; i++)
	{
		rank[vv[i].id] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", vv[i].x);
	}
	puts("");
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		s[i] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		long long sum1 = 0;
		long long sum2 = 0;
		int u = vv[k].id;
		for (int i = head[u]; i; i = nextx[i])
		{
			int v = vet[i];
			if (rank[v] < rank[u])
			{
				int t = findfather(v);
				ans += (long long)s[t] * vv[k].x;
				printf("K%d %d %lld\n", u, v, (long long)s[t] * vv[k].x);
				sum1 += (long long)s[t] * s[t];
				sum2 += (long long)s[t];
				unionx(u, v);
			}
		}
		ans += (long long)(sum2 * sum2 - sum1) / 2 * vv[k].x;
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		vv[i].x = x;
		vv[i].id = i;
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	printf("%lld\n", query(1) - query(0));
	return 0;
}
