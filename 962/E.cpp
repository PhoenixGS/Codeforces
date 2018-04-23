#include <cstdio>
#include <algorithm>

int n;
long long pos;
char cas[10];
long long ans, maxR, maxB, preR, preB, preP;
int R, B, P;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld%s", &pos, cas + 1);
		if (cas[1] == 'R' || cas[1] == 'P')
		{
			if (R)
			{
				ans += pos - preR;
				maxR = std::max(maxR, pos - preR);
			}
			R = 1;
			preR = pos;
		}
		if (cas[1] == 'B' || cas[1] == 'P')
		{
			if (B)
			{
				ans += pos - preB;
				maxB = std::max(maxB, pos - preB);
			}
			B = 1;
			preB = pos;
		}
		if (cas[1] == 'P')
		{
			if (P)
			{
				ans += std::min(0ll, pos - preP - maxR - maxB);
			}
			P = 1;
			preP = pos;
			maxR = maxB = 0;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
