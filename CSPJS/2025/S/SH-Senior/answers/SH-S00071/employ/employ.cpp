#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,m,c[1010],p[1010];
string s;
ll fact[1010];
void init()
{
	fact[0]=1;
	for(ll i=1;i<=500;i++) fact[i]=fact[i-1]*i%mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n)
	{
		bool flag=1;
		for(int i=1;i<=n;i++) if(s[i-1]=='0') flag=0;
		for(int i=1;i<=n;i++) if(c[i]==0) flag=0;
		if(flag) cout<<fact[n]<<endl;
		else cout<<0<<endl;
		return 0;
	}
	if(m==1)
	{
		sort(c+1,c+1+n);
		int cnt=n;
		ll ans=0;
		ll pre=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0') continue;
			int pos=lower_bound(c+1,c+1+n,i)-c;
			cnt--;
			ans+=fact[cnt]*(n-pos+1)%mod*pre%mod;ans%=mod;
			pre*=(pos-1);pre%=mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n<=10)
	{
		for(int i=1;i<=n;i++) p[i]=i;
		int ans=0;
		do
		{
			int cnt=0,sum=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i-1]=='0'||cnt>=c[p[i]]) cnt++;
				else cnt=0,sum++;
			}
			if(sum>=m) ans++;
		}while(next_permutation(p+1,p+1+n));
		cout<<ans<<endl;
	}
	return 0;
}

