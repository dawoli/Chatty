#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,cnt,ans=0,a[510],vis[510],c[510];
char s[510];
int f(int x)
{
	long long ans=1;
	for(int i=1;i<=x;i++)
	{
		ans*=1ll*i;
		ans%=mod;
	}
	return ans;
}
int g(int deep)
{
	if(deep==n+1)
	{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0')
				cnt++;
			else if(cnt>=c[a[i]])
				cnt++;
//			else
//				cout<<a[i]<<endl;
		}
		if(n-cnt>=m)
		{
//			cout<<cnt<<endl;
//			for(int i=1;i<=n;i++)
//				cout<<a[i]<<" ";
//			cout<<endl;
			ans++;
		}
		ans%=mod;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			a[deep]=i;
			vis[i]=1;
			g(deep+1);
			vis[i]=0;
		}
	}
	return 0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",c+i);
	}
	g(1);
	printf("%d",ans);
	return 0;
}
