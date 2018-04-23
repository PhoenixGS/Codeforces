#include <cstdio>

void getrev(int bit)
{
	for (int i = 0; i < (1 << bit); i++)
	{
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
	}
}

void FFT(int *x, int n, int f)
{
	for (int i = 1; i < n; i <<= 1)
	{

	}
}

void solve(int l, int r)
{
	if (l == r)
	{
		return;
	}
	int mid = (l + r) >> 1;
	solve(l, mid);
	solve(mid + 1, r);
	int n = point[mid + 1] - v[l];
	int m = point[r + 1] - v[mid + 1];
	int s = 1, bit = 9;
	for (s = 1, bit = 0; s <= n + m; s <<= 1, bit++);
	for (int i = 0; i < s; i++)
	{
		xx[i] = yy[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		xx[i] = (point[l])[i];
	}
	for (int i = 0; i < m; i++)
	{
		yy[i] = (point[mid + 1])[i];
	}
	getrev(bit);
	FFT(xx, s, 1);
	FFT(yy, s, 1);
	for (int i = 0; i < n; i++)
	{
		xx[i] = xx[i] * yy[i];
	}
	FFT(xx, s, -1);
	for (int i = 0; i < n; i++)
	{
		(point[l])[i] = (long long)(xx[i] + 0.5) % M;
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
	}
	std::sort(x + 1, x + n + 1);
	int cnt = 1;
	int last = 0;
	s = 0;
	for (int i = 2; i <= n; i++)
	{
		if (x[i] != x[i - 1])
		{
			s++;
			point[s] = x + last;
			for (int j = 0; j <= cnt; j++)
			{
				v[last] = 1;
				last++;
			}
			cnt = 1;
		}
		else
		{
			cnt++;
		}
	}
	s++;
	point[s] = x + last;
	for (int j = 0; j <= cnt; j++)
	{
		v[last] = 1;
		last++;
	}
	point[s + 1] = point[s] + 1;
	cnt = 1;
	solve(1, s);
}
