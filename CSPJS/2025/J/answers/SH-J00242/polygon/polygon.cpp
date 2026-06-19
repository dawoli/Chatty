#include <bits/stdc++.h>
using namespace std;
long long a[5005];
long long cnt =0;
bool f[5005];
const long long mod = 998244353;
int n;
bool cmp(long long x,long long y)
{
	return x>y;
}
void dfs(long long sum,long long maxn,long long step,long long st)
{
	if(st>n&&step>=3&&sum >2*maxn)
	{
		cnt++;
		return;
	}
	if(step>=3&&sum >2*maxn) 
	{
		cnt++;
		long long now = n-st+1;
		long long ans = (now*now -(now-1))%mod;
		cnt = cnt + ans;
		//cout <<maxn<<" "<<sum<<" "<<now<<" "<< ans<<endl;
		cnt%=mod;
		return ;
	}
	cnt%=mod;
	for(int i = st; i <= n; i++)
	{
		if(f[i]) continue;
		f[i] = 1;
		dfs(sum+a[i],max(maxn,a[i]),step+1,i+1);
		f[i] = 0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	dfs(0,0,0,1);
	cout << cnt;
	return 0;
}
