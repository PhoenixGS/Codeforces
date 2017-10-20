#include <cstdio>
#include <algorithm>

using namespace std;

struct T
{
	int id, k, pos;
};

T x[500000];
int kk[300000];
int l[300000];
int r[300000];
int cost[300000];
int ans;
int last;
int n, X;

bool comp(T x, T y)
{
	return x.pos < y.pos || (x.pos == y.pos && x.k < y.k);
}

int main()
{
	scanf("%d%d", &n, &X);
	for (int i = 1; i <= 200000; i++)
	{
		kk[i] = 2100000000;
	}
	last = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &l[i], &r[i], &cost[i]);
		last++;
		x[last].id = i;
		x[last].k = 0;
		x[last].pos = l[i];
		last++;
		x[last].id = i;
		x[last].k = 1;
		x[last].pos = r[i];
	}
	sort(x + 1, x + last + 1, comp);
	ans = 2100000000;
	for (int i = 1; i <= last; i++)
	{
		int kkk = x[i].id;
		int len = r[kkk] - l[kkk] + 1;
		if (x[i].k == 0)
		{
			int rest = X - len;
			if (rest <= 0 || kk[rest] == 2100000000)
			{
				continue;
			}
			ans = min(ans, cost[kkk] + kk[rest]);
		}
		else
		{
			kk[len] = min(kk[len], cost[kkk]);
		}
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
