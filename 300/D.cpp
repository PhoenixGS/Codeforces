#include <cstdio>
#include <algorithm>

const int G = 3;
const int M = 7340033;
int n, bit;
int q;
int f[50][20000];
int rev[10000];
int x[10000];

int pow_mod(int x, int p, int M)
{
	p = (p % (M - 1) + M - 1) % (M - 1);
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

void getrev(int bit)
{
	for (int i = 0; i < (1 << bit); i++)
	{
		rev[i] = rev[i >> 1] >> 1 | ((i & 1) << (bit - 1));
	}
}

void NTT(int *x, int cas)
{
	for (int i = 0; i < n; i++)
	{
		if (i < rev[i])
		{
			std::swap(x[i], x[rev[i]]);
		}
	}
	for (int i = 1; i < n; i <<= 1)
	{
		int wn = pow_mod(G, cas * (M - 1) / (i << 1), M);
		for (int j = 0; j < n; j += (i << 1))
		{
			for (int k = 0, w = 1; k < i; k++, w = (long long)w * wn % M)
			{
				int xx = x[j + k];
				int yy = (long long)w * x[j + k + i] % M;
				x[j + k] = (xx + yy) % M;
				x[j + k + i] = ((xx - yy) % M + M) % M;
			}
		}
	}
	if (cas == -1)
	{
		int invn = pow_mod(n, M - 2, M);
		for (int i = 0; i < n; i++)
		{
			x[i] = (long long)x[i] * invn % M;
		}
	}
}

int main()
{
	bit = 13;
	n = 8192;
	getrev(bit);
	f[0][0] = 1;
	for (int i = 1; i <= 40; i++)
	{
		for (int j = 0; j < n; j++)
		{
			x[j] = 0;
		}
		for (int j = 0; j <= 1000; j++)
		{
			x[j] = f[i - 1][j];
		}
		NTT(x, 1);
		for (int j = 0; j < n; j++)
		{
			x[j] = (long long)x[j] * x[j] % M * x[j] % M * x[j] % M;
		}
		NTT(x, -1);
		f[i][0] = 1;
		for (int j = 1; j <= 1000; j++)
		{
			f[i][j] = x[j - 1];
		}
	}
	scanf("%d", &q);
	while (q--)
	{
		int s, k, c;
		scanf("%d%d", &s, &k);
		c = 0;
		while (s % 2 == 1 && s != 1)
		{
			c++;
			s /= 2;
		}
		printf("%d\n", c < 0 ? (k == 0) : f[c][k]);
	}
	return 0;
}
