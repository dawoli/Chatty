#include<bits/stdc++.h>
using namespace std;
int ans,d,x,y;
char mp[1005][1005];
bool vis[1005][1005];
void walk(int xx,int yy){
	if(mp[xx][yy]=='.'){
		if(!vis[xx][yy])ans++;
		x=xx,y=yy;
		vis[xx][yy]=1;
		return;
	}
	else{
		d=(d+1)%4;
		return;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		int m,n,k;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(d==0){
				walk(x,y+1);
			}
			else if(d==1){
				walk(x+1,y);
			}
			else if(d==2){
				walk(x,y-1);
			}
			else if(d==3){
				walk(x-1,y);
			}
		}
		cout<<ans;
	}
	return 0;
}
