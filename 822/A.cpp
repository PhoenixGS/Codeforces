#include <cstdio>
#include <algorithm>

using namespace std;

int x, y;

int main()
{
	scanf("%d%d", &x, &y);
	int xx = min(x, y);
	int ans = 1;
	for (int i = 1; i <= xx; i++)
	{
		ans = ans * i;
	}
	printf("%d\n", ans);
	return 0;
}
