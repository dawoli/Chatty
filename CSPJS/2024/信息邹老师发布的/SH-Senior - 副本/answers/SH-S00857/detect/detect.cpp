#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,s[100010],e[100010],d[100010],sp[100010],a[100010],ans1=0,mon[100010],minn,minnn;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		cin>>n>>m>>l>>v;
		ans1=0;
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>sp[i]>>a[i];
			if(a[i]!=0)
				flag=1;
		}
		for(int i=1;i<=m;i++)
			cin>>mon[i];
		for(int i=1;i<=n;i++)
		{
			if(sp[i]>v)
			{
				if(mon[m]>=d[i])
					ans1++;
				continue;
			}
			if(flag!=0)
			{ 
				int dis=(v*v-sp[i]*sp[i])/(2*a[i]);
				if(mon[m]>=d[i]+dis+1)
					ans1++;
			}
		}
		if(ans1==0)
			cout<<ans1<<" "<<m<<endl;
		else
			cout<<ans1<<" "<<m-1<<endl;
	}
	return 0;
}
