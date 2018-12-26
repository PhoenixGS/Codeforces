#include <cstdio>
#include <cstring>
#include <algorithm>

const int _n = 5000 + 10, _x = 100000 + 10;
int n;
int x[_n];
int pre[_x], mod[10];
int f[_n][_n];
int ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
	}
	for (int i = 0; i <= n; i++)
	{
		memset(pre, 0, sizeof(pre));
		memset(mod, 0, sizeof(mod));
		for (int j = 0; j < i; j++)
		{
			pre[x[j]] = std::max(pre[x[j]], f[i][j]);
			mod[x[j] % 7] = std::max(mod[x[j] % 7], f[i][j]);
		}
		for (int j = i + 1; j <= n; j++)
		{
			f[i][j] = std::max(f[i][j], f[i][0] + 1);
			f[i][j] = std::max(f[i][j], pre[x[j] - 1] + 1);
			f[i][j] = std::max(f[i][j], pre[x[j] + 1] + 1);
			f[i][j] = std::max(f[i][j], mod[x[j] % 7] + 1);
			pre[x[j]] = std::max(pre[x[j]], f[i][j]);
			mod[x[j] % 7] = std::max(mod[x[j] % 7], f[i][j]);
			f[j][i] = f[i][j];
			ans = std::max(ans, f[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
