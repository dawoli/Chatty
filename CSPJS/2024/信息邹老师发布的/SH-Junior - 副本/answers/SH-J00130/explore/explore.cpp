#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,now;
int x,y,d,ans;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int vis[1010][1010];
char a[1010][1010],p;

bool check(int x,int y){
	if(x<=0 || x>n)return 1;
	if(y<=0 || y>m)return 1;
	if(a[x][y]=='x')return 1;
	return 0;
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		now=0,ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		vis[x][y]=1;
		while(now<=k){
			if(check(x+dx[d],y+dy[d])){
				d++;d%=4;
				now++;
			}
			else{
				now++;
				x+=dx[d],y+=dy[d];
				if(now<=k)vis[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=vis[i][j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
