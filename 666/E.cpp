#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define mid ((l + r) >> 1)

char s[1000000];
char t[1000000];
int knum, num;
int to[2000000][28], len[2000000], pre[2000000];
int root[2000000];
int tree[20000000], poss[20000000], ch[20000000][2];
int fa[2000000][23];
int cnt[2000000];
int n, m, q;
int last;
std::queue<int> que;
int vvv[2000000];
int top;
int stack[2000000];

void add(int c)
{
	int u = last;
	if (to[u][c])
	{
		int w = to[u][c];
		if (len[u] + 1 == len[w])
		{
			last = w;
			return;
		}
		knum++;
		int neww = knum;
		last = neww;
		pre[neww] = pre[w];
		for (int i = 0; i < 26; i++)
		{
			to[neww][i] = to[w][i];
		}
		len[neww] = len[u] + 1;
		pre[w] = neww;
		for (; u && to[u][c] == w; u = pre[u])
		{
			to[u][c] = neww;
		}
		return;
	}
	knum++;
	int v = knum;
	last = v;
	len[v] = len[u] + 1;
	for (; u && ! to[u][c]; u = pre[u])
	{
		to[u][c] = v;
	}
	if (! u)
	{
		pre[v] = 1;
		return;
	}
	int w = to[u][c];
	if (len[u] + 1 == len[w])
	{
		pre[v] = w;
		return;
	}
	knum++;
	int neww = knum;
	pre[neww] = pre[w];
	for (int i = 0; i < 27; i++)
	{
		to[neww][i] = to[w][i];
	}
	len[neww] = len[u] + 1;
	pre[w] = pre[v] = neww;
	for (; u && to[u][c] == w; u = pre[u])
	{
		to[u][c] = neww;
	}
}

void pushup(int k)
{
	if (tree[ch[k][0]] >= tree[ch[k][1]])
	{
		tree[k] = tree[ch[k][0]];
		poss[k] = poss[ch[k][0]];
	}
	else
	{
		tree[k] = tree[ch[k][1]];
		poss[k] = poss[ch[k][1]];
	}
}

void change(int &u, int l, int r, int pos)
{
	if (! u)
	{
		num++;
		u = num;
	}
	if (l == r)
	{
		tree[u] += 1;
		poss[u] = l;
		return;
	}
	if (pos <= mid)
	{
		change(ch[u][0], l, mid, pos);
	}
	else
	{
		change(ch[u][1], mid + 1, r, pos);
	}
	pushup(u);
}

void merge(int x, int y, int &z, int l, int r)
{
	if (! x)
	{
		z = y;
		return;
	}
	if (! y)
	{
		z = x;
		return;
	}
	num++;
	z = num;
	if (l == r)
	{
		tree[z] = tree[x] + tree[y];
		poss[z] = poss[x];
		return;
	}
	merge(ch[x][0], ch[y][0], ch[z][0], l, mid);
	merge(ch[x][1], ch[y][1], ch[z][1], mid + 1, r);
	pushup(z);
}

std::pair<int, int> query(int k, int l, int r, int L, int R)
{
	if (! k)
	{
		return std::make_pair(0, 0);
	}
	if (L <= l && r <= R)
	{
		return std::make_pair(tree[k], poss[k]);
	}
	if (! (L <= mid))
	{
		return query(ch[k][1], mid + 1, r, L, R);
	}
	if (! (R > mid))
	{
		return query(ch[k][0], l, mid, L, R);
	}
	std::pair<int, int> t1 = query(ch[k][0], l, mid, L, R);
	std::pair<int, int> t2 = query(ch[k][1], mid + 1, r, L, R);
	if (t1.first >= t2.first)
	{
		return t1;
	}
	else
	{
		return t2;
	}
}

std::pair<int, int> solve(int l, int r, int L, int R)
{
	int now = vvv[R];
	for (int i = 21; i >= 0; i--)
	{
		if (len[fa[now][i]] >= R - L + 1)
		{
			now = fa[now][i];
		}
	}
	std::pair<int, int> ans = query(root[now], 1, m, l, r);
	if (ans.first == 0 && ans.second == 0)
	{
		return std::make_pair(0, l);
	}
	return ans;
}

int main()
{
	last = 1;
	knum = 1;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	{
		add(s[i] - 'a');
		vvv[i] = last;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%s", t + 1);
		int k = strlen(t + 1);
		last = 1;
		for (int j = 1; j <= k; j++)
		{
			add(t[j] - 'a');
			change(root[last], 1, m, i);
		}
	}
	top = 0;
	for (int i = 2; i <= knum; i++)
	{
		cnt[pre[i]]++;
	}
	for (int i = 1; i <= knum; i++)
	{
		if (! cnt[i])
		{
			que.push(i);
		}
	}
	while (! que.empty())
	{
		int u = que.front();
		top++;
		stack[top] = u;
		que.pop();
		merge(root[pre[u]], root[u], root[pre[u]], 1, m);
		cnt[pre[u]]--;
		if (! cnt[pre[u]])
		{
			que.push(pre[u]);
		}
	}
	for (int i = top; i >= 1; i--)
	{
		int u = stack[i];
		fa[u][0] = pre[u];
		for (int j = 1; j <= 21; j++)
		{
			fa[u][j] = fa[fa[u][j - 1]][j - 1];
		}
	}
	scanf("%d", &q);
	while (q--)
	{
		int l, r, L, R;
		scanf("%d%d%d%d", &l, &r, &L, &R);
		std::pair<int, int> ans = solve(l, r, L, R);
		printf("%d %d\n", ans.second, ans.first);
	}
	return 0;
}
