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

struct node
{
	int key1, key2, pos;
};

const int INF = 1000000000;
const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
const int _n = 2000 + 10;
int n, m;
char map[_n][_n];
int f[_n][_n];
int ans;
int ansx, ansy;
int last;
int vx[_n], vy[_n];
node v[_n];
int rank[_n][_n], mmmm[_n][_n];

bool comp(node x, node y)
{
	return x.key1 < y.key1 || (x.key1 == y.key1 && x.key2 < y.key2);
}

int main()
{
	n = read();
	m = read();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", map[i] + 1);
	}
	for (int i = 0; i <= n; i++)
	{
		f[i][0] = f[0][i] = INF;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == 1 && j == 1)
			{
				f[i][j] = map[i][j] != 'a';
			}
			else
			{
				f[i][j] = std::min(f[i - 1][j], f[i][j - 1]) + (map[i][j] != 'a');
			}
		}
	}
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (m >= f[i][j])
			{
				ans = std::max(ans, i + j - 1);
			}
		}
	}
	for (int i = 2 * n - 1; i >= 1; i--)
	{
		int sx, sy;
		if (i > n)
		{
			sx = n;
			sy = 1 + i - n;
		}
		else
		{
			sx = i;
			sy = 1;
		}
		last = 0;
		for (int i = 0; ; i++)
		{
			int xx = sx - i;
			int yy = sy + i;
			if (xx < 1 || xx > n || yy < 1 || yy > n)
			{
				break;
			}
			last++;
			vx[last] = xx;
			vy[last] = yy;
		}
		for (int i = 1; i <= last; i++)
		{
			int minx = INF;
			for (int k = 0; k < 2; k++)
			{
				int xx = vx[i] + dx[k];
				int yy = vy[i] + dy[k];
				if (xx >= 1 && xx <= n && yy >= 1 && yy <= n)
				{
					minx = std::min(minx, rank[xx][yy]);
				}
			}
			v[i].key1 = map[vx[i]][vy[i]];
			v[i].key2 = minx;
			v[i].pos = i;
		}
		std::sort(v + 1, v + last + 1, comp);
		for (int i = 1; i <= last; i++)
		{
			rank[vx[v[i].pos]][vy[v[i].pos]] = i;
			mmmm[vx[v[i].pos]][vy[v[i].pos]] = v[i].key2;
		}
	}
	for (int i = 1; i <= ans; i++)
	{
		putchar('a');
	}
	int ansx = -1, ansy = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (m >= f[i][j] && i + j - 1 == ans)
			{
				if (ansx == -1)
				{
					ansx = i;
					ansy = j;
				}
				else
				{
					if (mmmm[i][j] < mmmm[ansx][ansy])
					{
						ansx = i;
						ansy = j;
					}
				}
			}
		}
	}
	if (ans == 0)
	{
		ansx = 1;
		ansy = 1;
		putchar(map[1][1]);
	}
	while (! (ansx == n && ansy == n))
	{
		if (ansx == n)
		{
			ansy++;
		}
		else
		{
			if (ansy == n)
			{
				ansx++;
			}
			else
			{
				if (rank[ansx + 1][ansy] < rank[ansx][ansy + 1])
				{
					ansx++;
				}
				else
				{
					ansy++;
				}
			}
		}
		putchar(map[ansx][ansy]);
	}
	puts("");
	return 0;
}
