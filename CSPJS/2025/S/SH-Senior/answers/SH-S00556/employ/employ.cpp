#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
char a[20];
int c[20];
ll f[1<<18][20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	cin>>a+1;
	for(int i=1;i<=n;i++) cin>>c[i];
	f[0][0]=1;
	for(int st=1;st<(1<<n);st++){
		int nw=0;
		for(int i=0;i<n;i++) if(st>>i&1) nw++;
		for(int i=1;i<=n;i++){
			if(st>>(i-1)&1){
				int pv=st^(1<<(i-1));
				if(a[nw]=='0') for(int j=nw;j>=0;j--) f[st][j]=(f[st][j]+f[pv][j])%mod;
				else {
					for(int j=nw-1;j>nw-1-c[i] && j>=0;j--){
						f[st][j+1]=(f[st][j+1]+f[pv][j])%mod;
					}
					for(int j=nw-1-c[i];j>=0;j--){
						f[st][j]=(f[st][j]+f[pv][j])%mod;
					}
				}
			}
		}
	}
	ll ans=0;
	for(int j=m;j<=n;j++) ans=(ans+f[(1<<n)-1][j])%mod;
	cout<<ans;
	return 0;
}
