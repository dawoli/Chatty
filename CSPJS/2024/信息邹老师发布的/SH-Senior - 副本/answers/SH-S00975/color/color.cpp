#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e5+10;
const int N=1e4+10;
int T;
int n;
ll ans;
int a[M];
ll f[2][N][N];
ll g[2][N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n>N){cout<<':'<<n<<'\n';continue;}
		for(int i=1;i<=n;i++){
			g[0][i-1]=g[1][i-1]=0;
			for(int j=1;j<=i-3;j++){
				f[0][j][i-1]=f[1][j][i-2]+(a[i]==a[j]?a[i]:0);
				f[1][i-1][j]=f[0][i-2][j]+(a[i]==a[j]?a[i]:0);
				g[0][i-1]=max(f[0][j][i-1],g[0][i-1]);
				g[1][i-1]=max(f[1][i-1][j],g[1][i-1]);
			}
			if(i>=2){
				f[0][i-2][i-1]=g[1][i-2]+(a[i]==a[i-2]?a[i]:0);
				f[1][i-1][i-2]=g[0][i-2]+(a[i]==a[i-2]?a[i]:0);
				g[0][i-1]=max(g[0][i-1],f[0][i-2][i-1]);
				g[1][i-1]=max(g[1][i-1],f[1][i-1][i-2]);
			}
			if(i>=1){
				for(int o=1;o<i-1;o++){
					f[0][i-1][o]=g[0][o]+(a[i]==a[i-1]?a[i]:0);
					f[1][o][i-1]=g[1][o]+(a[i]==a[i-1]?a[i]:0);
					g[0][o]=f[0][i-1][o];
					g[1][o]=f[1][o][i-1];
				}
			}
		}
		for(int i=0;i<n;i++) ans=max({g[0][i],g[1][i],ans});
		cout<<ans<<'\n';
	}
	return 0;
}
