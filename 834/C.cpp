#include <cstdio>
#include <algorithm>

typedef long long ll;

ll x, y, s;

ll read()
{
	char last = '+', ch = getchar();
	while (ch < '0' || ch > '9') last = ch, ch = getchar();
	ll tmp = 0;
	while (ch >= '0' && ch <= '9') tmp = tmp * 10 + ch - 48, ch = getchar();
	if (last == '-') tmp = -tmp;
	return tmp;
}

ll binary_search(ll l, ll r)
{
	if (l > r)
	{
		return -1;
	}
	ll mid = (l + r) >> 1;
	if (mid * mid * mid == s)
	{
		return mid;
	}
	if (mid * mid * mid < s)
	{
		return binary_search(mid + 1, r);
	}
	else
	{
		return binary_search(l, mid - 1);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		x = read();
		y = read();
		s = x * y;
		if (binary_search(0, std::min(std::min(x, y), (long long)1000000)) != -1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
