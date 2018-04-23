#include <cstdio>
#include <algorithm>

int n, k, ans;

int main()
{
	scanf("%d%d", &n, &k);
	ans = 1000000000;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (k % x == 0)
		{
			ans = std::min(ans, k / x);
		}
	}
	printf("%d\n", ans);
	return 0;
}
