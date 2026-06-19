#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t=0,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
	string tt;
	cin>>tt; 
	for(int i=tt.size()-1;i>=0;i--){
		t+=(int(tt[i])-48)*pow(10,i);
	}
	for(int tt=0;tt<t;tt++){
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,z,sum=1;
		cin>>x>>y>>z;
		char map[1010][1010];
		bool vis[1010][1010];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>map[i][j];
				vis[i][j]=0;
			}
		}
		vis[x][y]=1;
		for(int i=1;i<=k;i++){
			if(map[x+dx[z]][y+dy[z]]!='x' and x+dx[z]>=1 and x+dx[z]<=n and y+dy[z]>=1 and y+dy[z]<=m){
				if(vis[x+dx[z]][y+dy[z]]!=1){
				    sum++;
				    x+=dx[z];
				    y+=dy[z];
				    vis[x][y]=1;
				}else{
					x+=dx[z];
					y+=dy[z];
				}
			}else{
				z++;
				z%=4;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
