#include <cstdio>
#include <cstring>
#include <algorithm>

char st[1005][1005];
int count[20];
int len[1005];
int n;
int m;
int k[1005];
int f[1005][1005];
int x[1005];
int y[1005][1005];
int value[20];
int ans;
int tmp[1005];

int cost(int id, int ll, int key)
{
	return key || len[id] >= ll || len[0] >= ll ? value[key % 10] : 0;
}

void radixsort(int pos)
{
	memset(count, 0, sizeof(count));
	for (int i = 1; i <= m; i++)
	{
		count[y[k[i]][pos]]++;
	}
	for (int i = 8; i >= 0; i--)
	{
		count[i] = count[i + 1] + count[i];
	}
	for (int i = m; i >= 1; i--)
	{
		tmp[count[y[k[i]][pos]]] = k[i];
		count[y[k[i]][pos]]--;
	}
	for (int i = 1; i <= m; i++)
	{
		k[i] = tmp[i];
	}
}

int main()
{
	scanf("%s", st[0] + 1);
	len[0] = strlen(st[0] + 1);
	n = len[0];
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%s", st[i] + 1);
		len[i] = strlen(st[i] + 1);
		n = std::max(n, (int)strlen(st[i] + 1));
	}
	n++;
	for (int i = 1; i <= len[0]; i++)
	{
		if (st[0][i] == '?')
		{
			x[i + n - len[0]] = -1;
		}
		else
		{
			x[i + n - len[0]] = st[0][i] - '0';
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= len[i]; j++)
		{
			y[i][j + n - len[i]] = st[i][j] - '0';
		}
	}
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &value[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			f[i][j] = -1000000000;
		}
	}
	if (x[n] == -1)
	{
		for (int i = 0; i < 10; i++)
		{
			int cnt = 0;
			int total = 0;
			for (int j = 1; j <= m; j++)
			{
				if (i + y[j][n] >= 10)
				{
					cnt++;
				}
				total += value[(i + y[j][n]) % 10];
			}
			f[n][cnt] = std::max(f[n][cnt], total);
		}
	}
	else
	{
		int cnt = 0;
		int total = 0;
		for (int j = 1; j <= m; j++)
		{
			if (x[n] + y[j][n] >= 10)
			{
				cnt++;
			}
			total += value[(x[n] + y[j][n]) % 10];
		}
		f[n][cnt] = std::max(f[n][cnt], total);
	}
	for (int i = 1; i <= m; i++)
	{
		k[i] = i;
	}
	for (int i = n - 1; i >= 1; i--)
	{
		radixsort(i + 1);
		int l, r;
		if (x[i] == -1)
		{
			l = 0;
			if (n - i + 1 == len[0])
			{
				l = 1;
			}
			r = 9;
		}
		else
		{
			l = r = x[i];
		}
		for (int c = l; c <= r; c++)
		{
			int cnt = 0;
			int total = 0;
			for (int j = 1; j <= m; j++)
			{
				total += std::max(len[j], len[0]) >= n - i + 1 ? value[(y[j][i] + c) % 10] : 0;
				cnt += y[j][i] + c >= 10;
			}
			for (int now = 1; now <= m + 1; now++)
			{
				f[i][cnt] = std::max(f[i][cnt], f[i + 1][now - 1] + total);
				total -= cost(k[now], n - i + 1, y[k[now]][i] + c);
				total += cost(k[now], n - i + 1, y[k[now]][i] + c + 1);
				cnt += y[k[now]][i] + c + 1 == 10;
			}
		}
	}
	ans = 0;
	for (int i = 0; i <= m; i++)
	{
		ans = std::max(ans, f[1][i]);
	}
	printf("%d\n", ans);
	return 0;
}
