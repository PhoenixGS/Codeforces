#include<ctime>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define sqz main
#define ll long long
#define reg register int
#define rep(i, a, b) for (reg i = (a); i <= (b); i++)
#define per(i, a, b) for (reg i = (a); i >= (b); i--)
#define travel(i, u) for (reg i = head[u]; ~i; i = edge[i].next)

const ll INF = 1e18, N = 200005;
const double eps = 1e-6, phi = acos(-1.0);
namespace fast_IO
{
    inline char read()
    {
        return getchar();
        static const int IN_LEN = 1000000;
        static char buf[IN_LEN], *s, *t;
        if (s == t)
        {
            t = (s = buf) + fread(buf, 1, IN_LEN, stdin);
            if (s == t) return -1;
        }
        return *s++;
    }
    template<class T>
    inline void read(T &x)
    {
        static bool iosig;
        static char c;
        for (iosig = false, c = read(); !isdigit(c); c = read()) {
            if (c == '-') iosig = true;
            if (c == -1) return;
        }
        for (x = 0; isdigit(c); c = read())
            x = ((x + (x << 2)) << 1) + (c ^ '0');
        if (iosig) x = -x;
    }
    const int OUT_LEN = 10000000;
    char obuf[OUT_LEN], *ooh = obuf;
    inline void print(char c)
    {
        if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
        *ooh++ = c;
    }
    template<class T>
    inline void print(T x)
    {
        static int buf[30], cnt;
        if (x == 0) print('0');
        else
        {
            if (x < 0) print('-'), x = -x;
            for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
            while (cnt) print((char)buf[cnt--]);
        }
    }
    inline void flush()
    {
        fwrite(obuf, 1, ooh - obuf, stdout);
    }
}
using namespace fast_IO;

int n, T, ans, x = 0;
int flag1[N + 5];
struct node
{
    int a, t;
}X[N + 5];
int cmp(node X, node Y)
{
    return X.t < Y.t || (X.t == Y.t && X.a > Y.a);
}
int check(int x)
{
    int num = 0, i = 1, ans = 0;
    while (num < x)
    {
        ans += X[i].t;
        if (X[i].a >= x) num++;
        if (ans > T) return 0;
        i++;
    }
    rep(j, 1, i - 1) flag1[j] = 1;
    return 1;
}
int Find(int l, int r)
{
    if (l == r) return l;
    int mid = (l + r + 1) >> 1;
    if (check(mid)) return Find(mid, r);
    else return Find(l, mid - 1);
}

int main()
{
    read(n), read(T); ans = 0;
    rep(i, 1, n)
    {
        read(X[i].a), read(X[i].t);
    }
    sort(X + 1, X + n + 1, cmp);
    print(Find(0, n)), print('\n');
    rep(i, 1, n) if (flag1[i]) ans++;
    print(ans), print('\n');
    rep(i, 1, n) if (flag1[i]) print(i), print((++x) == ans ? '\n' : ' ');
    return flush(), 0;
}

