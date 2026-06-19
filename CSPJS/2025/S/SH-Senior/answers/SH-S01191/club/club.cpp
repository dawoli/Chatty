#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
long long n,a[1000005][4];
long long f[505][505][505];
long long p[1000005],p1[1000005],p2[1000005],pt1=0,pt2=0;
bool cmp(long long x,long long y)
{
	return x>y;
}
bool cmp2(long long x,long long y)
{
	return (a[x][2]-a[x][1])>(a[y][2]-a[y][1]);
}
bool cmp3(long long x,long long y)
{
	return (a[x][1]-a[x][2])>(a[y][1]-a[y][2]);
}
void solve()
{
	bool sub6=1,sub7=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j]; 
		}
		if(a[i][2]!=0||a[i][3]!=0) sub6=0;
		if(a[i][3]!=0) sub7=0;
	}
	if(sub6)
	{
		for(int i=1;i<=n;i++)
		{
			p[i]=a[i][1];
		}
		sort(p+1,p+n+1,cmp);
		long long ans=0;
		for(int i=1;i<=n/2;i++)
		{
			ans+=p[i];
		}
		cout<<ans<<endl;
		return;
	}
	if(sub7)
	{
		pt1=0;pt2=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>a[i][2]) p1[++pt1]=i;
			else p2[++pt2]=i;
		}
		if(pt1>=n/2)
		{
			sort(p1+1,p1+pt1+1,cmp2);
			for(int i=1;i<=pt1-n/2;i++)
			{
				ans+=a[p1[i]][2];
			}
			for(int i=pt1-n/2+1;i<=pt1;i++)
			{
				ans+=a[p1[i]][1];
			}
			for(int i=1;i<=pt2;i++)
			{
				ans+=a[p2[i]][2];
			}
			cout<<ans<<endl;
			return;
		}
		else
		{
			sort(p2+1,p2+pt2+1,cmp3);
			for(int i=1;i<=pt2-n/2;i++)
			{
				ans+=a[p2[i]][1];
			}
			for(int i=pt2-n/2+1;i<=pt2;i++)
			{
				ans+=a[p2[i]][2];
			}
			for(int i=1;i<=pt1;i++)
			{
				ans+=a[p1[i]][1];
			}
			cout<<ans<<endl;
			return;
		}
		return;
	}
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=n/2;j++)
		{
			for(int k=0;k<=n/2;k++)
			{
				f[i][j][k]=-INF;
			}
		}
	}
	f[0][0][0]=0;
	for(long long i=0;i<=n-1;i++)
	{
		for(int j=0;j<=min(n/2,i);j++)
		{
			for(int k=0;k<=min(n/2,i);k++)
			{
				long long p=i-j-k;
				if(j+1<=n/2)
				{
					f[i+1][j+1][k]=max(f[i+1][j+1][k],f[i][j][k]+a[i+1][1]);
				}
				if(k+1<=n/2)
				{
					f[i+1][j][k+1]=max(f[i+1][j][k+1],f[i][j][k]+a[i+1][2]);
				}
				if(p+1<=n/2)
				{
					f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]+a[i+1][3]);
				}
			}
		}
	}
	long long ans=-INF;
	for(int j=0;j<=n/2;j++)
	{
		for(int k=0;k<=n/2;k++)
		{
			ans=max(ans,f[n][j][k]);
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

2
4
1 0 0
5 0 0
9 0 0
18 0 0
4
1 0 0
2 0 0
3 0 0
4 0 0
*/
