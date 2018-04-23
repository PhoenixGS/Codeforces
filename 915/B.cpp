#include <cstdio>
#include <algorithm>

int n, pos, l, r;

int abss(int x)
{
	return x < 0 ? -x : x;
}

int main()
{
	scanf("%d%d%d%d", &n, &pos, &l, &r);
	if (l == 1 && r == n)
	{
		printf("0\n");
		return 0;
	}
	if (l == 1)
	{
		printf("%d\n", abss(pos - r) + 1);
		return 0;
	}
	if (r == n)
	{
		printf("%d\n", abss(pos - l) + 1);
		return 0;
	}
	printf("%d\n", std::min(abss(pos - l) + abss(l - r) + 2, abss(pos - r) + abss(l - r) + 2));
	return 0;
}
