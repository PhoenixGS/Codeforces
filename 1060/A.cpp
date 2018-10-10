#include <cstdio>
#include <algorithm>

int n;
char s[1000];
int cnt[100];

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		cnt[s[i] - 48]++;
	}
	printf("%d\n", std::min(cnt[8], n / 11));
	return 0;
}
