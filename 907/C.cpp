#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

int n;
int flag[100], tmp[100];
int cnt, enough;
int last;
std::string cas[200000], st[200000];
int len[200000];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 26; i++)
	{
		flag[i] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		std::cin >> cas[i] >> st[i];
		len[i] = st[i].length();
		cas[i] = '#' + cas[i];
		st[i] = '#' + st[i];
	}
	cnt = 0;
	enough = -1;
	last = 26;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			tmp[j] = 0;
		}
		if (cas[i][1] == '!')
		{
			cnt++;
			for (int j = 1; j <= len[i]; j++)
			{
				tmp[st[i][j] - 'a'] = 1;
			}
			for (int j = 0; j < 26; j++)
			{
				if (tmp[j] == 0 && flag[j] == 1)
				{
					flag[j] = 0;
					last--;
				}
			}
			if (enough == -1 && last == 1)
			{
				enough = cnt;
			}
		}
		if (cas[i][1] == '.')
		{
			for (int j = 1; j <= len[i]; j++)
			{
				tmp[st[i][j] - 'a'] = 1;
			}
			for (int j = 0; j < 26; j++)
			{
				if (tmp[j] == 1 && flag[j] == 1)
				{
					flag[j] = 0;
					last--;
				}
			}
			if (enough == -1 && last == 1)
			{
				enough = cnt;
			}
		}
		if (cas[i][1] == '?')
		{
			if (st[i] != st[n])
			{
				cnt++;
				if (flag[st[i][1] - 'a'] == 1)
				{
					flag[st[i][1] - 'a'] = 0;
					last--;
				}
			}
			if (enough == -1 && last == 1)
			{
				enough = cnt;
			}
		}
	}
	if (enough == -1)
	{
		enough = cnt;
	}
	printf("%d\n", cnt - enough);
	return 0;
}
