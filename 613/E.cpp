#include <cstdio>
#include <cstring>
#include <algorithm>

const long long M = 1e9 + 7;
long long mi[2005];

struct hash
{
    long long hash[2005];
    void make(int n, char *s)
    {
        hash[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            hash[i] = (hash[i - 1] * 31 + s[i] - 'a') % M;
        }
    }
    long long cut(int l, int r)
    {
        return (hash[r] - hash[l - 1] * mi[r - l + 1] % M + M) % M;
    }
};

hash pre[2], suf[2], comp;
int n, m;
long long f[2][2005][2005];
long long ans;
char st[2005];
char S[2][2005];

long long solve(int flag)
{
    long long ans = 0;
    memset(f, 0, sizeof(f));
    for (int j = 1; j <= n; j++)
    {
        f[0][j][0] = f[1][j][0] = 1;
        for (int i = 0; i < 2; i++)
        {
            for (int k = 2; k <= std::min(n - j + 1, m / 2); k++)
            {
                if (comp.cut(m - 2 * k + 1, m - k) == pre[i].cut(j, j + k - 1) && comp.cut(m - k + 1, m) == suf[i ^ 1].cut(n - (j + k - 1) + 1, n - j + 1))
                {
                    if (2 * k != m || flag)
                    {
                        ans = (ans +  f[i][j][m - 2 * k]) % M;
                    }
                }
            }
            for (int k = 2; k <= std::min(j, m / 2); k++)
            {
                if (comp.cut(k + 1, 2 * k) == pre[i].cut(j - k + 1, j) && comp.cut(1, k) == suf[i ^ 1].cut(n - j + 1, n - (j - k + 1) + 1))
                {
                    if (2 * k != m || flag)
                    {
                        f[i][j + 1][2 * k] = (f[i][j + 1][2 * k] + 1) % M;
                    }
                }
            }
        }
        for (int i = 0; i < 2; i++)
        {
            for (int k = 0; k < m; k++)
            {
                if (S[i][j] == st[k + 1])
                {
                    f[i][j + 1][k + 1] = (f[i][j + 1][k + 1] + f[i][j][k]) % M;
                    if (k + 2 <= m && S[i ^ 1][j] == st[k + 2])
                    {
                        f[i ^ 1][j + 1][k + 2] = (f[i ^ 1][j + 1][k + 2] + f[i][j][k]) % M;
                    }
                }
            }
        }
        for (int i = 0; i < 2; i++)
        {
            ans = (ans + f[i][j + 1][m]);
        }
    }
    return ans;
}

int main()
{
    scanf("%s%s%s", S[0] + 1, S[1] + 1, st + 1);
    n = strlen(S[0] + 1);
    m = strlen(st + 1);
    mi[0] = 1;
    for (int i = 1; i <= 2000; i++)
    {
        mi[i] = (mi[i - 1] * 31) % M;
    }
    for (int i = 0; i < 2; i++)
    {
        pre[i].make(n, S[i]);
        std::reverse(S[i] + 1, S[i] + n + 1);
        suf[i].make(n, S[i]);
        std::reverse(S[i] + 1, S[i] + n + 1);
    }
    comp.make(m, st);
    if (m == 1)
    {
        printf("%lld\n", solve(1) % M);
        return 0;
    }
    ans = 0;
    ans = (ans + solve(1)) % M;    
    std::reverse(st + 1, st + m + 1);
    comp.make(m, st);
    ans = (ans + solve(0)) % M;
    if (m == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            if (S[0][i] == st[1] && S[1][i] == st[2])
            {
                ans = (ans - 1 + M) % M;
            }
            if (S[1][i] == st[1] && S[0][i] == st[2])
            {
                ans = (ans - 1 + M) % M;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
