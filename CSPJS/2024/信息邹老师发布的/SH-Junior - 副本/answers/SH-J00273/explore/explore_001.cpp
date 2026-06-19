#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
int q[5][5]={{0,1},{1,0},{0,-1},{-1,0}};
bool vis[1001][1001];
int ans=0;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int N;
	int n,m,k;
	cin>>N;
	int x,y;
	int xx,yy;
	int d;
	while(N--){
		string s;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=0;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=1;j<=m;j++){
            	a[i][j]=s[j-1];
			}
            
		}
		for(int i=0;i<=k;i++){
			if(a[x][y]=='.'&&vis[x][y]==0){
				ans++;
				vis[x][y]=1;
				
			}
			xx=x+q[d][0];
			yy=y+q[d][1];
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]=='.'){
				x=xx;
				y=yy;
			}else{
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
