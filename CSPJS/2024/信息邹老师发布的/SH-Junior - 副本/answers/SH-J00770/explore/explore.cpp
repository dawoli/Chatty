#include<iostream>
using namespace std;
int n,m,k,ans=0;
int x1,y1,d1;
int map[1000][1000];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
void dfs(int st,int x,int y){
	if(k==0){
		return ;
	}
	for(int i=0;i<4;i++){
		if(st==i){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx>n||nx<1||ny>m||ny<1&&map[nx][ny]=='x'){
				st=(st+1)%4;
				k--;
			}else{
				ans++;
				k--;
				dfs(st,nx,ny);
			}
			
		}
	}
	
	
}
int main(){
	freopen("","r",stdin);
	freopen("","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k;
		cin>>x1>>y1>>d1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>map[i][j];
			}
		}
		dfs(d1,x1,y1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
