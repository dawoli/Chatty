#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,ans,arr[5005];
void dfs(int idx,int sum,int mxi,int cnt)
{
	if(sum>2*arr[mxi]&&cnt==n)
	{
		ans++;
		ans%=mod;
	}
	if(idx<=0)return;
	dfs(idx-1,sum+arr[idx],max(idx,mxi),cnt+1);
	dfs(idx-1,sum,mxi,cnt+1);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	dfs(n,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
