#include<bits/stdc++.h>
using namespace std;
int T,n,t,ans,x[1000005],vis[1000005];
int main()	{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)	{
		cin>>n;
		t=0,ans=0;
		memset(x,0,sizeof(x));
		memset(vis,0,sizeof(vis));
		for(int i=1; i<=n; i++)	{
			cin>>x[i];
			vis[x[i]]++;
		}
		for(int i=1; i<=1000000; i++)	{
			if(vis[i]>=2)	{
				t++;
				continue;
			}
		}
		if(t>=2&&t%2==0)	{
			cout<<0<<'\n';
			continue;
		} else	{
			for(int i=1; i<=1000000; i++)	{
				if(vis[i]>1) {
					ans+=i;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
