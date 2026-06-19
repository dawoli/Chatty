#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5e2+5;
const int MOD=998244353;

ll n,m,s[N],a[N],ans,anss;
bool ok[N],b[N];

void dfs(ll u,ll nw)
{
//	if(u==n)anss++;
	cout<<s[u-1]<<' '<<a[nw]<<endl;
	if(!b[u]||s[u-1]>=a[nw])
	{
		s[u]=s[u-1]+1;
	}
	if(n-s[u]<m)
	{
		s[u]=0;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!ok[i])
		{
			ok[i]=1;
			dfs(u+1,i);
			ok[i]=0;
		}
	}
//	if(u==n)cout<<s[n]<<endl;
	if(u==n&&n-s[n]>=m)
	{
		ans++;
		ans%=MOD;
	}
	s[u]=0;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		b[i]=c-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	b[0]=1;
	a[0]=0x3f3f3f3f;
//	anss=0;
	dfs(0,0);
	cout<<ans%MOD<<endl;
//	cout<<anss<<endl;
	return 0;
}
