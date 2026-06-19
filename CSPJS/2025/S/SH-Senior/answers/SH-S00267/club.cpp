#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=1e5+2;
int t,n,a[maxn][3],dp[3][maxn>>1],c[3][3];
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		memset(dp,0,sizeof dp);
		memset(c,0,sizeof c);
		for(int i=1;i<=n;i++) {
			for(int j=0;j<3;j++) {
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=0;j<3;j++) {
				for(int k=0;k<3;k++) {
					if(c[j][j]<n/2) {
						dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
						c[i][j][j]=c[i-1][k][j]+1;
					}
				}
			}
		}
		cout<<c[1][1][1]<<'\n';
		cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<'\n';
	}
	return 0;
}
