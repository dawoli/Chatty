#include <bits/stdc++.h>
using namespace std;
int t;
struct node
{
	int q,h;
}ans2[100005];
bool cmp(node x,node y)
{
	if(x.h==y.h) return x.q<y.q;
	return x.h<y.h;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		int n,m,l,v,d[100005],vv[100005],a[100005],p[100005],ans[100005],ansn1=0,ansn2=0;
		cin >> n >> m >> l >> v;
		for(int j=1;j<=n;j++) 
		{
			ans2[j].q=0;
			ans2[j].h=0;
		}
		for(int j=1;j<=n;j++)
		{
			cin >> d[j] >> vv[j] >> a[j];
		}
		for(int j=1;j<=m;j++)
		{
			cin >> p[j];
		}
		for(int j=1;j<=n;j++)
		{
			bool f=0;
			for(int x=1;x<=m;x++)
			{
				if(d[j]>p[x]) continue;
				double y;
				y=sqrt(1.0*vv[j]*vv[j]+2.0*a[j]*(p[x]-d[j]));
				if(y>v)
				{
					if(f==0)
					{
						ans2[j].q=x;
						ans2[j].h=x;
						f=1;
					}
					else
						ans2[j].h=x;
				}
			}
			if(f==1) ansn1++;
		} 
		sort(ans2+1,ans2+n+1,cmp);
		int zhizhen;
		while(1)
		{
			ansn2++;
			while(ans2[zhizhen].h==0) zhizhen++;
			ans2[zhizhen].q=0;
			ans2[zhizhen].h=0;
			for(int j=zhizhen+1;j<=n;j++)
			{
				if(ans2[j].h==0) continue;
				if(ans2[zhizhen].h>=ans2[j].q&&ans2[zhizhen].h<=ans2[j].h)
				{
					ans2[j].q=0;
					ans2[j].h=0;
				}
			}
			bool f_=0;
			for(int j=zhizhen+1;j<=n;j++)
			{
				if(ans2[j].h==0) continue;
				else f_=1;
			}
			if(f_==0) break;
		}
		cout << ansn1 << " " << ansn2 << endl;
	}
}
