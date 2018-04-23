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

int n, m;
long long t, M;
long long x[2000000], k[2000000];
long long v[100];
int cnt[2000000];

long long c(long long x, long long y)
{
	x = ((x * y - ((long long)((long double)x / M * y)) * M) % M + M) % M;
	return x;
}

void FWT(long long *x)
{
	for (int i = 1; i < n; i <<= 1)
	{
		for (int j = 0; j < n; j += (i << 1))
		{
			for (int k = 0; k < i; k++)
			{
				long long xx = x[j + k];
				long long yy = x[j + k + i];
				x[j + k] = (xx + yy) % M;
				x[j + k + i] = (xx - yy + M) % M;
			}
		}
	}
}

long long pow_mod(long long x, long long p, long long ff)
{
	long long ans = ff;
	long long tmp = x;
	while (p)
	{
		if (p & 1)
		{
			ans = c(ans, tmp);
		}
		tmp = c(tmp, tmp);
		p >>= 1;
	}
	return ans;
}

int main()
{
	m = read();
	t = read();
	M = read();
	n = (1 << m);
	M = M * n;
	for (int i = 0; i < n; i++)
	{
		x[i] = read();
	}
	for (int i = 0; i <= m; i++)
	{
		v[i] = read();
	}
	for (int i = 0; i < n; i++)
	{
		cnt[i] = cnt[i >> 1] + (i & 1);
		k[i] = v[cnt[i]];
	}
	FWT(x);
	FWT(k);
	for (int i = 0; i < n; i++)
	{
		//x[i] = c(pow_mod(k[i], t), x[i]);
		x[i] = pow_mod(k[i], t, x[i]);
	}
	FWT(x);
	M = M / n;
	for (int i = 0; i < n; i++)
	{
		printf("%lld\n", (x[i] / n % M + M) % M);
	}
	return 0;
}
