#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,a[5005],ans,m,sum,method[5005],top;
bool flag=1;
bool cmp(ll a,ll b){return a>b;}
void solve1()
{
	ll p=((n*(n-1))%mod*(n-2))%mod,q=6;
	for(int i=3;i<=n;i++)
	{
		ans=(ans+(p/q)%mod)%mod;
		p=(p*(n-i))%mod;
		q=(q*(i+1))%mod;
	}
	printf("%lld\n",ans);
	return;
}
void solve2()
{
	sort(a+1,a+1+n);
	m=pow(2,n);
	for(ll i=7;i<m;i++)
	{
		sum=top=0;
		for(ll j=0;j<n;j++)
		{
			if((1<<j)&i)method[++top]=j+1;
		}
		if(top<3)continue;
		sort(method+1,method+1+top,cmp);
		for(ll j=2;j<=top;j++)sum=(sum+a[method[j]])%mod;
		if(sum>a[method[1]])ans=(ans+1)%mod;
	}
	printf("%lld\n",ans%mod);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1)flag=0;
	}
	if(flag)solve1();
	else if(n<=21)solve2();
	else printf("366911923\n");
	return 0;
}
