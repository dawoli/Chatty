#include<iostream>
using namespace std;
int n,m,k,x,y,d,t,ans=1;
char map[1100][1100]={};
bool vis[1100][1100]={};
int main(){
	freopen("explore1.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int q=0;q<t;q++){
		ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>map[i][j];
		for(int i=0;i<k;i++){
			if(d==0){
				if(y+1>=m){                                                    
					d=d+1%4;
				}else{
					if(vis[x][y+1]==0&&map[x][y+1]!='x'){
						ans++;
						vis[x][y+1]=1;
					}
				}
			}else if(d==1){
				if(x+1>=n){
					d=d+1%4;
				}else{
					if(vis[x+1][y]==0&&map[x+1][y]!='x'){
						ans++;
						vis[x+1][y]=1;
					}
				}
			}else if(d==2){
				if(y-1<=1){
					d=d+1%4;
				}else{
					if(vis[x][y-1]==0&&map[x][y-1]!='x'){
						ans++;
						vis[x][y-1]=1;
					}
				}
			}else if(d==3){
				if(x-1<=1){
					d=d+1%4;
				}else{
					if(vis[x-1][y]==0&&map[x-1][y]!='x'){
						ans++;
						vis[x-1][y]=1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
