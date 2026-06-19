#include <bits/stdc++.h>
using namespace std;
struct car
{
	int d,v,a;
}c[100001];
int jv[100001];
bool cmp(int a,int b)
{
	return a>b;
}
bool cmp1(car a,car b)
{
	return a.d>b.d;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int m,n,l,v;cin >> n >> m >> l >> v;
		for(int i=1;i<=n;i++)
		{cin >> c[i].d >> c[i].v >> c[i].a;}
		for(int i=1;i<=m;i++)cin >> jv[i];
		if(c[1].a==0)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(c[i].v>v)ans++;
			}
			cout << ans <<" "<< m-1;
		}
		else if(c[1].a>0)
		{
			int maxn=0;
			for(int i=1;i<=m;i++)maxn=max(maxn,jv[i]);
			int s=l-maxn;
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(c[i].v+2*c[i].a*maxn>v*v)ans++;
			}
			cout << ans <<" "<< m-1;
		}
		cout << "\n";
	}
}
