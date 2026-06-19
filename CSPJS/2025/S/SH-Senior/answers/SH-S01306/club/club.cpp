#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4];
int n,t;
int solve(){
	int ans=0;
	if(n==2){
		ans=max(ans,a[1][1]+a[2][2]);
		ans=max(ans,a[1][2]+a[2][3]);
		ans=max(ans,a[1][2]+a[2][1]);
		ans=max(ans,a[1][2]+a[2][3]);
		ans=max(ans,a[1][3]+a[2][1]);
		ans=max(ans,a[1][3]+a[2][2]);
		return ans;
	}
	else if(n==4){
		//1 and 2
		ans=max(ans,a[1][1]+a[2][1]);
		ans=max(ans,a[1][1]+a[2][2]);
		ans=max(ans,a[1][1]+a[2][3]);
		ans=max(ans,a[1][2]+a[2][1]);
		ans=max(ans,a[1][2]+a[2][2]);
		ans=max(ans,a[1][2]+a[2][3]);
		ans=max(ans,a[1][3]+a[2][1]);
		ans=max(ans,a[1][3]+a[2][2]);
		ans=max(ans,a[1][3]+a[2][3]);
		//1 and 3
		ans=max(ans,a[1][1]+a[3][1]);
		ans=max(ans,a[1][1]+a[3][2]);
		ans=max(ans,a[1][1]+a[3][3]);
		ans=max(ans,a[1][2]+a[3][1]);
		ans=max(ans,a[1][2]+a[3][2]);
		ans=max(ans,a[1][2]+a[3][3]);
		ans=max(ans,a[1][3]+a[3][1]);
		ans=max(ans,a[1][3]+a[3][2]);
		ans=max(ans,a[1][3]+a[3][3]);
		//1 and 4
		ans=max(ans,a[1][1]+a[4][1]);
		ans=max(ans,a[1][1]+a[4][2]);
		ans=max(ans,a[1][1]+a[4][3]);
		ans=max(ans,a[1][2]+a[4][1]);
		ans=max(ans,a[1][2]+a[4][2]);
		ans=max(ans,a[1][2]+a[4][3]);
		ans=max(ans,a[1][3]+a[4][1]);
		ans=max(ans,a[1][3]+a[4][2]);
		ans=max(ans,a[1][3]+a[4][3]);
		//2 and 3
		ans=max(ans,a[2][1]+a[3][1]);
		ans=max(ans,a[2][1]+a[3][2]);
		ans=max(ans,a[2][1]+a[3][3]);
		ans=max(ans,a[2][2]+a[3][1]);
		ans=max(ans,a[2][2]+a[3][2]);
		ans=max(ans,a[2][2]+a[3][3]);
		ans=max(ans,a[2][3]+a[3][1]);
		ans=max(ans,a[2][3]+a[3][2]);
		ans=max(ans,a[2][3]+a[3][3]);
		//2 and 4
		ans=max(ans,a[2][1]+a[4][1]);
		ans=max(ans,a[2][1]+a[4][2]);
		ans=max(ans,a[2][1]+a[4][3]);
		ans=max(ans,a[2][2]+a[4][1]);
		ans=max(ans,a[2][2]+a[4][2]);
		ans=max(ans,a[2][2]+a[4][3]);
		ans=max(ans,a[2][3]+a[4][1]);
		ans=max(ans,a[2][3]+a[4][2]);
		ans=max(ans,a[2][3]+a[4][3]);
		//3 and 4
		ans=max(ans,a[3][1]+a[4][1]);
		ans=max(ans,a[3][1]+a[4][2]);
		ans=max(ans,a[3][1]+a[4][3]);
		ans=max(ans,a[3][2]+a[4][1]);
		ans=max(ans,a[3][2]+a[4][2]);
		ans=max(ans,a[3][2]+a[4][3]);
		ans=max(ans,a[3][3]+a[4][1]);
		ans=max(ans,a[3][3]+a[4][2]);
		ans=max(ans,a[3][3]+a[4][3]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
		int ans=solve();
		cout<<ans<<endl;
	}
	return 0;
}
