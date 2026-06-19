#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,mp[1001][1001],ans;
bool vis[1001][1001];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) mp[i][j]=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vis[i][j]=0; 
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			string s="";
			cin>>s;
			for(int j=1;j<=m;j++){
				if(s[j-1]=='x') mp[i][j]=1;
				else if(s[j-1]=='.') mp[i][j]=0;
			}
		}vis[x][y]=1;
		while(k--){
			if(d==0){
				if(1<=y+1&&y+1<=m&&(!mp[x][y+1])) y+=1;
				else d=(d+1)%4;
			}else if(d==1){
				if(1<=x+1&&x+1<=n&&(!mp[x+1][y])) x+=1;
				else d=(d+1)%4;
			}else if(d==2){
				if(1<=y-1&&y-1<=m&&(!mp[x][y-1])) y-=1;
				else d=(d+1)%4;
			}else if(d==3){
				if(1<=x-1&&x-1<=n&&(!mp[x-1][y])) x-=1;
				else d=(d+1)%4;
			}vis[x][y]=1;
		}for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(vis[i][j]) ans++;
		cout<<ans<<endl;
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
