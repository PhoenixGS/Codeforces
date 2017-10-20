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

long long n, k;
long long f[2000000];
long long fac[2000000];
long long up;
long long ans;
const long long M = 1e9 + 7;

long long pow_mod(long long x, long long p, long long M)
{
	long long tmp = x % M;
	long long ans = 1;
	while (p)
	{
		if (p & 1)
		{
			ans = ans * tmp % M;
		}
		tmp = tmp * tmp % M;
		p >>= 1;
	}
	return ans;
}

int main()
{
	n = read();
	k = read();
	for (int i = 1; i <= k + 1; i++)
	{
		f[i] = (f[i - 1] + pow_mod(i * 1ll, k, M)) % M;
	}
	if (n <= k + 1)
	{
		printf("%lld\n", f[n]);
		return 0;
	}
	fac[0] = 1;
	for (int i = 1; i <= k + 1; i++)
	{
		fac[i] = (fac[i - 1] * i) % M;
	}
	up = 1;
	ans = 0;
	for (int i = 0; i <= k + 1; i++)
	{
		up = (up * (n - i)) % M;
	}
	for (int i = 0; i <= k + 1; i++)
	{
		long long inv1 = pow_mod(n - i, M - 2, M);
		long long inv2 = pow_mod(fac[i] * fac[k + 1 - i] % M, M - 2, M);
		long long sign = ((k + 1 - i) & 1) ? -1 : 1;
		(ans += sign * inv1 * inv2 % M * f[i] % M * up % M) %= M;
	}
	ans = (ans + M) % M;
	printf("%lld\n", ans);
	return 0;
}
