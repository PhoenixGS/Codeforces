#include <cstdio>

#define mid ((l + r) >> 1)

int n, m;
int num;
int tag[15000000], sum[15000000], ch[15000000][2];
int root;

void newpoint(int &k)
{
	if (! k)
	{
		num++;
		k = num;
		tag[k] = -1;
		sum[k] = 0;
	}
}

void pushdown(int k, int l, int r)
{
	if (tag[k] != -1)
	{
		newpoint(ch[k][0]);
		newpoint(ch[k][1]);
		tag[ch[k][0]] = tag[k];
		sum[ch[k][0]] = tag[k] * (mid - l + 1);
		tag[ch[k][1]] = tag[k];
		sum[ch[k][1]] = tag[k] * (r - mid);
		tag[k] = -1;
	}
}

void pushup(int k)
{
	sum[k] = sum[ch[k][0]] + sum[ch[k][1]];
}

void change(int &k, int l, int r, int L, int R, int newvalue)
{
	newpoint(k);
	if (sum[k] == newvalue * (r - l + 1))
	{
		return;
	}
	if (L <= l && r <= R)
	{
		tag[k] = newvalue;
		sum[k] = newvalue * (r - l + 1);
//		printf("X%d %d %d\n", l, r, sum[k]);
		return;
	}
	pushdown(k, l, r);
	if (L <= mid)
	{
		change(ch[k][0], l, mid, L, R, newvalue);
	}
	if (R > mid)
	{
		change(ch[k][1], mid + 1, r, L, R, newvalue);
	}
	pushup(k);
//	printf("%d %d %d %d\n", k, l, r, sum[k]);
}

int main()
{
	scanf("%d%d", &n, &m);
	num = 0;
	for (int i = 1; i <= m; i++)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		if (k == 1)
		{
			change(root, 1, n, l, r, 1);
		}
		else
		{
			change(root, 1, n, l, r, 0);
		}
		printf("%d\n", n - sum[root]);
	}
	return 0;
}
