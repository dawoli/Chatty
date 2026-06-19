#include<bits/stdc++.h>
using namespace std;
#define N 1005//ÉèÖÃ´óÐ¡

int n,m,k,x,y,d,mp[N][N];
bool vis[N][N];
int dir[4][2]={0,1,1,0,0,-1,-1,0};

void move(){
	int x0=x+dir[d][0],y0=y+dir[d][1];
	if(x0>=1&&x0<=n&&y0>=1&&y0<=m&&mp[x0][y0]==0){
		x=x0,y=y0;
	}
	else d=(d+1)%4;
	vis[x][y]=1;
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--){
		int ct=0;
		memset(vis,0,sizeof(vis));
		memset(mp,0,sizeof(mp));
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
			char c;
			cin>>c;
			if(c=='x') mp[i][j]=1;
			else mp[i][j]=0;
		}
		for(int i=1;i<=k;++i){
			vis[x][y]=1;
			//cout<<"#"<<i<<' '<<x<<' '<<y<<' '<<d<<endl;
			move();
		}
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(vis[i][j]) ct++;
		cout<<ct<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


