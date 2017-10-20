#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
char s[2000];
char t[2000];
int ansn[2000];
int ttt[2000];

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	int ans = 1000000000;
	for (int i = 1; i <= m - n + 1; i++)
	{
		int tmp = 0;
		for (int j = 1; j <= n; j++)
		{
			int ss = j;
			int tt = i + j - 1;
			if (s[ss] != t[tt])
			{
				tmp++;
				ttt[tmp] = j;
			}
		}
		if (tmp < ans)
		{
			ans = tmp;
			for (int j = 1; j <= tmp; j++)
			{
				ansn[j] = ttt[j];
			}
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++)
	{
		printf("%d ", ansn[i]);
	}
	return 0;
}
