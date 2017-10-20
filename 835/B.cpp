#include <cstdio>
#include <cstring>
#include <algorithm>

int k;
char st[200000];
int x[200000];

int main()
{
	scanf("%d", &k);
	scanf("%s", st + 1);
	int n = strlen(st + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		x[i] = st[i] - 48;
		sum += x[i];
	}
	std::sort(x + 1, x + n + 1);
	int now = 1;
	while (sum < k)
	{
		sum += 9 - x[now];
		now++;
	}
	printf("%d\n", now - 1);
	return 0;
}
