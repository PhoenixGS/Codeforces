#include <cstdio>
#include <vector>
#include <algorithm>

const long long INF = (long long)1000000000 * 1000000000;
int n, m;
std::pair<int, int> x[4000];
std::vector<std::pair<int, int> > vec[4000];
int f[4000];
long long sum, ans;
int cnt;
int cc;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x[i].second, &x[i].first);
	}
	std::sort(x + 1, x + n + 1);
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (x[i].second == 1)
		{
			cnt++;
		}
		vec[x[i].second].push_back(std::make_pair(x[i].first, i));
	}
	for (int i = 1; i <= m; i++)
	{
		std::sort(vec[i].begin(), vec[i].end());
	}
	ans = INF;
	for (int i = std::max(cnt, 1); i <= n; i++)
	{
		sum = 0;
		for (int j = 1; j <= n; j++)
		{
			f[j] = x[j].second == 1;
		}
		cc = cnt;
		for (int j = 2; j <= m; j++)
		{
			for (int k = 0; k < (int)vec[j].size() - i + 1; k++)
			{
				sum += vec[j][k].first;
				f[vec[j][k].second] = 1;
				cc++;
			}
		}
		for (int j = 1; j <= n && cc < i; j++)
		{
			if (! f[j])
			{
				sum += x[j].first;
				cc++;
			}
		}
		ans = std::min(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
}
