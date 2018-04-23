#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#pragma G++ optimize (2)
#include <cstdio>

long long read()
{
	char last = '+', ch = getchar();
	while (ch < '0' || ch > '9') last = ch, ch = getchar();
	long long tmp = 0;
	while (ch >= '0' && ch <= '9') tmp = tmp * 10 + ch - 48, ch = getchar();
	if (last == '-') tmp = -tmp;
	return tmp;
}

int n, m;
int x[200000];

int main()
{
	n = read();
	m = read();
	for (register int i = 1; i <= n; i++)
	{
		x[i] = read();
	}
	for (register int i = 1; i <= m; i++)
	{
		register int cas;
		cas = read();
		if (cas == 1)
		{
			register int l, r, k;
			l = read();
			r = read();
			k = read();
			register int j = l;
			for (j = l; j + 7 <= r; j += 8)
			{
				x[j] -= k * (x[j] > k);
				x[j + 1] -= k * (x[j + 1] > k);
				x[j + 2] -= k * (x[j + 2] > k);
				x[j + 3] -= k * (x[j + 3] > k);
				x[j + 4] -= k * (x[j + 4] > k);
				x[j + 5] -= k * (x[j + 5] > k);
				x[j + 6] -= k * (x[j + 6] > k);
				x[j + 7] -= k * (x[j + 7] > k);
			}
			for (; j <= r; j++)
			{
				x[j] -= k * (x[j] > k);
			}
		}
		else
		{
			register int l, r, k;
			l = read();
			r = read();
			k = read();
			register int ans = 0;
			register int j = l;
			for (j = l; j + 7 <= r; j += 8)
			{
				ans += x[j] == k;
				ans += x[j + 1] == k;
				ans += x[j + 2] == k;
				ans += x[j + 3] == k;
				ans += x[j + 4] == k;
				ans += x[j + 5] == k;
				ans += x[j + 6] == k;
				ans += x[j + 7] == k;
			}
			for (; j <= r; j++)
			{
				ans += x[j] == k;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
