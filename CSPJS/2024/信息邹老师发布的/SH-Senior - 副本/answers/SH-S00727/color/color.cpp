#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e3+5;
int t,n,a[MAXN],ans,f[MAXN][MAXN];
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int awa=1;awa<=t;awa++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i-1;j++){
				if(a[i-1]==a[i]) f[i][j]=f[i-1][j]+a[i];
				else f[i][j]=f[i-1][j];
				ans=max(ans,f[i][j]);
			}
			for(int j=1;j<=i-1;j++){
				if(a[i]==a[j])	f[i][i-1]=max(f[i][i-1],f[i-1][j]+a[i]);
				else f[i][i-1]=max(f[i][i-1],f[i-1][j]);
			}ans=max(ans,f[i][i-1]);
		}
		cout<<ans<<endl;
		ans=0;
		for(int i=1;i<=n;i++){
			a[i]=0;
			for(int j=1;j<=n;j++) f[i][j]=0;
		}
	}
	
}
