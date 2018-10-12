#include <cstdio>
#include <cmath>

int n, m, k;
int d;
int ansn, ansm;

long long gcd(long long x, long long y)
{
	return y == 0 ? x : gcd(y, x % y);
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	ansn = n;
	ansm = m;
	d = gcd(n, k);
	ansn /= d;
	k /= d;
	d = gcd(m, k);
	ansm /= d;
	k /= d;
	if (k != 1 && k != 2)
	{
		puts("NO");
		return 0;
	}
	if (k == 1)
	{
		if (ansn != n)
		{
			ansn *= 2;
		}
		else
		{
			ansm *= 2;
		}
	}
	puts("YES");
	printf("%d %d\n", 0, 0);
	printf("%d %d\n", ansn, 0);
	printf("%d %d\n", 0, ansm);
	return 0;
}
