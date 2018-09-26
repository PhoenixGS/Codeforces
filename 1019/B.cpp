#include <cstdio>
#include <algorithm>

int n;
int l, r;

int query(int pos)
{
	int ans;
	printf("? %d\n", pos);
	fflush(stdout);
	scanf("%d", &ans);
	return ans;
}

void print(int ans)
{
	printf("! %d\n", ans);
	fflush(stdout);
	std::exit(0);
}

int main()
{
	scanf("%d", &n);
	if (n % 4 == 2)
	{
		print(-1);
	}
	l = 2;
	r = n / 2;
	int x = query(1);
	int y = query(1 + n / 2);
	if (x == y)
	{
		print(1);
	}
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		int xx = query(mid);
		int yy = query(mid + n / 2);
		if (xx == yy)
		{
			print(mid);
		}
		if ((x < y) ^ (xx < yy))
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	print(-1);
	return 0;
}
