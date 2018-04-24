#include <cstdio>
#include <cmath>
#include <algorithm>

struct Complex
{
	double real, imag;

	Complex(){}

	Complex(double _real, double _imag): real(_real), imag(_imag){}
};

const int M = 1009;
const double pi = acos(-1);
int n, m, k;
int x[600000];
int* point[600000];
int v[600000];
Complex xx[600000], yy[600000];
int rev[600000];

Complex operator + (Complex x, Complex y)
{
	return Complex(x.real + y.real, x.imag + y.imag);
}

Complex operator - (Complex x, Complex y)
{
	return Complex(x.real - y.real, x.imag - y.imag);
}

Complex operator * (Complex x, Complex y)
{
	return Complex(x.real * y.real - x.imag * y.imag, x.real * y.imag + x.imag * y.real);
}

void getrev(int bit)
{
	for (int i = 0; i < (1 << bit); i++)
	{
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
	}
}

void FFT(Complex *x, int n, int f)
{
	for (int i = 1; i < n; i <<= 1)
	{
		Complex wn(cos(pi / i), f * sin(pi / i));
		for (int j = 0; j < n; j += (i << 1))
		{
			Complex w(1, 0);
			for (int k = 0; k < i; k++, w = w * wn)
			{
				Complex xx = x[j + k];
				Complex yy = w * x[j + k + i];
				x[j + k] = xx + yy;
				x[j + k + i] = xx - yy;
			}
		}
	}
	if (f == -1)
	{
		for (int i = 0; i < n; i++)
		{
			x[i].real /= n;
			x[i].imag /= n;
		}
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
	int n = point[mid + 1] - point[l];
	int m = point[r + 1] - point[mid + 1];
	int s = 1, bit = 9;
	for (s = 1, bit = 0; s <= n + m; s <<= 1, bit++);
	for (int i = 0; i < s; i++)
	{
		xx[i] = yy[i] = Complex(0, 0);
	}
	puts("X");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", (point[l])[i]);
		xx[i] = Complex((point[l])[i], 0);
	}
	puts("");
	puts("Y");
	for (int i = 0; i < m; i++)
	{
		printf("%d ", (point[mid + 1])[i]);
		yy[i] = Complex((point[mid + 1])[i], 0);
	}
	puts("");
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
		(point[l])[i] = (long long)(xx[i].real + 0.5) % M;
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
	int s = 0;
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
	printf("%d\n", (point[1])[k]);
	return 0;
}
