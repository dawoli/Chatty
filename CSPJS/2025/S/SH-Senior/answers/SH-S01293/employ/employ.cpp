#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
ll n,m,c[505],a[505],cnt,ans;
bool used[505];
string s;
bool check()
{
	cnt=0;
	bool f[505];
	memset(f,0,sizeof(f));
	// for(int i=1;i<=n;i++)
	//     printf("%lld ",a[i]);
	// puts("");
	for(int i=1;i<=n;i++)
	{
		if(f[a[i]]) continue;
		f[a[i]]=1;
		if(s[i]=='0') cnt++;
		for(int j=i;j<=n;j++)
			if(!f[a[j]]&&c[a[j]]<=cnt)
			{
				cnt++;
				f[a[j]]=1;
			}
		
	//    printf("%lld\n",cnt);
	}
	if(n-cnt>=m) return 1;
	return 0;
}
void dfs(ll dep)
{
	if(dep>n)
		if(check())
		{
			ans++;
			ans%=mod;
		}
	for(int i=1;i<=n;i++)
		if(!used[i])
		{
			a[dep]=i;
			used[i]=1;
			dfs(dep+1);
			used[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
