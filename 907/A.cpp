#include <cstdio>
#include <algorithm>

int x, y, z, k;
int upx, downx, upy, downy, upz, downz, ansx, ansy, ansz;
int flag;

int main()
{
	scanf("%d%d%d%d", &x, &y, &z, &k);
	upx = 2 * x;
	downx = x;
	upy = 2 * y;
	downy = y;
	upz = 2 * z;
	downz = z;
	downx = std::max(downx, k);
	downy = std::max(downy, k);
	downz = std::max(downz, k);
	downx = std::max(downx, 2 * k + 1);
	downy = std::max(downy, 2 * k + 1);
	upz = std::min(upz, 2 * k);
	flag = false;
	for (ansx = downx; ansx <= upx; ansx++)
	{
		for (ansy = downy; ansy <= upy; ansy++)
		{
			for (ansz = downz; ansz <= upz; ansz++)
			{
				if (ansx > ansy && ansy > ansz)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}
		if (flag)
		{
			break;
		}
	}
	if (flag)
	{
		printf("%d\n%d\n%d\n", ansx, ansy, ansz);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
