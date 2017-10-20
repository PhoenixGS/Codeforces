#include <cstdio>
#include <algorithm>

int n, k;
char st[2000000];
int begins[100];
int ends[100];

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", st + 1);
	for (int i = 1; i <= 26; i++)
	{
		begins[i] = n + 1;
		ends[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int ch = st[i] - 'A' + 1;
		begins[ch] = std::min(begins[ch], i);
		ends[ch] = std::max(ends[ch], i);
	}
	bool flag = false;
	int tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		int ch = st[i] - 'A' + 1;
		if (begins[ch] == i)
		{
			tmp++;
		}
		if (tmp > k)
		{
			flag = true;
			break;
		}
		if (ends[ch] == i)
		{
			tmp--;
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
