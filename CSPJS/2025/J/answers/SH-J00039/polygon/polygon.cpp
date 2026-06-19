#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll a[5005],n,ans,x;
int dfs(ll k,ll step,ll maxv,ll chs,ll sum)
{
	if(chs==k&&sum>2*maxv)
	{
		ans++;
		ans%=MOD;
		return 0;
	}
	else if(n-step+chs+1<k)return 0;
	else 
	{
		dfs(k,step+1,max(maxv,a[step]),chs+1,sum+a[step]);
		dfs(k,step+1,maxv,chs,sum);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,1,-1,0,0);
	}
	cout<<ans<<endl;
	return 0;
}
