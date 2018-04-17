#include <cstdio>
#include <cstring>
#include <algorithm>

char s[10000];
int n;
int v[10000][10000];
int fail[10000];
int f[10000];

int cc(int x)
{
	if (x < 10)
	{
		return 1;
	}
	if (x < 100)
	{
		return 2;
	}
	if (x < 1000)
	{
		return 3;
	}
	return 4;
}

void calc(char *s, int n, int *v)
{
	int j = 0;
	fail[0] = fail[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		while (j && s[j + 1] != s[i])
		{
			j = fail[j];
		}
		if (s[j + 1] == s[i])
		{
			j++;
		}
		fail[i] = j;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i % (i - fail[i]) == 0)
		{
			v[i] = i - fail[i] + cc(i / (i - fail[i]));
		}
		else
		{
			v[i] = i + 1;
		}
	}
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	{
		calc(s + i - 1, n - i + 1, v[i] + i - 1);
	}
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		f[i] = 1000000000;
		for (int j = 0; j < i; j++)
		{
			f[i] = std::min(f[i], f[j] + v[j + 1][i]);
		}
	}
	printf("%d\n", f[n]);
	return 0;
}
