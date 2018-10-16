#include <cstdio>
#include <algorithm>

int n;
char s[200000];

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	std::sort(s + 1, s + n + 1);
	printf("%s\n", s + 1);
	return 0;
}
