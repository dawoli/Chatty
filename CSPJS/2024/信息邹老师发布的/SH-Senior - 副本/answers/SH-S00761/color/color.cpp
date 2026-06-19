#include<bits/stdc++.h>
using namespace std;
int t,n,a[2009],f[2009][2][2009],ans;
int d(int x,int y){
	if(x==y) return x;
	return 0;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n,ans=0;
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j) f[i][0][j]=0,f[i][1][j]=0;
		for(int i=1;i<=n;++i) cin>>a[i];
		a[0]=-1;
		for(int i=2;i<=n;++i){
			for(int j=i-1;j>=0;--j)
				if(j==i-1){
					int tmp=0;
					for(int k=i-2;k>=0;--k) tmp=max(tmp,f[i-1][0][k]+d(a[i],a[k]));
					f[i][1][j]=tmp;
				}
				else{
					f[i][1][j]=f[i-1][1][j]+d(a[i],a[i-1]);
				}
			for(int j=i-1;j>=0;--j)
				if(j==i-1){
					int tmp=0;
					for(int k=i-2;k>=0;--k) tmp=max(tmp,f[i-1][1][k]+d(a[i],a[k]));
					f[i][0][j]=tmp;
				}
				else{
					f[i][0][j]=f[i-1][0][j]+d(a[i],a[i-1]);
				}
		}
		for(int i=0;i<n;++i) ans=max(ans,max(f[n][1][i],f[n][0][i]));
		cout<<ans<<endl;
	}
	return 0;
}

