#include<bits/stdc++.h>
using namespace std;
char a[1010][1010]={};
bool vis[1010][1010]={};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,n,m,k,x,y,d,c=0;
	cin>>T;
	while(T--){
		c=1;
		cin>>n>>m>>k>>x>>y>>d;
		x--,y--;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++){
			cin>>a[i][j];
			vis[i][j]=0;	
		}vis[x][y]=1;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(y+1==m||a[x][y+1]=='x'){
					d=(d+1)%4;continue;
				}else{
					y++;
					//printf("%d,x=%d,y=%d\n",i,x,y);
					if(vis[x][y]==0)c++;
					vis[x][y]=1;
				}
			}else if(d==1){
				if(x+1==n||a[x+1][y]=='x'){
					d=(d+1)%4;continue;
				}else{
					x++;
					//printf("%d,x=%d,y=%d\n",i,x,y);
					if(vis[x][y]==0)c++;
					vis[x][y]=1;
				}
			}else if(d==2){
				if(y==0||a[x][y-1]=='x'){
					d=(d+1)%4;continue;
				}else{
					y--;
					//printf("%d,x=%d,y=%d\n",i,x,y);
					if(vis[x][y]==0)c++;
					vis[x][y]=1;
				}
			}else if(d==3){
				if(x==0||a[x-1][y]=='x'){
					d=(d+1)%4;continue;
				}else{
					x--;
					//printf("%d,x=%d,y=%d\n",i,x,y);
					if(vis[x][y]==0)c++;
					vis[x][y]=1;
				}
			}
		}cout<<c<<"\n";
	}
	return 0;	
}
