#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,ans;
int a[5005];
void dfs(int last,int sum,int mx)
{
	if(sum>2*mx) ans++;
	for(int i=last+1;i<=n;++i)
		dfs(i,sum+a[i],a[i]);
	
}
int fact[5005],infact[5005];
int ksm(int a,int k)
{
	int tmp=a,res=1;
	while(k)
	{
		if(k%2==1) res=res*tmp%mod;
		k/=2;tmp=tmp*tmp%mod;
	}
	return res;
}
void init()
{
	fact[0]=infact[0]=1;
	for(int i=1;i<=5000;++i) fact[i]=fact[i-1]*i%mod;
	infact[5000]=ksm(fact[5000],mod-2);
	for(int i=4999;i>=1;--i) infact[i]=infact[i+1]*(i+1)%mod;
}
int C(int a,int b)
{
	return (fact[a]*infact[a-b]%mod)*infact[b]%mod;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=20)
	{
		for(int i=1;i<=n;++i) cin>>a[i];
		sort(a+1,a+n+1);
		dfs(0,0,0);
		cout<<ans;
	}
	else
	{
		bool flag=1;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			if(a[i]!=1) flag=0;
		}
		if(flag)
		{
			init();
			for(int i=3;i<=n;++i) ans=(ans+C(n,i))%mod;
			cout<<ans;
		}
		else cout<<1;
	}
	return 0;
}
