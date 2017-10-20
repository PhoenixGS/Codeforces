#include <cstdio>
#include <algorithm>

int n;

int main()
{
	scanf("%d", &n);
	int ans = 1000000000;
	int a = n / 100000;
	int b = n / 10000 % 10;
	int c = n / 1000 % 10;
	int d = n / 100 % 10;
	int e = n / 10 % 10;
	int f = n % 10;
	for (int k1 = 0; k1 <= 9; k1++)
	{
		for (int k2 = 0; k2 <= 9; k2++)
		{
			for (int k3 = 0; k3 <= 9; k3++)
			{
				for (int k4 = 0; k4 <= 9; k4++)
				{
					for (int k5 = 0; k5 <= 9; k5++)
					{
						int k6 = k1 + k2 + k3 - k4 - k5;
						if (k6 >= 0 && k6 <= 9)
						{
							ans = std::min(ans, ((int)(k1 != a) + (int)(k2 != b) + (int)(k3 != c) + (int)(k4 != d) + (int)(k5 != e) + (int)(k6 != f)));
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
