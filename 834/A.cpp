#include <cstdio>

char c1, c2;
int n;

int calc(char x)
{
	if (x == '^')
	{
		return 0;
	}
	if (x == '>')
	{
		return 1;
	}
	if (x == 'v')
	{
		return 2;
	}
	if (x == '<')
	{
		return 3;
	}
}

int main()
{
	scanf("%c %c", &c1, &c2);
	scanf("%d", &n);
	int x = calc(c1);
	int y = calc(c2);
	int k1 = (x + n) % 4;
	int k2 = ((x - n) % 4 + 4) % 4;
	if (k1 == y && k2 == y || k1 != y && k2 != y)
	{
		printf("undefined\n");
		return 0;
	}
	if (k1 == y)
	{
		printf("cw\n");
	}
	else
	{
		printf("ccw\n");
	}
	return 0;
}
