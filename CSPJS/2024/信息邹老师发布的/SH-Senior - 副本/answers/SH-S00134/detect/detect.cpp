#include<bits/stdc++.h>
using namespace std;
long long t,ans[25][2];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		int n,m,l,V,d[100005],a[100005],v[100005],p[100005];
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)cin>>p[i];
		sort(p+1,p+m+1);
		if(a[1]==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(v[i]>V&&d[i]<=p[m])ans[o][0]++;
			}
			if(ans[o][0]==0)ans[o][1]=m;
			else ans[o][1]=m-1;
		}
		if(a[1]>0)
		{
			for(int i=1;i<=n;i++)
			{
				if(d[i]>p[m])continue;
				if((v[i]*v[i]+2*a[i]*(p[m]-d[i]))>V*V)ans[o][0]++;
			}
			if(ans[o][0]==0)ans[o][1]=m;
			else ans[o][1]=m-1;
		}
		if(a[1]<0)
		{
			
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	}
	return 0;
}
