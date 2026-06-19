#include<bits/stdc++.h>
using namespace std;
int t,n,m;
bool vis[1001][1001];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,-0};
char mapp[1001][1001];
void dfs(int x,int y,int dir,int step,int ans){
	if(step==0){
		cout<<ans<<endl;
		return;
	}	
	if((x+dx[dir])>=1&&(x+dx[dir])<=n&&(y+dy[dir])>=1&&(y+dy[dir])<=m&&mapp[x+dx[dir]][y+dy[dir]]=='.'){
		if(vis[x+dx[dir]][y+dy[dir]]==false){
			ans++;
			vis[x+dx[dir]][y+dy[dir]]=true;
		}
		dfs(x+dx[dir],y+dy[dir],dir,step-1,ans);
	}else{
		dir=(dir+1)%4;
		dfs(x,y,dir,step-1,ans);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t>0){
		int k;
		cin>>n>>m>>k;
		for(int j=1;j<=n;j++){
			for(int p=1;p<=m;p++){
				vis[j][p]=false;
			}
		}
		int x,y,d;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++){
			for(int p=1;p<=m;p++){
				cin>>mapp[j][p];
			}
		}
		vis[x][y]=true;
		if(k==1){
			if((x+dx[d])>=1&&(x+dx[d])<=n&&(y+dy[d])>=1&&(y+dy[d])<=m&&mapp[x+dx[d]][y+dy[d]]=='.'){
				cout<<2<<endl;
				continue;
			}else{
				cout<<1<<endl;
				continue;
			}
		}
		dfs(x,y,d,k,1);
		n=0;
		m=0;
		t--;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
