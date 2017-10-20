#include <cstdio>
#include <algorithm>

using namespace std;

int n, A;
int pre, now;
int x[200000];
int s[2000000];
int kk[3][2000000];
int last[3];

void add(int x)
{
	last[now]++;
	kk[now][last[now]] = x;
}

int main()
{
	scanf("%d%d", &n, &A);
	int minx = 1000000000;
	int maxx = -1000000000;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		minx = min(minx, x[i]);
		maxx = max(maxx, x[i]);
	}
	last[0] = last[1] = 0;
	for (int i = minx; i <= maxx; i++)
	{
		if (i != A)
		{
			add(i);
		}
	}
	pre = 1;
	now = 0;
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		s[x[i]]++;
		if (x[i] == A)
		{
			pre = pre ^ 1;
			now = now ^ 1;
			last[now] = 0;
			for (int i = 1; i <= last[pre]; i++)
			{
				if (s[kk[pre][i]] >= s[A])
				{
					add(kk[pre][i]);
				}
			}
			if (last[now] == 0)
			{
				flag = false;
				break;
			}
		}
	}
	if (! flag)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", kk[now][1]);
	}
	return 0;
}
