#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod=998244353;
int n,a[5005];
int ans;
void dfs(int x,int ma,int tot,int cho)
{
//	if(tot>ma*2&&cho>=3) ans++;
	if(x>n) 
	{
		return ;
	}
	for(int i=0;i<=1;i++)
	{
		if(i==0) dfs(x+1,ma,tot,cho);
		if(i==1)
		{
			ma=max(a[x],ma);
			tot+=a[x];
			cho+=1;
			if(tot>ma*2&&cho>=3) 
			{
				ans++;
			}
			dfs(x+1,ma,tot,cho);
		}
	}
	return ;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
//	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	ans=ans%mod;
	cout<<ans<<endl;
	return 0;
}
