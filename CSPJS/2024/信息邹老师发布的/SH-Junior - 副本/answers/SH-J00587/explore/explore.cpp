#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans,v[1001][1001];
char a[1001][1001];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		memset(v,0,sizeof(v));
		ans=0;
		while(k--){
			if(!v[x][y])v[x][y]=1,ans++;
			int tx,ty;
			if(d==0)tx=x,ty=y+1;
			if(d==1)tx=x+1,ty=y;
			if(d==2)tx=x,ty=y-1;
			if(d==3)tx=x-1,ty=y;
			if(1<=tx&&tx<=n&&1<=ty&&ty<=m&&a[tx][ty]=='.')x=tx,y=ty;
			else d=(d+1)%4;
		}
		if(!v[x][y])v[x][y]=1,ans++;
		cout<<ans<<endl;
	}
	return 0;
}
