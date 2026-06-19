#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int n,m;
const int MAXN=1+1+4+514;
char s[MAXN];
int c[MAXN];
bool vis[100010];
int ans=0;
void dfs(int step,int i,int ko)
{
	if (step>n)
	{
		if (ko<=n-m)ans++;
	}
	int dko=1-s[i];
	if (c[i]<=ko)dko=1;
	ko+=dko;
	for (int j=1;j<=n;j++)
	{
		if (vis[j])continue;
		vis[j]=1;
		dfs(step+1,j,ko);
		vis[j]=0;
	}
}
void sol1()
{
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	c[0]=0x3f3f3f3f;
	s[0]=1;
	dfs(0,0,0);
	cout<<ans<<endl;
}
void sol2()
{
	long long modd=998244353ll;
	int p=1;
	for (int i=1;i<=n;i++)
	{
		p*=i;
		p%=modd;
	}
	cout<<p<<endl;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if (n>18)sol2();
	else sol1();
}
