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

const int M = 998244353;
int K;
int n, m, c;
int x[300000];
int d;
int tmp;
int ans;

int pow_mod(int x, int p, int M)
{
	int ans = 1;
	int tmp = x;
	while (p)
	{
		if (p & 1)
		{
			ans = (long long)ans * tmp % M;
		}
		tmp = (long long)tmp * tmp % M;
		p >>= 1;
	}
	return ans;
}

int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}

int C(int n, int m)
{
	printf("G%d %d\n", n, m);
	int ans = 1;
	int t = 1;
	for (int i = 1; i <= n; i++)
	{
		t = (long long)t * i % M;
	}
	ans = (long long)ans * t % M;
	t = 1;
	for (int i = 1; i <= m; i++)
	{
		t = (long long)t * i % M;
	}
	ans = (long long)ans * pow_mod(t, M - 2, M) % M;
	t = 1;
	for (int i = 1; i <= n - m; i++)
	{
		t = (long long)t * i % M;
	}
	ans = (long long)ans * pow_mod(t, M - 2, M) % M;
	return ans;
}

int main()
{
	K = pow_mod(2, M - 2, M);
	n = read();
	m = read();
	c = read();
	for (int i = 1; i <= m; i++)
	{
		x[i] = read();
	}
	ans = 1;
	d = x[1];
	for (int i = 2; i <= m; i++)
	{
		d = gcd(d, x[i]);
	}
	tmp = pow_mod(c, d, M);
	tmp = (long long)tmp * (tmp + 1) % M * K % M;
	printf("%d\n", tmp);
	//ans = (long long)ans * pow_mod(tmp, x[m] / d, M) % M;
	ans = C(x[m] / d + tmp - 1, tmp - 1);
	ans = (long long)ans * pow_mod(c, n - 2 * x[m], M) % M;
	printf("%d\n", ans);
	return 0;
}
