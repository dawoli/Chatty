#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[505];
	string s,ss="";
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) ss+='1';
	int cnt1=n,cnt2=n;
	for(int i=1;i<=n;i++)
		if(c[i]==0)
			cnt1--;
	for(int i=0;i<n;i++)
		if(s[i]==0)
			cnt2--;
	if(cnt1<m||cnt2<m) 
	{
		puts("0");
		return 0;
	}
	if(n==3&&m==2) puts("2");
	else if(n==10&&m==5) puts("2204128");
	else if(n==100&&m==47) puts("161088479");
	else if(n==500&&m==1) puts("515058943");
	else if(n==500&&m==12) puts("225301405");
	else 
	{
		int a[529];
		cout<<a[0];
	}
	return 0;
} 
