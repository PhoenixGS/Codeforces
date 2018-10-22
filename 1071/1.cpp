#include<bits/stdc++.h>
using namespace std;
const int N=2005;
string ans;
char s[N][N];
int a[N][N],rk[N][N],n,k;

/*struct node{
	int x,y,id;
	bool operator < (const node &B) const
	{
		if (x!=B.x) return x<B.x;
		return y<B.y;
	}
}tmp[N*N];
*/
pair<pair<char,int>,int>tmp[N];
void check(int x,int y,int z)
{
	string S="";
	if (!z)
	{
		for (int i=1;i<=x+y-1;i++) S=S+'a';
	}
	else
	{
		S=S+s[x][y];
	}
	while (!(x==n && y==n))
	{
		if (x==n) {y++; S=S+s[x][y];}
		else if (y==n) {x++; S=S+s[x][y];}
		else 
		{
			if (rk[x+1][y]<rk[x][y+1]) {x++; S=S+s[x][y];}
			else {y++; S=S+s[x][y];}
		}
	}
	ans=min(ans,S);
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			if (i==1)
			{
				if (j==1) a[i][j]=(s[i][j]!='a');
				else a[i][j]=a[i][j-1]+(s[i][j]!='a');
			}
			else 
			{
				if (j==1) a[i][j]=a[i-1][j]+(s[i][j]!='a');
				else a[i][j]=min(a[i-1][j],a[i][j-1])+(s[i][j]!='a');
			}
		}
	if (a[n][n]<=k)
	{
		for (int i=1;i<=n+n-1;i++) putchar('a');
		puts("");
		return 0;
	}
	rk[n][n]=1;
	for (int i=n+n-1;i>=2;i--)
	{
		int m=0;
		for (int j=max(i-n,1);j<=n && j<i;j++)
		{
			int x=j,y=i-j,z=1000000000;
			m++;
			if (x<n) z=min(z,rk[x+1][y]);
			if (y<n) z=min(z,rk[x][y+1]);
			tmp[m]=make_pair(make_pair(s[x][y],z),x);
		}
		sort(tmp+1,tmp+1+m);
		for (int j=1;j<=m;j++)
		{
			int x=tmp[j].second,y=i-x;
			rk[x][y]=j;
		}
	}
	ans="";
	for (int i=1;i<=n+n-1;i++) ans=ans+'z';
	check(1,1,1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (a[i][j]==k) check(i,j,0);
	cout<<ans<<endl;
	return 0;
}
