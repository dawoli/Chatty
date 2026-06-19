#include<bits/stdc++.h>
using namespace std;
map<int,char>mp[1001];
bool vis[1001][1001];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++){
			for(int z=1;z<=m;z++){
				char c;
				cin>>c;
				mp[j][z]=c;
				vis[j][z]=0;
			}
		}
		vis[x][y]=1;
		int ans=1;
		for(int j=1;j<=k;j++){
			if(d==0){
				if(y+1>0&&(y+1<m||y+1==m)&&mp[x][y+1]=='.'){
					y+=1;
					if(vis[x][y]==0){
						vis[x][y]=1;
						ans++;
					}
				}
				else d=(d+1)%4;
				
			}
			else if(d==1){
				if(x+1>0&&(x+1<n||x+1==n)&&mp[x+1][y]=='.'){
					x+=1;
					if(vis[x][y]==0){
						vis[x][y]=1;
						ans++;
					}
				}
				else d=(d+1)%4;
			}
			else if(d==2){
				if(y-1>0&&(y-1<m||y-1==m)&&mp[x][y-1]=='.'){
					y-=1;
					if(vis[x][y]==0){
						vis[x][y]=1;
						ans++;
					}
				}
				else d=(d+1)%4;
			}
			else if(d==3){
				if(x-1>0&&(x-1<n||x-1==n)&&mp[x-1][y]=='.'){
					x-=1;
					if(vis[x][y]==0){
						vis[x][y]=1;
						ans++;
					}
				}
				else d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
		
	}
}
