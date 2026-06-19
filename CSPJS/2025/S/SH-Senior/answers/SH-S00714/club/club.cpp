#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxm=205;
int T,n,idx;
int a[maxn],b[maxn],c[maxn],f[maxm][maxm][maxm];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(f,0,sizeof f);
		cin>>n;
		idx=0;
		bool Aflag=true,Bflag=true;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]>0||c[i]>0) Aflag=false;
			else if(c[i]>0) Bflag=false;
		}
		int ans=0;
		if(Aflag){
			sort(a+1,a+n+1,greater<int>());
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans;
			return 0;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i,n/2);k++){
					if(i-j-k>min(i,n/2)) continue;
					if(j>0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i]);
					if(k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+b[i]);
					if(i-j-k>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+c[i]);
					ans=max(ans,f[i][j][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
