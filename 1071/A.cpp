#include <cstdio> 

int x, y;
int n;
int flag[100000];
int cnt;

int main()
{
	scanf("%d%d", &x, &y);
	for (n = 0; (long long)(n + 1) * (n + 2) / 2 <= (long long)x + y; n++);
	for (int i = n; i >= 1; i--)
	{
		if (i <= x)
		{
			cnt++;
			flag[i] = 1;
			x -= i;
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++)
	{
		if (flag[i])
		{
			printf("%d ", i);
		}
	}
	puts("");
	printf("%d\n", n - cnt);
	for (int i = 1; i <= n; i++)
	{
		if (! flag[i])
		{
			printf("%d ", i);
		}
	}
	puts("");
	return 0;
}
