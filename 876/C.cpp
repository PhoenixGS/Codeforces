#include <cstdio>
#include <algorithm>

int n;
int cnt;
int ans[100000];

int calc(int x)
{
	int ans = 0;
	while (x)
	{
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	cnt = 0;
	for (int i = 0; i <= std::min(100, n); i++)
	{
		if (calc(n - i) == i)
		{
			cnt++;
			ans[cnt] = n - i;
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
	{
		printf("%d\n", ans[cnt - i + 1]);
	}
	return 0;
}
