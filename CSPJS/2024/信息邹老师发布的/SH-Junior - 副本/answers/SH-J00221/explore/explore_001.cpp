#include<bits/stdc++.h>
using namespace std;
long long x,y,d,T,n,m,k,f[5][3],ans;
char c[1010][1010];
bool vis[1010][1010];
string s[1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout); 
	for(int i=0;i<=3;i++){
		for(int j=1;j<=2;j++){
			f[i][j]=0;
		}
	}
	f[0][2]=1;
	f[1][1]=1;
	f[2][2]=-1;
	f[3][1]=-1;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			cin>>s[i];
			for(int j=1;j<=m;j++){
				c[i][j]=s[i][j-1];
			}
		}
		for(;k>0;k--){
			if(x+f[d][1]>=1&&x+f[d][1]<=n&&y+f[d][2]>=1&&y+f[d][2]<=m&&c[x+f[d][1]][y+f[d][2]]=='.'){
				x+=f[d][1];
				y+=f[d][2];
				vis[x][y]=1;
			}
			else{
				d++;
				d%=4;
				vis[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1){
					ans++;
					vis[i][j]=0;
				}
			}
		}
		cout<<ans<<endl;
	}
} 
