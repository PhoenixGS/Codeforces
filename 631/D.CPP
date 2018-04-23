#include <cstdio>

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d-%c", &x[i], &s[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d-%c", &y[i], &t[i]);
	}
}
