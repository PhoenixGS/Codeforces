#include <cstdio>
#include <cstring>

char x[1000], y[1000];
int n, m;
int cnt[1000];
int tmp[1000];

bool check(int pos)
{
	for (int i = pos; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (cnt[j])
			{
				cnt[j]--;
				tmp[i] = j;
				break;
			}
		}
	}
	for (int i = pos; i <= n; i++)
	{
		cnt[tmp[i]]++;
	}
	for (int i = pos; i <= n; i++)
	{
		if (tmp[i] < y[i] - '0')
		{
			return true;
		}
		if (tmp[i] > y[i] - '0')
		{
			return false;
		}
	}
	return true;
}

int main()
{
	scanf("%s%s", x + 1, y + 1);
	n = strlen(x + 1);
	m = strlen(y + 1);
	for (int i = 1; i <= n; i++)
	{
		cnt[x[i] - '0']++;
	}
	if (n < m)
	{
		for (int i = 9; i >= 0; i--)
		{
			for (int j = 1; j <= cnt[i]; j++)
			{
				printf("%d", i);
			}
		}
		printf("\n");
		return 0;
	}
	bool limit = true;
	for (int i = 1; i <= n; i++)
	{
		int top;
		if (limit)
		{
			top = y[i] - '0';
		}
		else
		{
			top = 9;
		}
		//printf("XX%d %d %d\n", i, top, limit);
		for (int j = top; j >= 0; j--)
		{
			if (cnt[j])
			{
				cnt[j]--;
				if (! (limit && (j == top)) || check(i + 1))
				{
					limit = limit && (j == top);
					//printf("X%d %d %d", j, top, limit);
					printf("%d", j);
					break;
				}
				cnt[j]++;
			}
		}
		/*printf("#%d\n", i);
		for (int i = 0; i <= 9; i++)
		{
			printf("%d", cnt[i]);
		}*/
	}
	printf("\n");
	return 0;
}
