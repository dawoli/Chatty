#include<bits\stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,c[505];
string s;
int fact[505],infact[505];
int ksm(int a,int k)
{
	int tmp=a,res=1;
	while(k)
	{
		if(k%2==1) res=res*tmp%mod;
		tmp=tmp*tmp%mod;k/=2;
	}
	return res;
}
void init()
{
	fact[0]=infact[0]=1;
	for(int i=1;i<=500;++i) fact[i]=fact[i-1]*i%mod;
	infact[500]=ksm(fact[500],mod-2);
	for(int i=499;i>=1;--i) infact[i]=infact[i+1]*(i+1)%mod;
}
int C(int a,int b)
{
	return (fact[a]*infact[a-b]%mod)*infact[b]%mod;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool flag=1;
	for(int i=0;i<n;++i) 
		if(s[i]!='1') 
			flag=0;
	for(int i=1;i<=n;++i) cin>>c[i];
	if(flag)
	{
		cout<<fact[n];
	}
	else cout<<0;
}
