#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=510;
const int mod=998244353;
int n,m;
string s;
int a[N];
int p[N];
inline void solve1(){
	ll ans=0;
	iota(p+1,p+1+n,1);
	do{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||cnt>=a[p[i]])
				cnt++;
		ans+=((n-cnt)>=m);
	}while(next_permutation(p+1,p+1+n));
	cout<<ans%mod<<endl;
}
int f[1<<18][19];
inline void solve2(){
	f[0][0]=1;
	for(int S=0;S<(1<<n);S++){
		int cnt=__builtin_popcount(S);
		for(int j=0;j<=cnt;j++){
			for(int i=0;i<n;i++)
				if((S>>i)&1){
					if(s[cnt]=='0')
						f[S][j]=(1ll*f[S][j]+f[S^(1<<i)][j])%mod;
					else{
						if(j)
							f[S][j]=(1ll*f[S][j]+f[S^(1<<i)][j]*(cnt-1-j>=a[i+1])+(cnt-j<a[i+1])*f[S^(1<<j)][j-1])%mod;
						else
							f[S][j]=(1ll*f[S][j]+(a[i+1]==0)*(f[S^(1<<j)][j]))%mod;
					}
				}
		}
	}
	ll ans=0;
	for(int i=m;i<=n;i++)
		(ans+=f[(1<<n)-1][i])%=mod;
	cout<<ans<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>s,s=' '+s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=10)
		solve1();
	else if(n<=18)
		solve2();
	else
		cout<<0<<endl;
	return 0;
}
