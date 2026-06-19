#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ok[1001][1001];
char mp[1001][1001];
int dx[4]={0,1, 0,-1};
int dy[4]={1,0,-1, 0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
	
	int n,m,k,x,y,d;
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		cin>>mp[i][j];
		ok[i][j]=0;
	}
	ok[x][y]=1;
	for(int step=1;step<=k;step++){
		int x1=x+dx[d],y1=y+dy[d],d1=d;
		if(1<=x1 && x1<=n && mp[x1][y1]=='.'
		     && 1<=y1 && y1<=m) x=x1,y=y1,d=d1;
		else d=(d+1)%4;
		ok[x][y]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		if(ok[i][j]) ans++;
	cout<<ans<<endl;
	
	}
	return 0;
}

