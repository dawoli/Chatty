#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
ll n,a[N],ans;
void solveBS()//BinarySystem二进制枚举
{
	vector<ll> Red,Blue;
	ans=0;
	ll sum;
	for(ll p=0;p<(1<<n);p++)
	{
		Red.clear();
		Blue.clear();
		for(ll k=0;k<n;k++)
		{
			if(p&(1<<k))Red.push_back(k+1);
			else Blue.push_back(k+1);
		}
		sum=0;
		for(ll t=1;t<Red.size();t++)
		  if(a[Red[t-1]]==a[Red[t]])
			sum+=a[Red[t]];
		for(ll t=1;t<Blue.size();t++)
		  if(a[Blue[t-1]]==a[Blue[t]])
			sum+=a[Blue[t]];
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++)cin>>a[i];
		if(n<=15)
		{
			solveBS();
		}
	}
	return 0;
}

