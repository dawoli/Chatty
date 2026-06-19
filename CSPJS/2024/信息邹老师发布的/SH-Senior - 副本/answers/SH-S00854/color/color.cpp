#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int T,n,a[maxn],f[maxn][maxn][1][1];
int main(){
	//freopen("color.in","r",stdin);
	//freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int k=0;k<=1;k++)
				for(int l=0;l<=1;l++){
					int j;
					if(l==k){
						j=i-1;
						for(int m=1;m<=i-2;m++){
							if(l==0)f[i][j][k][l]=max(f[i][j][k][l],max(f[i-1][m][l][1],f[i-1][m][l][0])+(a[i]==a[i-1])*a[i]);
							else f[i][j][k][l]=max(f[i][j][k][l],max(f[i-1][m][l][1],f[i-1][m][l][0])+(a[i]==a[i-1])*a[i]);
						}
					}
					else{
						for(int j=1;j<=i-2;j++)
							for(int m=1;m<=i-2;m++){
								if(l==0)f[i][j][k][l]=max(f[i][j][k][l],f[i-1][m][0][1])
							}
					}
				}
	return 0;
}
