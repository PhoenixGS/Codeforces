#include <cstdio>
#include <algorithm>

using namespace std;

int d;
int n, m;
int x1[200000];
int y1[200000];
int x2[200000];
int y2[200000];
int cntl, cntr, cntt, cntb;
int l[200000];
int r[200000];
int t[200000];
int b[200000];
int sl[200000];
int sr[200000];
int st[200000];
int sb[200000];

int main()
{
	scanf("%d", &d);
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= d; i++)
	{
		scanf("%d%d%d%d", &y1[i], &x1[i], &y2[i], &x2[i]);
	}
	scanf("%d%d%d%d", &cntl, &cntr, &cntt, &cntb);
	for (int i = 1; i <= d; i++)
	{
		l[min(y1[i], y2[i])]++;
		r[max(y1[i], y2[i])]++;
		t[min(x1[i], x2[i])]++;
		b[max(x1[i], x2[i])]++;
	}
	for (int i = 1; i <= n; i++)
	{
		st[i] = st[i - 1] + t[i];
	}
	for (int i = n; i >= 1; i--)
	{
		sb[i] = sb[i + 1] + b[i];
	}
	for (int i = 1; i <= m; i++)
	{
		sl[i] = sl[i - 1] + l[i];
	}
	for (int i = m; i >= 1; i--)
	{
		sr[i] = sr[i + 1] + r[i];
	}
	bool flag = false;
	for (int i = 1; i <= d; i++)
	{
		if (st[max(x1[i], x2[i]) - 1] - (x1[i] != x2[i]) == cntt && sl[max(y1[i], y2[i]) - 1] - (y1[i] != y2[i]) == cntl && sb[min(x1[i], x2[i]) + 1] - (x1[i] != x2[i]) == cntb && sr[min(y1[i], y2[i]) + 1] - (y1[i] != y2[i]) == cntr)
		{
			printf("%d\n", i);
			flag = true;
			break;
		}
	}
	if (! flag)
	{
		printf("-1\n");
	}
	return 0;
}
