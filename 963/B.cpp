#include <cstdio>

int n;
int fa[300000];
int degree[300000];
int cnt[300000];
int ansn;
int ans[300000];
int head, tail;
int que[300000];
int flag[300000];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &fa[i]);
		degree[fa[i]]++;
		if (fa[i])
		{
			cnt[fa[i]]++;
			cnt[i]++;
		}
	}
	if ((n & 1) == 0)
	{
		puts("NO");
		return 0;
	}
	head = 1;
	tail = 0;
	for (int i = 1; i <= n; i++)
	{
		if (! degree[i])
		{
			tail++;
			que[tail] = i;
		}
	}
	ansn = 0;
	while (head <= tail)
	{
		int u = que[head];
		head++;
		if ((cnt[u] & 1) == 0)
		{
			cnt[fa[u]]--;
			ansn++;
			ans[ansn] = u;
			flag[u] = 1;
		}
		degree[fa[u]]--;
		if (! degree[fa[u]])
		{
			tail++;
			que[tail] = fa[u];
		}
	}
	for (int i = n; i >= 1; i--)
	{
		if (! flag[que[i]])
		{
			ansn++;
			ans[ansn] = que[i];
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}
