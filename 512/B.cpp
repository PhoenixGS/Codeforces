#include <cstdio>
#include <map>
#include <cmath>

long long read()
{
	char last = '+', ch = getchar();
	while (ch < '0' || ch > '9') last = ch, ch = getchar();
	long long tmp = 0;
	while (ch >= '0' && ch <= '9') tmp = tmp * 10 + ch - 48, ch = getchar();
	if (last == '-') tmp = -tmp;
	return tmp;
}

int knum;
int n;
std::map<int, int> map;
int knumber[20000000];
int x[1000];
int cost[1000];
int f[305][100000];

int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}

void add(int x)
{
	if (map.find(x) != map.end())
	{
		return;
	}
	//printf("%d\n", x);
	knum++;
	map[x] = knum;
	knumber[knum] = x;
}

int main()
{
	knum = 0;
	n = read();
	for (int i = 1; i <= n; i++)
	{
		x[i] = read();
	}
	for (int i = 1; i <= n; i++)
	{
		cost[i] = read();
	}
	add(1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <= sqrt(x[i]); j++)
		{
			if (x[i] % j == 0)
			{
				add(j);
				if (j * j != x[i])
				{
					add(x[i] / j);
				}
			}
		}
		add(x[i]);
	}
	for (int i = 1; i <= knum; i++)
	{
		f[0][i] = 1000000000;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= knum; j++)
		{
			f[i][j] = f[i - 1][j];
		}
		for (int j = 1; j <= knum; j++)
		{
			f[i][map[gcd(knumber[j], x[i])]] = std::min(f[i][map[gcd(knumber[j], x[i])]], f[i - 1][j] + cost[i]);
		}
		f[i][map[x[i]]] = std::min(f[i][map[x[i]]], cost[i]);
	}
	if (f[n][map[1]] == 1000000000)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", f[n][map[1]]);
	}
	return 0;
}

