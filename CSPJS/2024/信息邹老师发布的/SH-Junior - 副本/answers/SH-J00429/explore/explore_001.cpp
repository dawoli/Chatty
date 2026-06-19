#include<bits/stdc++.h>
using namespace std;
struct robot{
	int x,y,d;
};
char M[1010][1010];
int n,m,k;
bool vis[1010][1010];
robot r;
void move(){
	int moveX[4]={0,1,0,-1};
	int moveY[4]={1,0,-1,0};
	int removex=r.x+moveX[r.d];
	int removey=r.y+moveY[r.d];
	if(removex>n||removex<=0||removey>m||removey<=0) r.d=(r.d+1)%4;
	else if(M[removex][removey]=='.'){
		r.x+=moveX[r.d];
		r.y+=moveY[r.d];
		vis[r.x][r.y]=true;
	}else r.d=(r.d+1)%4;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int ans=0;
		memset(vis,0,sizeof vis);
		cin>>n>>m>>k;
		cin>>r.x>>r.y>>r.d;
		vis[r.x][r.y]=true;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>M[i][j];
			
		for(int i=1;i<=k;i++) move();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(vis[i][j]==true) ans++;
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
