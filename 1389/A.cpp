#include <cstdio>

int T;
int l, r;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &l, &r);
		if (l + l <= r)
		{
			printf("%d %d\n", l, l + l);
		}
		else
		{
			printf("-1 -1\n");
		}
	}
	return 0;
}
