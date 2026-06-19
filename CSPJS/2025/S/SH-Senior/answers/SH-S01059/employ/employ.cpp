#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 505
#define mod 998244353
int n,m;
char s[N];
int c[N];
int f[1<<19][19];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	if(n<=18){
		int MX=(1<<n);
		f[0][0]=1;
		for(int S=0;S<MX-1;S++)
		for(int j=0;j<=n;j++)
		if(f[S][j]){
			int num=0;
			for(int i=1;i<=n;i++)
			if(S&(1<<(i-1))) num++;
			if(j+n-num<m) continue;
			for(int i=1;i<=n;i++)
			if(!(S&(1<<(i-1))))
			{
				int _j=j+((c[i]>num-j)&&(s[num+1]-'0'));
				(f[S|(1<<(i-1))][_j]+=f[S][j])%=mod;
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++)
			ans=(ans+f[MX-1][i])%mod;
		cout<<ans;
	}
	return 0;
}
