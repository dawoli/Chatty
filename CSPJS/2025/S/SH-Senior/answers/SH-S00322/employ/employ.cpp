#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,mod=998244353;

int n,m,c[N];
ll ans;
bool A=1;
string s;

int main()
	{
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<n;i++) if(s[i]=='0') A=0;
	if(n<=10)
	{
		
	}
	if(A)//wrong
	{
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<(ans+mod)%mod;
		return 0;
	}
	if(m==1)//wrong
	{
		int cnt=0;
		while(s[cnt]=='0') cnt++;
		cnt++;
		for(int i=1;i<=n;i++) if(c[i]>cnt) ans++;
		for(int i=1;i<n;i++) ans=ans*i%mod;
		cout<<(ans+mod)%mod;
		return 0;
	}
	return 0;
	}
