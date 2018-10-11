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

const int INF = 1000000000;
const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int _n = 10 + 2;
int n;
int x[_n][_n];
int posx[_n * _n], posy[_n * _n];
int f[2 * _n * _n][_n][_n][_n * _n][3];
int ans;

void update(int t, int i, int j, int l, int c, int newv)
{
//	printf("G%d %d %d %d %d %d\n", t, i, j, l, c, f[t][i][j][l][c]);
	f[t][i][j][l][c] = std::min(f[t][i][j][l][c], newv);
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			x[i][j] = read();
			posx[x[i][j]] = i;
			posy[x[i][j]] = j;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k <= 2 * n * n + 1; k++)
			{
				for (int l = 1; l <= n * n; l++)
				{
					for (int c = 0; c < 3; c++)
					{
						f[k][i][j][l][c] = INF;
					}
				}
			}
		}
	}
	ans = INF;
	f[0][posx[1]][posy[1]][1][0] = 0;
	f[0][posx[1]][posy[1]][1][1] = 0;
	f[0][posx[1]][posy[1]][1][2] = 0;
	for (int t = 0; t <= 2 * n * n; t++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int l = 1; l <= n * n; l++)
				{
//					if (f[t][i][j][l][0] != INF) printf("%d %d %d %d %d %d\n", t, i, j, l, 0, f[t][i][j][l][0]);
//					if (f[t][i][j][l][1] != INF) printf("%d %d %d %d %d %d\n", t, i, j, l, 1, f[t][i][j][l][1]);
//					if (f[t][i][j][l][2] != INF) printf("%d %d %d %d %d %d\n", t, i, j, l, 2, f[t][i][j][l][2]);
					if (l == n * n)
					{
						ans = std::min(ans, f[t][i][j][l][0]);
						ans = std::min(ans, f[t][i][j][l][1]);
						ans = std::min(ans, f[t][i][j][l][2]);
					}
					for (int jj = 1; jj <= n; jj++)
					{
						update(t + 1, i, jj, l + (x[i][jj] == l + 1), 0, f[t][i][j][l][0]);
					}
					for (int ii = 1; ii <= n; ii++)
					{
						update(t + 1, ii, j, l + (x[ii][j] == l + 1), 0, f[t][i][j][l][0]);
					}
					update(t + 1, i, j, l, 1, f[t][i][j][l][0] + 1);
					update(t + 1, i, j, l, 2, f[t][i][j][l][0] + 1);
					for (int jj = 1; jj <= n; jj++)
					{
						int ii = jj - j + i;
						if (ii >= 1 && ii <= n)
						{
							update(t + 1, ii, jj, l + (x[ii][jj] == l + 1), 1, f[t][i][j][l][1]);
						}
					}
					for (int jj = 1; jj <= n; jj++)
					{
						int ii = j - jj + i;
						if (ii >= 1 && ii <= n)
						{
							update(t + 1, ii, jj, l + (x[ii][jj] == l + 1), 1, f[t][i][j][l][1]);
						}
					}
					update(t + 1, i, j, l, 0, f[t][i][j][l][1] + 1);
					update(t + 1, i, j, l, 2, f[t][i][j][l][1] + 1);
					for (int kk = 0; kk < 8; kk++)
					{
						int ii = i + dx[kk];
						int jj = j + dy[kk];
						if (ii >= 1 && ii <= n && jj >= 1 && jj <= n)
						{
//							printf("K%d %d %d %d\n", i, j, ii, jj);
							update(t + 1, ii, jj, l + (x[ii][jj] == l + 1), 2, f[t][i][j][l][2]);
						}
					}
					update(t + 1, i, j, l, 0, f[t][i][j][l][2] + 1);
					update(t + 1, i, j, l, 1, f[t][i][j][l][2] + 1);
				}
			}
		}
		if (ans != INF)
		{
			printf("%d %d\n", t, ans);
			return 0;
		}
	}
	return 0;
}
