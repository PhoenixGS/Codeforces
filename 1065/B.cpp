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

long long n, m;

int main()
{
	n = read();
	m = read();
	printf("%lld ", std::max(0ll, n - 2 * m));
	for (long long i = 0; i <= n; i++)
	{
		if (i * (i - 1) / 2 >= m)
		{
			printf("%lld\n", n - i);
			return 0;
		}
	}
	return 0;
}
