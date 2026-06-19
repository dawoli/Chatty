#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int t,n,m,k,x,y,d,ans;
char map[1005][1005];
int v[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(v,0,sizeof(v));
		cin>>n>>m>>k>>x>>y>>d;
		ans=0;
		v[x][y]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>map[i][j];
		for(int i=1;i<=k;i++){
			int newx,newy;
			if(d==0)
				newx=x,newy=y+1;
			if(d==1)
				newx=x+1,newy=y;
			if(d==2)
				newx=x,newy=y-1;
			if(d==3)
				newx=x-1,newy=y;
			if(newx>0&&newx<=n&&newy>0&&newy<=m&&map[newx][newy]=='.'){
				x=newx;
				y=newy;
				v[x][y]=1;
			}else{
				d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(v[i][j])
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}
