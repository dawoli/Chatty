#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m,k;
int ans;
void dfs(int x,int y,int d,int u,int v){
	if(v==0){
		ans=max(ans,u);
		return ;
	}
	if(x+dx[d]<=0||x+dx[d]>n||y+dy[d]<=0||y+dy[d]>m||a[x+dx[d]][y+dx[d]]==1){
		dfs(x,y,(d+1)%4,u,v-1);
	}
	else{
		a[x][y]=1;
		dfs(x+dx[d],y+dy[d],d,u+1,v-1);
		a[x][y]=0;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	int x,y,d;
	string s;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++){
			cin>>s;
			for(int k=0;k<m;k++){
				if(s[k]=='x'){
					a[j][k+1]=1;
				}
				else{
					a[j][k+1]=0;
				}
			}
		}
		dfs(x,y,d,1,k);
		cout<<ans+1<<'\n';
	}
	return 0;
}
