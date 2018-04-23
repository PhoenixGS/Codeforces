#include <cstdio>
#include <cstring>
#include <algorithm>

int n, m;
char s[200000], t[200000];
int f[200000], cnt[200000];
int nextx[200000];

void getnextx()
{
	int j = 0;
	for (int i = 2; i <= m; i++)
	{
		while (j && t[j + 1] != t[i])
		{
			j = nextx[j];
		}
		if (t[j + 1] == t[i])
		{
			j++;
		}
		nextx[i] = j;
	}
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	scanf("%s", t + 1);
	m = strlen(t + 1);
	getnextx();
	for (int i = m; i <= n; i++)
	{
		bool flag = 1;
		for (int j = 1; j <= m; j++)
		{
			if (t[m - j + 1] != s[i - j + 1] && s[i - j + 1] != '?')
			{
				flag = 0;
				break;
			}
		}
		f[i] = f[i - 1];
		if (flag)
		{
			cnt[i] = f[i - m];
			for (int j = nextx[m]; j; j = nextx[j])
			{
				cnt[i] = std::max(cnt[i], cnt[i - (m - j)]);
			}
			cnt[i]++;
			f[i] = std::max(f[i], cnt[i]);
		}
	}
	printf("%d\n", f[n]);
	return 0;
}
