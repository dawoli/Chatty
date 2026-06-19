#include<bits/stdc++.h>
using namespace std;
const int MX=998244353;
int n,m;
string s;
int a[505];
int rn=0;
long long ans=0;
bool us[505];
long long qzc[505];
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int pl,int wlq)
{
//	cout<<pl<<endl;
	if(n-wlq<m)
	{
		return;
	}
	if(pl-wlq>m)
	{
		int rn=n-pl+1;
		ans+=qzc[rn];
		ans%=MX;
		return;
	}
	if(pl>n)
	{
		if(n-wlq>=m)
		{
			ans++;
			ans%=MX;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!us[i])
		{
			if(a[i]<=wlq||s[pl]=='0')
			{
				us[i]=1;
				dfs(pl+1,wlq+1);
				us[i]=0;
			}
			else
			{
				us[i]=1;
				dfs(pl+1,wlq);
				us[i]=0;
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
//	cin>>n>>m;
	cin>>s;
	s=" "+s;
	qzc[0]=1;
	for(int i=1;i<=500;i++)
	{
		qzc[i]=qzc[i-1]*i%MX;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
//		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	printf("%lld\n",ans);
//	cout<<ans<<endl;
	return 0;
}
/*
10 1
1111111111
7 1 4 2 4 0 9 1 2 5
*/
