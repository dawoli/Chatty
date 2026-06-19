#include<bits/stdc++.h>
using namespace std;
int n,m,k,a1,b1;
int a[1000000][1000000],c[11],dp[100000][100000];
void dfs(){
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			for(int k=1;k<=n+k;k++){
			    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	} 
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a1>>b1;
		cin>>dp[a1][b1];
	}
	for(int i=1;i<=k;i++){
		cin>>c[n+i];
		for(int j=1;j<=m;j++){
			cin>>dp[n+i][j];
		}
	}
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			if(i!=j&&dp[i][j]==0){
				dp[i][j]=1000000000000;
			}
		}
	}	
	for(int i=1;i<=n;i++){
		dfs();
	} 
	int maxn=0;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
        	if(maxn<dp[i][j]){
        		maxn=dp[i][j];
			}
		} 
    }
    cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4

