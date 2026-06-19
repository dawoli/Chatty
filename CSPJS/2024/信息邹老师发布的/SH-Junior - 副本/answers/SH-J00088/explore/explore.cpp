#include<bits/stdc++.h>
using namespace std;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,k,t,x,y,d,ans;
char c[1010][1010];
bool vis[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;++l){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		vis[x][y]=1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>c[i][j];
			}
		}
		for(int i=1;i<k;){
			while(x+dx[d]>n||x+dx[d]<=0||y+dy[d]>m||y+dy[d]<=0){
				d=(d+1)%4;
				++i;
			}
			x+=dx[d];
			y+=dy[d];
			vis[x][y]=1;
			++i;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(vis[i][j]==1){
					++ans;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
