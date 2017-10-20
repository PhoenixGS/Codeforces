#include <cstdio>
#include <cstring>

int n, m;
int x[200];
int ans[200];
int ff[200];
int last;
int stack[200];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &x[i]);
	}
	bool flag = true;
	memset(ans, -1, sizeof(ans));
	memset(ff, -1, sizeof(ff));
	for (int i = 1; i < m; i++)
	{
		int tmp = ((x[i + 1] - x[i]) % n + n) % n;
		if ((ans[x[i]] != -1 && ans[x[i]] != tmp) || (ff[tmp] != -1 && ff[tmp] != x[i]))
		{
			flag = false;
			break;
		}
		ans[x[i]] = tmp;
		ff[tmp] = x[i];
	}
	if (! flag)
	{
		printf("-1\n");
		return 0;
	}
	last = 0;
	for (int i = 0; i < n; i++)
	{
		if (ff[i] == -1)
		{
			last++;
			stack[last] = i;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == -1)
		{
			ans[i] = stack[last];
			last--;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (ans[i] == 0)
		{
			printf("%d ", n);
		}
		else
		{
			printf("%d ", ans[i]);
		}
	}
	if (ans[n] == 0)
	{
		printf("%d ", n);
	}
	else
	{
		printf("%d ", ans[n]);
	}
	printf("\n");
	return 0;
}
