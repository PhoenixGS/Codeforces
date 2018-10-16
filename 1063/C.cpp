#include <cstdio>

const int INF = 1000000000;
char s[100];
int n;
int flag;

int main()
{
	scanf("%d", &n);
	int l = 0;
	int r = INF;
	printf("%d %d\n", l, 200);
	fflush(stdout);
	scanf("%s", s + 1);
	if (s[1] == 'b')
	{
		flag = 1;
	}
	else
	{
		flag = 0;
	}
	for (int i = 1; i < n; i++)
	{
		int mid = (l + r + 1) >> 1;
		printf("%d %d\n", mid, 200);
		fflush(stdout);
		scanf("%s", s + 1);
		if ((s[1] == 'b' ? 1 : 0) == flag)
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	printf("%d %d %d %d\n", l, 100, l + 1, 300);
	fflush(stdout);
	return 0;
}
