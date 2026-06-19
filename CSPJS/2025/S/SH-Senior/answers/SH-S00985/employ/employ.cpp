#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000],ans,flag,sum[1000],l,cnt={1,1};
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	memset(sum,1,sizeof(sum));
	for(int i=2;i<=500;i++) sum[i]=sum[i-1]*i%998244353;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(s[i-1]!='1') flag++;
		if(a[i]==0) cnt++;
	}
	if(n-max(cnt,flag)<m) return cout<<0,0;
	if(flag==0)
	{
		sort(a+1,a+n+1);
		for(int i=n-m;i>=1;i--)
			if(a[i]!=a[i+1])
			{
				l=min(cnt,a[i+1]-1);
				break;
			}
		for(int i=0;i<=l;i++) ans=(ans+sum[i]*sum[n-cnt]%998244353*sum[cnt-i]%998244353)%998244353;
		cout<<ans;
	}
	else cout<<sum[n];
}
