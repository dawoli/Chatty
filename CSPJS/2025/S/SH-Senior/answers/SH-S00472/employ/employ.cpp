#include<bits/stdc++.h>
#define mkp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn= 509 ;
const ll MOD = 998244353 ;

int n,m;
char s[509];
int c[509];
ll ans=0;

bool isA()
{
	for(int i=1;i<=n;++i)
		if(s[i]=='0') return false;
	return true;
}

void solveA()
{
	//数0个数 不行 0对后面有影响 
	
	ans=1;
	for(ll i=n;i>=1;--i)
		ans=ans*i%(ll)998244353;
	printf("%lld",ans);
}

bool vst[509];
void dfs(int dep,int fail)
{
	if(n-fail<m) return ;
	if(dep==n+1)
	{
		ans=(ans+1)%MOD;
		return ;
	}
	for(int i=1;i<=n;++i)
	{
		if(vst[i])continue;
		vst[i]=true;
		if(fail>=c[i])
		{
			dfs(dep+1,fail+1);
		}
		else
		{
			dfs(dep+1,fail+(s[dep]=='0'));
		}
		vst[i]=false;
	}
}

void solve()
{
	ans=0;
	dfs(1,0);
	printf("%lld",ans);
}


int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	scanf("%s\n",&s[1]);
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
		
	//for(int i=1;i<=n;++i)
	//	printf("%c",s[i]);
	
	if(isA())
	{
		solve();
	}
	else
	{
		solve();
	}
	
	return 0;
}

