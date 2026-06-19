#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][3],f[205][205][205];
int main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for (int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=0;j<=min(i,n/2);j++){
				for (int k=0;k<=min(i-j,n/2);k++){
					f[i][j][k]=0;
				}
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=0;j<=min(i,n/2);j++){
				for (int k=0;k<=min(i-j,n/2);k++){
					if (i-j-k<n/2){
						if (j==0 && k==0){
							f[i][j][k]=f[i-1][j][k]+a[i][3];
						}
						else if (j==0){
							f[i][j][k]=max(f[i-1][j][k]+a[i][3],f[i-1][j][k-1]+a[i][2]);
						}
						else if (k==0){
							f[i][j][k]=max(f[i-1][j][k]+a[i][3],f[i-1][j-1][k]+a[i][1]);
						}
						else{
							f[i][j][k]=max(f[i-1][j-1][k]+a[i][1],f[i-1][j][k-1]+a[i][2]);
							f[i][j][k]=max(f[i-1][j][k]+a[i][3],f[i][j][k]);
						}
					}
					else {
						if (j==0 && k==0){
							f[i][j][k]=f[i-1][j][k]+a[i][3];
						}
						else if (j==0){
							f[i][j][k]=f[i-1][j][k-1]+a[i][2];
						}
						else if (k==0){
							f[i][j][k]=f[i-1][j-1][k]+a[i][1];
						}
						else{
							f[i][j][k]=max(f[i-1][j-1][k]+a[i][1],f[i-1][j][k-1]+a[i][2]);
						}
					}
			}
		}
	}
		int ans=0;
		for (int i=0;i<=n/2;i++){
				for (int j=0;j<=n/2;j++){
					ans=max(ans,f[n][i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

