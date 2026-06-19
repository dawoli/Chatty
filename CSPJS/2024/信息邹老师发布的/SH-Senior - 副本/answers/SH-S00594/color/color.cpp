#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[20005],f[2][20005][2];
signed main(){
	cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n>2e4) break;
		for(int i=0;i<n;i++){
			f[0][i][0]=0;
			f[0][i][1]=0;
			f[1][i][0]=0;
			f[1][i][1]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<i-1;j++){
				f[i&1][j][0]=f[(i-1)&1][j][0]+(a[i]==a[i-1]?a[i]:0);
				f[i&1][j][1]=f[(i-1)&1][j][1]+(a[i]==a[i-1]?a[i]:0);
				f[i&1][i-1][0]=max(f[i&1][i-1][0],f[(i-1)&1][j][1]+(a[i]==a[j]?a[i]:0));
				f[i&1][i-1][1]=max(f[i&1][i-1][1],f[(i-1)&1][j][0]+(a[i]==a[j]?a[i]:0));
			}
		}
		int ans=0;
		for(int i=0;i<n;i++) ans=max(ans,max(f[n&1][i][0],f[n&1][i][1]));
		cout<<ans<<endl;
	}
}
