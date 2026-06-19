#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int f[(1<<18)+5][19];
int n,m;
int ppap(int x){
	int ret=0;
	while(x){
		ret+=(x&1);
		x>>=1;
	}
	return ret;
}
int a[19];
int c[19];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	f[0][0]=1;
	for(int i=0;i<1<<n;i++){
		int daze=ppap(i);
		for(int j=0;j<=n;j++){
			for(int k=0;k<n;k++){
				if(!(i>>k&1)){			
					int tmp=0;
					if(j>=c[k])tmp=1;
					if(!a[daze])tmp=1;
					f[i|(1<<k)][j+tmp]+=f[i][j];
					f[i|(1<<k)][j+tmp]%=mod;
				}
			}
		}
	}
	int ans=0;
	for(int j=0;j<=n-m;j++){
		ans=(ans+f[(1<<n)-1][j])%mod;
	}
	cout<<ans;
	return 0;
}
