#include<bits/stdc++.h>
using namespace std;
int abc,ans=0;
int n,m,k;
int x,y,d;
char mp[1005][1005];
bool visited[1005][1005];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
void func(int x,int y,int step){
	if(visited[x][y]==0){
		ans++;
		visited[x][y]=1;
	}
	if(step==k) return ;
	if(mp[x+xx[d]][y+yy[d]]=='x') d=(d+1)%4;
	else{
		x+=xx[d];
		y+=yy[d];
		
	}
	
	func(x,y,step+1);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>abc;
	while(abc--){
		memset(mp,'x',sizeof(mp));
		memset(visited,0,sizeof(visited));
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
				
			}
		}
		func(x,y,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
