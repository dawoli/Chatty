#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int T,n,a[MAXN],f[2][MAXN][2];
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			f[0][i][0]=0;
			f[1][i][1]=0;
			f[0][i][1]=0;
			f[1][i][0]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i-1;j++){
				f[i&1][j][1]=f[i-1&1][j][1]+(a[i]==a[i-1]?a[i]:0);
				f[i&1][i-1][1]=max(f[i&1][i-1][1],f[i-1&1][j][0]+(a[i]==a[j]?a[i]:0));
				f[i&1][j][0]=f[i-1&1][j][0]+(a[i]==a[i-1]?a[i]:0);
				f[i&1][i-1][0]=max(f[i&1][i-1][0],f[i-1&1][j][1]+(a[i]==a[j]?a[i]:0));
			}
		}
		for(int i=1;i<n;i++){
			ans=max(ans,max(f[n&1][i][1],f[n&1][i][0]));
		}
		cout<<ans<<endl;
	}
}

