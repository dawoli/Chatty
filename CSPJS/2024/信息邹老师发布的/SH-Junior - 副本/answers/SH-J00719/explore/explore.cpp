#include<bits/stdc++.h>
using namespace std;
int t,cnt;
bool v[1005][1005];
char c[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cnt=0;
		for(int i=0;i<1005;i++)
		  for(int j=0;j<1005;j++)
		    v[i][j]=0;
		int n,m,k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
		    cin>>c[i][j];
		v[x][y]=1;
		for(int i=1;i<=k;i++){
			int tx=x+dx[d],ty=y+dy[d];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&c[tx][ty]=='.') x=tx,y=ty,v[x][y]=1;
			else d=(d+1)%4;
		}
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++){
		  	if(v[i][j]==1) cnt++;
		  }
		cout<<cnt<<endl;
	}

	return 0;
}
