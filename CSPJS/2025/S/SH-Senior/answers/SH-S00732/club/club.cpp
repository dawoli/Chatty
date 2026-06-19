#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,sum[3],cnt[3],ans;
struct node{
	int d[3];
	void input(){
		for(int j=0;j<3;j++)cin>>d[j];
	}
}a[N];
bool cmp(node a,node b){
	return a.d[0]>b.d[0];
}
bool compare(node a,node b){
	return a.d[1]-a.d[0]>b.d[1]-b.d[0];
}
void dfs(int id=1){
	if(id>n){
		ans=max(ans,sum[0]+sum[1]+sum[2]);
		return;
	}
	for(int j=0;j<3;j++){
		if(cnt[j]<n/2){
			sum[j]+=a[id].d[j];
			cnt[j]++;
			dfs(id+1);
			cnt[j]--;
			sum[j]-=a[id].d[j];
		}
	}
}
void solve(){
	ans=0;
	bool spa=1,spb=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i].input();
		spa&=a[i].d[1]==0&&a[i].d[2]==0;
		spb&=a[i].d[2]==0;
	}
	if(spa){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)ans+=a[i].d[0];
	}else if(spb){
		for(int i=1;i<=n;i++)ans+=a[i].d[0];
		sort(a+1,a+n+1,compare);
		for(int i=1;i<=n/2;i++)ans+=a[i].d[1]-a[i].d[0];
	}else dfs();
	cout<<ans<<'\n';
	return;
}
//int n,dp[2][N][3],cnt[N][3]; 
//void solve(){
//	memset(dp,0,sizeof(dp));
//	cin>>n;
//	for(int i=1;i<=n;i++)a[i].input();
//	for(int i=1;i<=n;i++){
//		int p=i&1,q=1^p;
//		for(int k=0;k<3;k++){
//			for(int j=n/2;j;j--){
//				dp[p][j][k]=dp[q][j][k];
//				for(int l=0;l<3;l++){
//					if(!j&&k==l)continue;
//					dp[p][j][k]=max(dp[p][j][k],dp[q][j-(k==l)][l]+a[i].d[k]);
//				}
//			}
//		}
//	}
//	cout<<max({dp[n&1][n/2][0],dp[n&1][n/2][1],dp[n&1][n/2][2]})<<'\n';
//	return;
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
f(i)=max({a[i][0]+f(i+1),a[i][1]+f(i+1),a[i][2]+f(i+1)});
*/
