#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T-->0){
		int n,m,k,x,y,d,ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		char a[1010][1010];
		bool vis[1010][1010];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				vis[i][j]=0;
			}
		}
		for(int i=1;i<=k;i++){
			if(d==0){
				if(a[x][y+1]=='.'&&x>=1&&x<=n&&y+1>=1&&y+1<=m){
					y++;
					if(!vis[x][y]) ans++;
					vis[x][y]=1;
					//cout<<d<<" "<<x<<" "<<y<<"  ";
				} 
				else{
					d=(d+1)%4;
				}
			}
			else if(d==1){
				if(a[x+1][y]=='.'&&x+1>=1&&x+1<=n&&y>=1&&y<=m){
					x++;
					if(!vis[x][y]) ans++;
					vis[x][y]=1;
					//cout<<d<<" "<<x<<" "<<y<<"  ";	
				} 
				else{
					d=(d+1)%4;
				}
			}
			else if(d==2){
				if(a[x][y-1]=='.'&&x>=1&&x<=n&&y-1>=1&&y-1<=m){
					y--;
					if(!vis[x][y]) ans++;
					vis[x][y]=1;
					//cout<<d<<" "<<x<<" "<<y<<"  ";
				} 
				else{
					d=(d+1)%4;
				}
			}
			else if(d==3){
				if(a[x-1][y]=='.'&&x-1>=1&&x-1<=n&&y>=1&&y<=m){
					x--;
					if(!vis[x][y]) ans++;
					vis[x][y]=1;
					//cout<<d<<" "<<x<<" "<<y<<"  ";
				} 
				else{
					d=(d+1)%4;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
} 
