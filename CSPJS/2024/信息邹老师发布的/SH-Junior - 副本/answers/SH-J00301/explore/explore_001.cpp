#include<iostream>
using namespace std;
int main(){
	fopen("explore.in","r");
	fopen("explore.out","w");
	int t,n,m,k,x,y,d;
	char a[1005][1005];
	int vis[1005][1005];
	int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k>>x>>y>>d;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				cin>>a[j][l];
				vis[j][l]=0;
			}
		}
		vis[x][y]=1;
		for(int j=1;j<=k;j++){
			int b=x+dis[d][0],c=y+dis[d][1];
			if(b>=1&&b<=n&&c>=1&&c<=m&&a[b][c]=='.'){
				vis[b][c]=1;
				x=b;y=c;
			}
			else{
				d=(d+1)%4;
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				if(vis[j][l]==1)ans+=1;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
