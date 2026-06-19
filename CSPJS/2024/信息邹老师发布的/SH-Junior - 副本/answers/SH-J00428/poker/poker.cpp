#include<cstdio>
#include<map>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const long long Inf=1e9+9;
const long long Mod=1e9+7,Mod2=998244353;
typedef long long ll;

ll n,ans;
char pk[19]={' ','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char hs[9]={' ','D','C','H','S'};
map<string,bool> mp;

inline void solve()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		char a,b;
		cin>>a>>b;
		string tmp="";
		tmp+=b, tmp+=a;
		mp[tmp]=true;
	}
	for(int i=1;i<=13;i++)
	{
		for(int j=1;j<=4;j++)
		{
			string tmp="";
			tmp+=pk[i];
			tmp+=hs[j];
			if(mp[tmp]==false)
				ans++;
		}
	}
	printf("%lld\n",ans); 
	return;
}

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
	ll T=1;
	while(T--)
		solve();
	return 0;
}

