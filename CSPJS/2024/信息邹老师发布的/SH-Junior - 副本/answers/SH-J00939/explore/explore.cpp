#include<bits/stdc++.h>
using namespace std;
char c[1005][1005];
bool b[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int w=0;w<t;w++){
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
				if(c[i][j]=='.') sum++;
				b[i][j]=0;
			}
		}
		
		int ans=1;
		b[x][y]=1;
		for(int i=0;i<k;i++){
			int x1=0,y1=0;
			if(d==0){
				x1=x;y1=y+1;
				if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&c[x1][y1]=='.'){
					x=x1;y=y1;
					if(b[x][y]==0){
						ans++;
					}
					b[x][y]=1;
					continue;
				}else{
					d=(d+1)%4;
					continue;
				}
			}
			if(d==1){
				x1=x+1;y1=y;
				if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&c[x1][y1]=='.'){
					x=x1;y=y1;
					if(b[x][y]==0){
						ans++;
					}
					b[x][y]=1;
					continue;
				}else{
					d=(d+1)%4;
					continue;
				}
			}
			if(d==2){
				x1=x;y1=y-1;
				if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&c[x1][y1]=='.'){
					x=x1;y=y1;
					if(b[x][y]==0){
						ans++;
					}
					b[x][y]=1;
					continue;
				}else{
					d=(d+1)%4;
					continue;
				}
			}
			if(d==3){
				x1=x-1;y1=y;
				if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&c[x1][y1]=='.'){
					x=x1;y=y1;
					if(b[x][y]==0){
						ans++;
					}
					b[x][y]=1;
					continue;
				}else{
					d=(d+1)%4;
					continue;
				}
			}
			if(ans>=sum) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
