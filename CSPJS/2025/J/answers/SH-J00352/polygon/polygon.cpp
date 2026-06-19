#include <bits/stdc++.h>
using namespace std;

int n;
const int N=5007;
const int mod=998244353;
long long ans;
int a[N],fac[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	fac[1]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
		fac[i]=(fac[i-1]*i)%mod;
//	cout<<"111\n";
	for(int i=3;i<=n;i++)
	{
		long long res=fac[n]/fac[i];
		if(i!=n) res/=fac[n-i];
//		cout<<res<<endl;
		res=res%mod;
		ans=(ans+res)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
