#include <cstdio>
#include <cstring>
#include <algorithm>

const int M = 998244353;
int n, m;
long long inv[70];
long long w[2000000];
long long x[2000000];
long long f[4000][70];
long long val[2000000];
long long point[2000000];
long long sum[2000000];

long long pow_mod(long long x, long long p, long long M)
{
	long long ans = 1;
	long long tmp = x;
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

int calc(int x)
{
	return std::lower_bound(point, point + n * m + 1, x) - point;
}

int main()
{
	inv[1] = 1;
	for (int i = 2; i <= 60; i++)
	{
		inv[i] = pow_mod(i, M - 2, M);
	}
	scanf("%d", &n);
	m++;
	w[m] = 0;
	for (int i = 0; i < n; i++)
	{
		double xx;
		scanf("%lf", &xx);
		x[i] = (int)(xx * 1000000 + 0.01);
		m++;
		w[m] = x[i] % 1000000;
	}
	std::sort(w + 1, w + m + 1);
	m = std::unique(w + 1, w + m + 1) - w;
	long long invI = pow_mod(1000000, M - 2, M);
	for (int i = n * m; i >= 0; i--)
	{
		point[i] = (i / m) * 1000000 + w[i % m];
		if (i < n * m)
		{
			val[i] = (long long)(point[i + 1] - point[i]) * invI % M;
		}
	}
	for (int i = std::min(calc(x[0]), m) - 1; i >= 0; i--)
	{
		sum[i] = val[i];
		f[i][1] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		int cut = calc(x[i]);
		for (int j = n * m - 1; j >= 0; j--)
		{
			if (j < cut)
			{
				for (int k = std::max(0, j - m); k < j; k++)
				{
					f[j][0] = (f[j][0] + sum[k]) % M;
				}
				if (j >= m)
				{
					for (int k = 0; k <= n; k++)
					{
						f[j][k] = (f[j][k] - f[j - m][k] + M) % M;
					}
				}
				for (int k = n - 1; k >= 0; k--)
				{
					f[j][k + 1] = f[j][k] * inv[k + 1] % M;
				}
				f[j][0] = sum[j] = 0;
				for (int k = n; k >= 0; k--)
				{
					sum[j] = (sum[j] * val[j] + f[j][k]) % M;
				}
			}
			else
			{
				sum[j] = 0;
				memset(f[j], 0, sizeof(f[j]));
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < n * m; i++)
	{
		ans = (ans + sum[i]) % M;
	}
	printf("%lld\n", ans);
	return 0;
}
