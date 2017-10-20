#include <cstdio>

int main()
{
	int s, v1, v2, t1, t2;
	scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2);
	int time1 = s * v1 + 2 * t1;
	int time2 = s * v2 + 2 * t2;
	if (time1 < time2)
	{
		printf("First\n");
	}
	if (time1 == time2)
	{
		printf("Friendship\n");
	}
	if (time1 > time2)
	{
		printf("Second\n");
	}
	return 0;
}
