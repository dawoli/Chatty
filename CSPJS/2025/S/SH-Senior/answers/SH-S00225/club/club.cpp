#include<bits/stdc++.h>
using namespace std;
int a[100010][5];
int dp[100010][5];
int join[5];
int n;
int maxv;
void dfs(int dep,int sum){
	if(dep==n+1){
		maxv=max(maxv,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(join[i]+1<=n/2){
			join[i]++;
			dfs(dep+1,sum+a[dep][i]);
			join[i]--;
		}
	} 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		maxv=0;
		memset(dp,0,sizeof(dp));
		memset(join,0,sizeof(join));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1,0);
		cout<<maxv<<endl;
	}
	return 0;
}
