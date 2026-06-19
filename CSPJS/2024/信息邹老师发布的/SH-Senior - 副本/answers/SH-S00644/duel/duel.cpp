#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
ll n,r[N];
ll t,a[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&r[i]);
	sort(r+1,r+1+n);
	r[0]=-1;
	for(int i=1;i<=n;++i)
	{
		if(r[i]!=r[i-1]) t++;
		a[t]++;//统计几种怪兽以及每种怪兽的数量 
	}
	ll lft=a[1];//指代比目前攻防能力弱的怪兽的数量 
	ll ans=n;//总共剩余数量 
	for(int i=2;i<=t;++i)
	{
		if(a[i]>=lft)//豆沙了 
		{
			ans-=lft;
			lft=0;
		}
		else//沙不完 
		{
			ans-=a[i];
			lft-=a[i];
		}
		lft+=a[i];//猎人变成猎物哩 
	}
	//cout<<t<<endl;
	printf("%lld\n",ans);
	return 0;
}
//mention:only when > can they defend against the attack
//r[i]<=1e5, so we use 桶排序 
