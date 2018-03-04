#include <cstdio>
#include <cstring>

char st[100];
char map[100][100];
int sum[100][100];
int x, y;

int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			scanf("%s", st);
			for (int k = 1; k <= 3; k++)
			{
				map[i][j * 3 + k] = st[k - 1];
			}
		}
	}
	scanf("%d%d", &x, &y);
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			sum[(i - 1) / 3][(j - 1) / 3] += map[i][j] == 'x' || map[i][j] == 'o';
		}
	}
	if (sum[((x - 1) % 3 + 3) % 3][((y - 1) % 3 + 3) % 3] == 9)
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (! (map[i][j] == 'x' || map[i][j] == 'o'))
				{
					map[i][j] = '!';
				}
			}
		}
	}
	else
	{
		int xx = ((x - 1) % 3 + 3) % 3;
		int yy = ((y - 1) % 3 + 3) % 3;
		for (int i = xx * 3 + 1; i <= (xx + 1) * 3; i++)
		{
			for (int j = yy * 3 + 1; j <= (yy + 1) * 3; j++)
			{
				if (! (map[i][j] == 'x' || map[i][j] == 'o'))
				{
					map[i][j] = '!';
				}
			}
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			printf("%c", map[i][j]);
			if (j % 3 == 0 && j != 9)
			{
				printf(" ");
			}
		}
		puts("");
		if (i % 3 == 0 && i != 9)
		{
			puts("");
		}
	}
	return 0;
}
