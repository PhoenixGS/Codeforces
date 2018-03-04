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

const long long INF = 1e18;
long long n, L;
long long x[1000];
long long ans;

int main()
{
	n = read();
	L = read();
	for (int i = 1; i <= 33; i++)
	{
		x[i] = INF;
	}
	for (int i = 1; i <= n; i++)
	{
		x[i] = read();
	}
	n = 33;
	for (int i = 2; i <= n; i++)
	{
		x[i] = std::min(x[i - 1] * 2, x[i]);
	}
	for (int i = n - 1; i >= 1; i--)
	{
		x[i] = std::min(x[i], x[i + 1]);
	}
	for (int i = 2; i <= n; i++)
	{
		x[i] = std::min(x[i - 1] * 2, x[i]);
	}
	for (int i = n - 1; i >= 1; i--)
	{
		x[i] = std::min(x[i], x[i + 1]);
	}
	long long now = 0;
	for (int i = 1; i < n; i++)
	{
		if (L & (1 << (i - 1)))
		{
			now = now + x[i];
		}
		now = std::min(now, x[i + 1]);
	}
	printf("%lld\n", now);
	return 0;
}
