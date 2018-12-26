#include <cstdio>

int main()
{
	n = read();
	m = read();
	for (int i = 1; i < n; i++)
	{
		int u, v, a, b;
		u = read();
		v = read();
		a = read();
		b = read();
		add(u, v, a, b);
		add(v, u, a, b);
	}
	
}
