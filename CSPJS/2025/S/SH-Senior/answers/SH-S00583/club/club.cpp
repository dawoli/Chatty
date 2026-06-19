#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,maxn,maxn2;
}a[100005];
int dp[100001][4][5];
pair<int,int> max1[100001],max2[100001],max3[100001];
bool cmp(node a,node b){
	if(a.maxn==b.maxn) return a.maxn2>b.maxn2;
	return a.maxn>b.maxn;
}
int main(){
	freopen("clab.in","r",stdin);
	freopen("clab.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].x==a[i].maxn){
				a[i].maxn2=max(a[i].y,a[i].z);
			}
			if(a[i].y==a[i].maxn){
				a[i].maxn2=max(a[i].x,a[i].z);
			}
			if(a[i].z==a[i].maxn){
				a[i].maxn2=max(a[i].y,a[i].x);
			}
		}
		sort(a+1,a+n+1,cmp);
		dp[1][1][0]=a[1].x,dp[1][2][0]=a[1].y,dp[1][3][0]=a[1].z;
		dp[1][1][1]=1,dp[1][2][2]=1,dp[1][3][3]=1;
		for(int i = 2;i <= n;i++){
			int u=0,v=0,w=0;
			if(dp[i-1][1][1]+1<=n/2) u=dp[i-1][1][0];
			if(dp[i-1][2][1]+1<=n/2) v=dp[i-1][2][0];
			if(dp[i-1][3][1]+1<=n/2) w=dp[i-1][3][0];
			if(u>=v&&u>=w&&(u!=0||v!=0||w!=0)){
				dp[i][1][0]=u+a[i].x; dp[i][1][1]=dp[i-1][1][1]+1; dp[i][1][2]=dp[i-1][1][2]; dp[i][1][3]=dp[i-1][1][3];
			}else if(v>=u&&v>=w&&(u!=0||v!=0||w!=0)){
				dp[i][1][0]=v+a[i].x; dp[i][1][1]=dp[i-1][2][1]+1; dp[i][1][2]=dp[i-1][2][2]; dp[i][1][3]=dp[i-1][2][3];
			}else if(w>=v&&w>=u&&(u!=0||v!=0||w!=0)){
				dp[i][1][0]=w+a[i].x; dp[i][1][1]=dp[i-1][3][1]+1; dp[i][1][2]=dp[i-1][3][2]; dp[i][1][3]=dp[i-1][3][3];
			}
			u=v=w=0;
			if(dp[i-1][1][2]+1<=n/2) u=dp[i-1][1][0];
			if(dp[i-1][2][2]+1<=n/2) v=dp[i-1][2][0];
			if(dp[i-1][3][2]+1<=n/2) w=dp[i-1][3][0];
			if(u>=v&&u>=w&&(u!=0||v!=0||w!=0)){
				dp[i][2][0]=u+a[i].y; dp[i][2][1]=dp[i-1][1][1]; dp[i][2][2]=dp[i-1][1][2]+1; dp[i][2][3]=dp[i-1][1][3];
			}
		//	cout << dp[i][2][0] << '\n';
			else if(v>=u&&v>=w&&(u!=0||v!=0||w!=0)){
				dp[i][2][0]=v+a[i].y; dp[i][2][1]=dp[i-1][2][1]; dp[i][2][2]=dp[i-1][2][2]+1; dp[i][2][3]=dp[i-1][2][3];
			}
			//cout << dp[i][2][0] << '\n';
			else if(w>=v&&w>=u&&(u!=0||v!=0||w!=0)){
				dp[i][2][0]=w+a[i].y; dp[i][2][1]=dp[i-1][3][1]; dp[i][2][2]=dp[i-1][3][2]+1; dp[i][2][3]=dp[i-1][3][3];
			}
		//	cout << dp[i][2][0] << '\n';
			u=v=w=0;
			if(dp[i-1][1][3]+1<=n/2) u=dp[i-1][1][0];
			if(dp[i-1][2][3]+1<=n/2) v=dp[i-1][2][0];
			if(dp[i-1][3][3]+1<=n/2) w=dp[i-1][3][0];
			if(u>=v&&u>=w&&(u!=0||v!=0||w!=0)){
				dp[i][3][0]=u+a[i].z; dp[i][3][1]=dp[i-1][1][1]; dp[i][3][2]=dp[i-1][1][2]; dp[i][3][3]=dp[i-1][1][3]+1;
			}
			else if(v>=u&&v>=w&&(u!=0||v!=0||w!=0)){
				dp[i][3][0]=v+a[i].z; dp[i][3][1]=dp[i-1][2][1]; dp[i][3][2]=dp[i-1][2][2]; dp[i][3][3]=dp[i-1][2][3]+1;
			}
			else if(w>=v&&w>=u&&(u!=0||v!=0||w!=0)){
				dp[i][3][0]=w+a[i].z; dp[i][3][1]=dp[i-1][3][1]; dp[i][3][2]=dp[i-1][3][2]; dp[i][3][3]=dp[i-1][3][3]+1;
			}
			//cout << dp[i][1][2] << ' ' << dp[i][2][2]  << ' ' << dp[i][3][2] << '\n';
			//cout << dp[i][1][1] << ' ' << dp[i][2][1]  << ' ' << dp[i][3][1] << '\n';
			//cout << dp[i][1][3] << ' ' << dp[i][2][3]  << ' ' << dp[i][3][3] << '\n';
		}
		cout << max(dp[n][1][0],max(dp[n][2][0],dp[n][3][0])) << '\n';
	}
	return 0;
}
