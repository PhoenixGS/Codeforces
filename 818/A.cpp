#include <cstdio>

long long n, k;

int main()
{
	scanf("%lld%lld", &n, &k);
	long long tmp = (n / 2) / (1 + k);
	long long x = tmp;
	long long y = tmp * k;
	long long z = n - x - y;
	printf("%lld %lld %lld\n", x, y, z);
	return 0;
}
