#include<bits/stdc++.h>
using namespace std;
char dp[1005][1005]={};
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,k,x,y,d,ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>dp[i][j];
			}
		}
		while(k){
			if(x+dx[d]<=n&&x+dx[d]>=1&&y+dy[d]<=m&&y+dy[d]>=1&&dp[x+dx[d]][y+dy[d]]!='x'){
				x+=dx[d];
				y+=dy[d];
				k--;
				ans++;
			}
			else{
				d=(d+1)%4;
				k--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
