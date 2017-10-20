#include <cstdio>
#include <algorithm>

struct T
{
	int l, r;
};

int n;
T x[300000];

bool comp(T x, T y)
{
	return x.l < y.l;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x[i].l, &x[i].r);
	}
	std::sort(x + 1, x + n + 1, comp);
	int last1 = -1;
	int last2 = -1;
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		if (x[i].l > last1)
		{
			last1 = x[i].r;
		}
		else
		{
			if (x[i].l > last2)
			{
				last2 = x[i].r;
			}
			else
			{
				flag = false;
				break;
			}
		}
	}
	if (flag)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
