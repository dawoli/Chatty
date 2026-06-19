#include<bits/stdc++.h>
typedef long long ll;
const ll MOD=998244353;
using namespace std;
int n,m,a[501],pl[30],cl[30];
ll ans;
string str;
void dfs(int k)
{
	if(k==n+1)
	{
		int cnt=0,gv=0;
		for(int i=1;i<=n;i++)
		{
			if(gv>=a[pl[i]])
			{
				gv++;
				continue;
			}
			if(str[i-1]=='0')
				gv++;
		}
		if(m<=n-gv)
		{
			ans++;
			ans%=MOD;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(cl[i])
			continue;
		cl[i]=1;
		pl[k]=i;
		dfs(k+1);
		cl[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int cnt0=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='0')
			cnt0++;
	}
	if(m>n-cnt0)
	{
		cout<<"0\n";
		return 0;
	}
	if(n<=18)
	{
		dfs(1);
		cout<<ans<<"\n";
		return 0;
	}
	if(cnt0==0)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=MOD;
		}
		cout<<ans<<"\n";
		return 0;
	}
	cout<<"0\n";
	return 0;
}

