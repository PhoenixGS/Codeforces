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

int T;
long long s, a, b, c;

int main()
{
	T = read();
	while (T--)
	{
		s = read();
		a = read();
		b = read();
		c = read();
		printf("%lld\n", s / c + s / c / a * b);
	}
	return 0;
}
