#include <cstdio>
#include <algorithm>

using namespace std;

struct T
{
	int l, r, cost, len;
};

int n, X;
T x[300000];
int f[300000][20];
int ans;

bool comp(T x, T y)
{
	return x.len < y.len || (x.len == y.len && x.l < y.l);
}

int binary_find1(int l, int r, int key)
{
	if (l == r)
	{
		return l;
	}
	int mid = (l + r) >> 1;
	if (x[mid].len >= key)
	{
		return binary_find1(l, mid, key);
	}
	else
	{
		return binary_find1(mid + 1, r, key);
	}
}

int binary_find2(int l, int r, int key)
{
	if (l == r)
	{
		return l;
	}
	int mid = (l + r + 1) >> 1;
	if (x[mid].len <= key)
	{
		return binary_find2(mid, r, key);
	}
	else
	{
		return binary_find2(l, mid - 1, key);
	}
}

int binary_find3(int l, int r, int key)
{
	if (l == r)
	{
		return l;
	}
	int mid = (l + r) >> 1;
	if (x[mid].l <= key)
	{
		return binary_find3(mid + 1, r, key);
	}
	else
	{
		return binary_find3(l, mid, key);
	}
}

int calc(int l, int r)
{
	int k = 0;
	while (l + (1 << (k + 1)) - 1 <= r)
	{
		k++;
	}
	return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
	scanf("%d%d", &n, &X);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &x[i].l, &x[i].r, &x[i].cost);
		x[i].len = x[i].r - x[i].l + 1;
	}
	ans = 2100000000;
	sort(x + 1, x + n + 1, comp);
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = x[i].cost;
	}
	for (int cas = 1; cas <= 18; cas++)
	{
		for (int i = 1; i + (1 << cas) - 1 <= n; i++)
		{
			f[i][cas] = min(f[i][cas - 1], f[i + (1 << (cas - 1)) - 1][cas - 1]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (X - x[i].len < x[1].len || X - x[i].len > x[n].len)
		{
			continue;
		}
		int l = binary_find1(1, n, X - x[i].len);
		int r = binary_find2(1, n, X - x[i].len);
		if (x[l].len != X - x[i].len || x[r].len != X - x[i].len)
		{
			continue;
		}
		if (l > r)
		{
			continue;
		}
		if (x[r].l <= x[i].r)
		{
			continue;
		}
		int xx = binary_find3(l, r, x[i].r);
		int tmp = x[i].cost + calc(xx, r);
		ans = min(ans, tmp);
	}
	if (ans == 2100000000)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", ans);
	}
	return 0;
}
