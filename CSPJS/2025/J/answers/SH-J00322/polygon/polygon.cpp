#include<bits/stdc++.h>
using namespace std;
int n,a[5005],t[5005],ans;
int vis[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]]++;
	}
	
	for(int i=1;i<=n-3;i++)
	{
		for(int sum=3;sum<=n;sum++)
		{
			for(int j=i+sum-1;j<=n;j++)
			{
				memset(vis,0,sizeof(vis));
				int maxn=-1,l=i,r=j,ansn=1;
				long long cntn=0;
				while(l<=r)
				{
					maxn=max(a[l],maxn);
					maxn=max(a[r],maxn);
//					ansn*=t[a[l]]-vis[a[l]];
					vis[a[l]]++;
					ansn%=998244353;
					cntn+=a[l];
//					cout<<ansn<<" "<<l<<" ";
					if(l!=r)
					{
//						ansn*=t[a[r]]-vis[a[r]];
						vis[a[r]]++;
						ansn%=998244353;
						cntn+=a[r];
//						cout<<ansn<<" "<<r<<" ";
					}
					l++,r--;
				}
//				cout<<endl;
				if(cntn<=maxn*2) continue;
				l=i,r=j;
				while(l<=r)
				{
					if(t[a[l]]-vis[a[l]]>0)
					{
						int st=t[a[l]],ed=vis[a[l]];
						for(int h=1;h<=st;h++) ansn*=h,ansn%=998244353;
						for(int u=1;u<=ed;u++) ansn/=u,ansn%=998244353;
					}
					if(t[a[r]]-vis[a[r]])
					{
						int st=t[a[r]],ed=vis[a[r]];
						for(int h=1;h<=st;h++) ansn*=h,ansn%=998244353;
						for(int u=1;u<=ed;u++) ansn/=u,ansn%=998244353;
					}
					l++,r--;
				}
				ans+=ansn;
			}
		}
	}
	cout<<ans;
	return 0;
}
