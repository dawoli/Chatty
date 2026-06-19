#include<bits/stdc++.h>
using namespace std;
int T;
const int MAXN=2e3+5;
int n,maxn;
bool flag1=1,flag2=1;
priority_queue<int> q;
int dp[MAXN][105][105];
bool flag[MAXN][105][105];
struct node{
	int u,v,w;
}a[100005];
int dfs(int pos,int i,int j){
	if(pos==n+1) return 0;
	if(flag[pos][i][j]) return dp[pos][i][j];
	int k=pos-i-j;	
	if((i+1ll)<=(n/2ll)) dp[pos][i][j]=max(dp[pos][i][j],dfs(pos+1,i+1,j)+a[pos].u);
    if((j+1ll)<=(n/2ll)) dp[pos][i][j]=max(dp[pos][i][j],dfs(pos+1,i,j+1)+a[pos].v);
	if((k+1ll)<=(n/2ll)) dp[pos][i][j]=max(dp[pos][i][j],dfs(pos+1,i,j)+a[pos].w);
	flag[pos][i][j]=1;
//	cout<<pos<<" "<<i<<" "<<j<<" "<<dp[pos][i][j]<<endl;;
	return dp[pos][i][j];		
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		memset(flag,0,sizeof(flag));
		memset(a,0,sizeof(a));
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].u>>a[i].v>>a[i].w;
			if(a[i].v!=0){
				flag1=0;
			}
			if(a[i].w!=0){
				flag2=0;
			}
		} 	
		if(flag1){
			for(int i=1;i<=n;i++) q.push(a[i].u);
			int ans=0;
			for(int i=1;i<=n/2;i++) {
				int p=q.top(); q.pop();
				ans+=p;
			} 
			cout<<ans<<endl;
		}else if(flag2){
			
		}else{
			cout<<dfs(0,0,0)<<endl;
		}		
	}
	return 0;
}

