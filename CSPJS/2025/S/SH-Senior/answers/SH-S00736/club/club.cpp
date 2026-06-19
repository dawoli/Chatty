#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
int voidpos(int l,int r){
	int mid=(l+r)>>1;
	return lowbit(mid);
}
struct nd{
	int x,y,z;
}a[100001];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		int dp[10001][4]={0};
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i].x);
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				voidpos(a[i].y,a[i].z);
				dp[i][j]=max(dp[i-1][j-1],dp[i][j]);
			}
		}		
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				voidpos(a[i].x,a[i].z);
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[n][1]<<endl;
	}	
} 
