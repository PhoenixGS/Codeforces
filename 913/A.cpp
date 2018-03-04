#include <cstdio>

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
	if (n >= 27)
	{
		printf("%lld\n", m);
	}
	else
	{
		printf("%lld\n", m % (1 << n));
	}
	return 0;
}
