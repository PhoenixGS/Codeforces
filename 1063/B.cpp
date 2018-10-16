#include <cstdio>
#include <queue>

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
const int INF = 1000000000;
const int _n = 2000 + 10, _m = 2000 + 10;
int n, m;
int sx, sy;
int liml, limr;
char s[_m];
int map[_n][_m];
bool flag[_n * _m];
int dis[_n * _m];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > que;
int ans;

int getid(int x, int y)
{
	return (x - 1) * m + y;
}

int getx(int id)
{
	return (id - 1) / m + 1;
}

int gety(int id)
{
	return (id - 1) % m + 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%d%d", &sx, &sy);
	scanf("%d%d", &liml, &limr);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = s[j] == '*' ? 1 : 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dis[getid(i, j)] = INF;
		}
	}
	dis[getid(sx, sy)] = 0;
	que.push(std::make_pair(0, getid(sx, sy)));
	while (! que.empty())
	{
		int u = que.top().second;
		que.pop();
		if (flag[u])
		{
			continue;
		}
		flag[u] = 1;
		int xx = getx(u);
		int yy = gety(u);
		for (int k = 0; k < 4; k++)
		{
			int xxx = xx + dx[k];
			int yyy = yy + dy[k];
			if (xxx >= 1 && xxx <= n && yyy >= 1 && yyy <= m && ! map[xxx][yyy])
			{
				int v = getid(xxx, yyy);
				int sl = dis[u] + (k == 0);
				int sr = yyy - sy + sl;
				if (sl <= liml && sr <= limr)
				{
					if (sl < dis[v])
					{
						dis[v] = sl;
						que.push(std::make_pair(dis[v], v));
					}
				}
			}
		}
	}
	ans = 0;
	for (int i = 1; i <= n * m; i++)
	{
		if (dis[i] != INF)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
