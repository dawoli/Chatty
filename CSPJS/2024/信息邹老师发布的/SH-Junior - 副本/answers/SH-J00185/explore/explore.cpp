#include<bits/stdc++.h>
using namespace std;
int awa[1009][1009];
long long D,X,Y,k,ans,n,m,T;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char c;
void work(){
	ans=0;
	cin>>n>>m>>k;
	cin>>X>>Y>>D;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c;
			if(c=='x') awa[i][j]=1;
			else awa[i][j]=0;
		}
	}
	awa[X][Y]=2;
	while(k--){
		int nx=X+dx[D],ny=Y+dy[D]; 
		if(awa[nx][ny]==1||nx>n||nx<=0||ny>m||ny<=0){D=(D+1)%4;continue;}
		awa[nx][ny]=2;

		Y=ny,X=nx;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(awa[i][j]==2) ans++;
	
	cout<<ans<<'\n';
	return ;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--) work();
	return 0; 
}
