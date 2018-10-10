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

const int _n = 100000 + 10;
int n;
long long l[_n], r[_n];
long long ans;

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		l[i] = read();
		r[i] = read();
		ans += l[i] + r[i] + 1;
	}
	std::sort(l + 1, l + n + 1);
	std::sort(r + 1, r + n + 1);
	for (int i = 1; i <= n; i++)
	{
		ans -= std::min(l[i], r[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
