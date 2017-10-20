#include <cstdio>
#include <cstring>

char st[5005];
int n;
bool flag[5005][5005];
int f[5005][5005];
int ans[5005];

int main()
{
	scanf("%s", st + 1);
	n = strlen(st + 1);
	for (int i = 1; i <= n; i++)
	{
		int l = i;
		int r = i;
		while (l >= 1 && r <= n && st[l] == st[r])
		{
			flag[l][r] = true;
			l--;
			r++;
		}
	}
	for (int i = 1; i < n; i++)
	{
		int l = i;
		int r = i + 1;
		while (l >= 1 && r <= n && st[l] == st[r])
		{
			flag[l][r] = true;
			l--;
			r++;
		}
	}
	for (int len = 1; len <= n; len++)
	{
		for (int l = 1; l + len - 1 <= n; l++)
		{
			int r = l + len - 1;
			if (flag[l][r])
			{
				if (len & 1)
				{
					int mid = (l + r) >> 1;
					f[l][r] = f[l][mid - 1] + 1;
				}
				else
				{
					int midl = (l + r) >> 1;
					f[l][r] = f[l][midl] + 1;
				}
				ans[f[l][r]]++;
			}
			else
			{
				f[l][r] = 0;
			}
		}
	}
	for (int i = n - 1; i >= 1; i--)
	{
		ans[i] += ans[i + 1];
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
