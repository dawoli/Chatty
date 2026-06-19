#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
char mp[1005][1005];
bool vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T; 
	while(T--){
		int ans=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=m;j++){
			    cin>>mp[i][j];
			    vis[i][j]=0;
			}
		vis[x][y]=1;
	    for(int i=1;i<=k;i++){
	    	if(d==0){
	    		if(x>=1&&x<=n&&y+1>=1&&y+1<=m&&mp[x][y+1]=='.')y++,vis[x][y]=1;
	    		else d=(d+1)%4;
			}
			else if(d==1){
				if(x+1>=1&&x+1<=n&&y>=1&&y<=m&&mp[x+1][y]=='.')x++,vis[x][y]=1;
	    		else d=(d+1)%4;
			}
			else if(d==2){
				if(x>=1&&x<=n&&y-1>=1&&y-1<=m&&mp[x][y-1]=='.')y--,vis[x][y]=1;
	    		else d=(d+1)%4;
			}
			else if(d==3){
				if(x-1>=1&&x-1<=n&&y>=1&&y<=m&&mp[x-1][y]=='.')x--,vis[x][y]=1;
	    		else d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=m;j++)
		        if(vis[i][j]==1)ans++;
		cout<<ans<<endl;
	}
	return 0; 
} 
