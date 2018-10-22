#include <cstdio>

void dfs(int k, int cas)
{
	if (k > 2)
	{
		return;
	}
	f[cas] = std::min(f[cas], k);
	dfs(k + 1, cas ^ 7);
	dfs(k + 1, cas ^ )
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		x[i] = read();
	}
	for (int i = 0; i < (1 << 6); i++)
	{
		f[i] = INF;
	}
	dfs(0, 0);
}
