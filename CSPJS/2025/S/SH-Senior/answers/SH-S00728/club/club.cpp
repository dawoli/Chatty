#include<bits/stdc++.h>
using namespace std;
struct node{
	int d,vis;
}dp[100010][10][10];
int t,n,q,mx,a[100010][10];
void dfs(int i,int sum,int dis1,int dis2,int dis3){
	if(i==n+1){
		mx=max(mx,sum);
		return;
	}if(dis1<q){
		dfs(i+1,sum+a[i][1],dis1+1,dis2,dis3);
	}if(dis2<q){
		dfs(i+1,sum+a[i][2],dis1,dis2+1,dis3);
	}if(dis3<q){
		dfs(i+1,sum+a[i][3],dis1,dis2,dis3+1);
	}
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		q=n/2;
		mx=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
//      dp[1][1][1].d=a[1][1];
//		dp[1][1][2].d=a[1][1];
//		dp[1][1][3].d=a[1][1];
//		dp[1][2][1].d=a[1][2];
//		dp[1][2][2].d=a[1][2];
//		dp[1][2][3].d=a[1][2];
//		dp[1][3][1].d=a[1][3];
//		dp[1][3][2].d=a[1][3];
//		dp[1][3][3].d=a[1][3];
//		dp[1][1][1].vis=q-1;
//		dp[1][2][2].vis=q-1;
//		dp[1][3][3].vis=q-1;
//		dp[1][1][2].vis=q;
//		dp[1][1][3].vis=q;
//		dp[1][2][1].vis=q;
//		dp[1][2][3].vis=q;
//		dp[1][3][1].vis=q;
//		dp[1][3][2].vis=q;
//		for(int i=2;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				for(int k=1;k<=3;k++){
//					if(dp[i-1][k][j].vis>0){
//						if(a[i][j]+dp[i-1][k][j].d>dp[i][j][1].d){
//							dp[i][j][1].d=a[i][j]+dp[i-1][k][j].d;
//							dp[i][j][2].d=a[i][j]+dp[i-1][k][j].d;
//							dp[i][j][3].d=a[i][j]+dp[i-1][k][j].d;
//							dp[i][j][j].vis=dp[i-1][k][j].vis-1;
//							if(j==1){
//								dp[i][j][2].vis=dp[i-1][k][j].vis;
//								dp[i][j][3].vis=dp[i-1][k][j].vis;
//							}else if(j==2){
//								dp[i][j][1].vis=dp[i-1][k][j].vis;
//								dp[i][j][3].vis=dp[i-1][k][j].vis;
//							}else{
//								dp[i][j][1].vis=dp[i-1][k][j].vis;
//								dp[i][j][2].vis=dp[i-1][k][j].vis;
//							}
//						}
//					}
//				}
//			}
//		}for(int i=1;i<=3;i++){
//			mx+=dp[n][i][1].d;
//		}
		dfs(1,0,0,0,0);
		printf("%d\n",mx);
	}return 0;
}
