#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d,f[1005][1005],ans;
char a[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		ans=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=0;i<=k;i++){
			f[x][y]=1;
			long long xx,yy;
			if(d==0){
				xx=x;
				yy=y+1;
			}
			else if(d==1){
				xx=x+1;
				yy=y;
			}
			else if(d==2){
				xx=x;
				yy=y-1;
			}
			else if(d==3){
				xx=x-1;
				yy=y;
			}
			if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]=='x') d=(d+1)%4;
			else{
				x=xx;
				y=yy;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=f[i][j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
