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

const long long _n = 200000 + 10, _h = 200000 + 10;
long long n, k;
int x[_n];
int s[_h];
long long ans, now;

int main()
{
	n = read();
	k = read();
	for (int i = 1; i <= n; i++)
	{
		x[i] = read();
		s[x[i]]++;
	}
	for (int i = _h; i >= 0; i--)
	{
		s[i] = s[i + 1] + s[i];
	}
	now = 0;
	ans = 0;
	for (int i = _h; i >= 0; i--)
	{
		if (s[i] == n)
		{
			break;
		}
		if (now + s[i] > k)
		{
			ans++;
			now = s[i];
		}
		else
		{
			now += s[i];
		}
	}
	if (now)
	{
		ans++;
	}
	printf("%lld\n", ans);
	return 0;
}
