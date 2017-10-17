#include <cstdio>
#include <cstring>
#include <queue>

int edgenum;
int n;
char st[200][200];
int len[200];
bool flag;
std::queue<int> que;
int knum;
int knumber[200];
int in[200];
int vet[200];
int nextx[200];
int head[200];

void add(int u, int v)
{
	edgenum++;
	vet[edgenum] = v;
	nextx[edgenum] = head[u];
	head[u] = edgenum;
	in[v]++;
}

int main()
{
	edgenum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", st[i] + 1);
		len[i] = strlen(st[i] + 1);
	}
	flag = false;
	for (int i = 2; i <= n; i++)
	{
		int pos = 1;
		for (; pos <= std::min(len[i - 1], len[i]) && st[i - 1][pos] == st[i][pos]; pos++);
		if (pos > len[i])
		{
			flag = true;
			break;
		}
		if (pos > len[i - 1])
		{
			continue;
		}
		add(st[i - 1][pos] - 'a', st[i][pos] - 'a');
	}
	if (flag)
	{
		printf("Impossible\n");
		return 0;
	}
	for (int i = 0; i < 26; i++)
	{
		if (in[i] == 0)
		{
			que.push(i);
		}
	}
	knum = -1;
	while (! que.empty())
	{
		int u = que.front();
		que.pop();
		knum++;
		knumber[knum] = u;
		for (int i = head[u]; i; i = nextx[i])
		{
			int v = vet[i];
			in[v]--;
			if (in[v] == 0)
			{
				que.push(v);
			}
		}
	}
	if (knum != 25)
	{
		printf("Impossible\n");
		return 0;
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%c", knumber[i] + 'a');
	}
	printf("\n");
	return 0;
}
