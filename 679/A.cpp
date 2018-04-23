#include <cstdio>

const int prime[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 16, 25, 49};
int cnt;
char st[100];

int main()
{
	for (int i = 0; i < 20; i++)
	{
		printf("%d\n", prime[i]);
		fflush(stdout);
		scanf("%s", st);
		if (st[0] == 'y')
		{
			cnt++;
		}
	}
	if (cnt >= 2)
	{
		printf("composite\n");
	}
	else
	{
		printf("prime\n");
	}
	return 0;
}
