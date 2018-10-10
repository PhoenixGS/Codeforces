#include <cstdio>

long long n;
int ans;

int main()
{
	scanf("%lld", &n);
	long long now = 0;
	while (now * 10 + 9 <= n)
	{
		now = now * 10 + 9;
		ans += 9;
	}
	n = n - now;
	while (n)
	{
		ans += n % 10;
		n = n / 10;
	}
	printf("%d\n", ans);
	return 0;
}
