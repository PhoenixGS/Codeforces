#include <cstdio>

int n, m;
int edgenum;
int vet[200000], nextx[200000], head[200000];
int dfn[1000];
int times;
int del;
int top;
int stack[200000];
bool instack[200000];

void add(int u, int v)
{
	edgenum++;
	vet[edgenum] = v;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
}

bool dfs(int u, int cas)
{
	dfn[u] = times;
	instack[u] = 1;
	for (int i = head[u]; i; i = nextx[i])
	{
		if (i != del)
		{
			int v = vet[i];
			if (instack[v] && dfn[v] == times)
			{
				if (cas == 1)
				{
				//	printf("%d %d\n", u, v);
					top++;
					stack[top] = i;
				}
				instack[u] = 0;
				return true;
			}
			if (! dfn[v])
			{
				if (dfs(v, cas))
				{
				//	printf("VV");
					if (cas == 1)
					{
				//		printf("X");
						top++;
						stack[top] = i;
					}
					instack[u] = 0;
					return true;
				}
			}
		}
	}
	instack[u] = 0;
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	times++;
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		if (! dfn[i])
		{
			if (dfs(i, 1))
			{
				flag = true;
				break;
			}
		}
	}
	if (! flag)
	{
		printf("YES\n");
		return 0;
	}
	/*printf("V%d\n", top);
	for (int i = 1; i <= top; i++)
	{
		printf("%d\n", stack[i]);
	}*/
	for (int kk = 1; kk <= top; kk++)
	{
		del = stack[kk];
		bool flag = true;
		for (int i = 1; i <= n; i++)
		{
			dfn[i] = 0;
			instack[i] = 0;
		}
		times = 0;
		for (int i = 1; i <= n; i++)
		{
			if (! dfn[i])
			{
				times++;
				if (dfs(i, 0))
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
		{
			printf("YES\n");
			return 0;
		}
		/*printf("X\n");
		for (int i = 1; i <= n; i++)
		{
			printf("%d %d\n", i, dfn[i]);
		}
		printf("X\n");*/
	}
	printf("NO\n");
	return 0;
}
