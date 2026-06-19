#include<bits/stdc++.h>
using namespace std;
int q,n,m,gmap[1001][1001],dp[15][15],f[15][15],cnt;
int mnq[1000],mnp[1000],h=1,t=0;
int fx[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char s;
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	cin>>q;
	for(int p=1;p<=q;p++){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s;
				if(s=='.') gmap[i][j]=1;//表示可走
				if(s=='$') gmap[i][j]=2,cnt++;//表示木箱
				if(s=='*') gmap[i][j]=3;//表示铁箱，不可走 
			}
		}//输入
		if(cnt==0){
			cout<<"0"<<" "<<n+m-2<<endl;
			continue;
		}
		if(n==1){
			cout<<cnt<<" "<<m-1<<endl;
			continue;
		}
		memset(dp,10000,sizeof(dp));memset(f,10000,sizeof(f));
		dp[1][1]=0,f[1][1]=0;
		for(int h=1;h<=100;h++){
			int an=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(gmap[i][j]==3) continue;
					if(dp[i-1][j]<dp[i][j]||(f[i-1][j]+1<f[i][j]&&dp[i-1][j]<=dp[i][j])){
						dp[i][j]=dp[i-1][j],f[i][j]=f[i-1][j]+1,an=1;
						if(gmap[i][j]==2) dp[i][j]++;
					}
					if(dp[i+1][j]<dp[i][j]||(f[i+1][j]+1<f[i][j]&&dp[i+1][j]<=dp[i][j])){
						dp[i][j]=dp[i+1][j],f[i][j]=f[i+1][j]+1,an=1;
						if(gmap[i][j]==2) dp[i][j]++;
					}
					if(dp[i][j-1]<dp[i][j]||(f[i][j-1]+1<f[i][j]&&dp[i][j-1]<=dp[i][j])){
						dp[i][j]=dp[i][j-1],f[i][j]=f[i][j-1]+1,an=1;
						if(gmap[i][j]==2) dp[i][j]++;
					}
					if(dp[i][j+1]<dp[i][j]||(f[i][j+1]+1<f[i][j]&&dp[i][j+1]<=dp[i][j])){
						dp[i][j]=dp[i][j+1],f[i][j]=f[i][j+1]+1,an=1;
					}
					//if(gmap[i][j]==2&&h==1) dp[i][j]++;
					//if(an==0) break;
				}
			}
		}
		cout<<dp[n][m]<<" "<<f[n][m]<<endl;
	}
	return 0;
}
