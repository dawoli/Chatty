#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k;
char a[1005][1005];
int b[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			} 
		}
		for(int i=1;i<=1005;i++){
			for(int j=1;j<=1005;j++){
				b[i][j]=0;
			} 
		}
		int ans=1;
		b[x][y]=1;
		for(int i=0;i<k;i++){
			if(d==0){
				int xx=x,yy=y+1;
				if(xx<1||yy<1||xx>n||yy>m||a[xx][yy]=='x'){
					d=(d+1)%4;
				}else{
					x=xx;
					y=yy;
					if(b[x][y]==1){
						continue;
					}else{
						ans++;
						b[x][y]=1;
					}
				}
			}else if(d==1){
				int xx=x+1,yy=y;
				if(xx<1||yy<1||xx>n||yy>m||a[xx][yy]=='x'){
					d=(d+1)%4;
				}else{
					x=xx;
					y=yy;
					if(b[x][y]==1){
						continue;
					}else{
						ans++;
						b[x][y]=1;
					}
				}
			}else if(d==2){
				int xx=x,yy=y-1;
				if(xx<1||yy<1||xx>n||yy>m||a[xx][yy]=='x'){
					d=(d+1)%4;
				}else{
					x=xx;
					y=yy;
					if(b[x][y]==1){
						continue;
					}else{
						ans++;
						b[x][y]=1;
					}
				}
			}else if(d==3){
				int xx=x-1,yy=y;
				if(xx<1||yy<1||xx>n||yy>m||a[xx][yy]=='x'){
					d=(d+1)%4;
				}else{
					x=xx;
					y=yy;
					if(b[x][y]==1){
						continue;
					}else{
						ans++;
						b[x][y]=1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
