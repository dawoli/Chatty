#include<bits/stdc++.h>
//d: 0ср 1об 2вС 3ио 
using namespace std;
char pam[1005][1005];
bool vis[1005][1005];
int n,m,k,x,y,d,nx,ny,ans;
string s;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0; 
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=1;j<=m;j++){
				pam[i][j]=s[j-1];
			}
		}
		vis[x][y]=1;
		ans++;
		for(int i=1;i<=k;i++){
			if(d==0){
				nx=x;
				ny=y+1;
			}
			else if(d==1){
				nx=x+1;
				ny=y;
			}
			else if(d==2){
				nx=x;
				ny=y-1;
			}
			else if(d==3){
				nx=x-1;
				ny=y;
			}
			if(nx>0&&ny>0&&nx<=n&&ny<=m&&pam[nx][ny]!='x'){
				x=nx;
				y=ny;
				if(!vis[x][y])
					ans++;
				vis[x][y]=1;
			}
			else
				d=(d+1)%4;	
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
