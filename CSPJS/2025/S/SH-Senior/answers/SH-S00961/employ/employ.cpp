#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<48||ch>57){if(ch=='-') f=-1;ch=getchar();}
	while(ch>=48&&ch<=57) x=x*10+ch-48,ch=getchar();
	return x*f;
}
const int N=1000;
ll n,m,a[N];
string in;
ll s[N],ok1=1,ans,sum;
ll vis[N],b[N];
int check()
{
	int res=0;
	for(int i=1;i<=n;++i)
	{
		if(res>=b[i]||s[i]==0) ++res;
	}
	if(n-res>=m) return 1;
	return 0;
}
void dfs(int step)
{
	if(step==n+1)
	{
		if(check()) ++ans;
		if(ans>=mod) ans-=mod;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			vis[i]=1;
			b[step]=a[i];
			dfs(step+1);
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>in;
	for(int i=0;i<n;++i) s[i+1]=in[i]-'0';
	for(int i=1;i<=n;++i) a[i]=read();
	if(n<=10)
	{
		dfs(1);
		cout<<ans<<"\n";
		return 0;
	}
	return 0;
}
