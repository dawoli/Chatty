#include<bits/stdc++.h>
using namespace std;
bool mp[1009][1009],vis[1009][1009];
int n,m,k,x,y,d,t,cnt=1;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void solve(){
	for(int i=1;i<=k;i++){
		int tx=x+dx[d],ty=y+dy[d];
		if(!mp[tx][ty])
			d=(d+1)%4;
		else{
			x=tx;y=ty;
			if(!vis[x][y]){
				vis[x][y]=1;
				cnt++;
			}
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	char c;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c;
				if(c=='.') mp[i][j]=1;
				else mp[i][j]=0;	
			}
		}
		vis[x][y]=1;
		solve();
		cout<<cnt<<endl;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				mp[i][j]=vis[i][j]=0;
		cnt=1;
	}
	return 0;
}

