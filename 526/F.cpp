#include <cstdio>
#include <algorithm>

long long read()
{
	char last = '+', ch = getchar();
	while (ch < '0' || ch > '9') last = ch, ch = getchar();
	long long tmp = 0;
	while (ch >= '0' && ch <= '9') tmp = tmp * 10 + ch - 48, ch = getchar();
	if (last == '-') tmp = -tmp;
	return tmp;
}

int n;
int x[400000];
int minx[400000];
int maxx[400000];
long long ans;
int sum[800000];
std::pair<int, int> kk[400000];

void solve(int l, int r)
{
	if (l == r)
	{
		ans++;
		return;
	}
	int mid = (l + r) >> 1;
	solve(l, mid);
	solve(mid + 1, r);
	minx[mid] = x[mid];
	maxx[mid] = x[mid];
	for (int i = mid - 1; i >= l; i--)
	{
		minx[i] = std::min(minx[i + 1], x[i]);
		maxx[i] = std::max(maxx[i + 1], x[i]);
	}
	minx[mid + 1] = x[mid + 1];
	maxx[mid + 1] = x[mid + 1];
	for (int i = mid + 2; i <= r; i++)
	{
		minx[i] = std::min(minx[i - 1], x[i]);
		maxx[i] = std::max(maxx[i - 1], x[i]);
	}
	for (int i = l; i <= mid; i++)
	{
		int j = maxx[i] - minx[i] + i;
		if (mid + 1 <= j && j <= r && minx[i] < minx[j] && maxx[j] < maxx[i])
		{
			ans++;
		}
	}
	for (int j = mid + 1; j <= r; j++)
	{
		int i = j - maxx[j] + minx[j];
		if (l <= i && i <= mid && minx[j] < minx[i] && maxx[i] < maxx[j])
		{
			ans++;
		}
	}
	int head, tail;
	head = mid + 1;
	tail = mid + 1;
	for (int i = mid; i >= l; i--)
	{
		while (tail <= r && minx[tail] > minx[i])
		{
			sum[maxx[tail] - tail + n]++;
			tail++;
		}
		while (head < tail && maxx[head] < maxx[i])
		{
			sum[maxx[head] - head + n]--;
			head++;
		}
		ans += sum[minx[i] - i + n];
	}
	while (head < tail)
	{
		sum[maxx[head] - head + n]--;
		head++;
	}
	head = mid;
	tail = mid;
	for (int j = mid + 1; j <= r; j++)
	{
		while (head >= l && minx[head] > minx[j])
		{
			sum[maxx[head] + head]++;
			head--;
		}
		while (tail > head && maxx[tail] < maxx[j])
		{
			sum[maxx[tail] + tail]--;
			tail--;
		}
		ans += sum[minx[j] + j];
	}
	while (head < tail)
	{
		sum[maxx[tail] + tail]--;
		tail--;
	}
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		kk[i].first = read();
		kk[i].second = read();
	}
	std::sort(kk + 1, kk + n + 1);
	for (int i = 1; i <= n; i++)
	{
		x[i] = kk[i].second;
	}
	ans = 0;
	solve(1, n);
	printf("%lld\n", ans);
	return 0;
}

