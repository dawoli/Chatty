#include<bits/stdc++.h>
using namespace std;
char cd[1010][1010];
int cd2[1010][1010];
int cd3[1010][1010];
int T;
int n,m,d,k;
int ans;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		
		int x,y;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=0;
		d+=1;
		cd2[x][y]=1;
		ans++;
		cd3[x][y]=d;
		for(int j=1;j<=n;j++)
			for(int l=1;l<=m;l++){
				cin>>cd[j][l];
			}
		for(int j=0;j<k;j++){
			if(d==1){
				if(y+1<=m and cd[x][y+1]=='.'){
					y++;
					if(cd3[x][y]==d){
						break;
					}
					if (cd2[x][y]==0){
						cd2[x][y]=1;
						ans++;
						cd3[x][y]=d;
					}
					
				}
				else{
					d=d%4+1;
				}
			}
			else if(d==2){
				if(x+1<=n and cd[x+1][y]=='.'){
					x++;
					if(cd3[x][y]==d){
						break;
					}
					if (cd2[x][y]==0){
						cd2[x][y]=1;
						ans++;
						cd3[x][y]=d;
					}
				}
				else{
					d=d%4+1;
				}
			}
			else if(d==3){
				if(y-1<=m and y-1>=1 and cd[x][y-1]=='.'){
					y--;
					if(cd3[x][y]==d){
						break;
					}
					if (cd2[x][y]==0){
						cd2[x][y]=1;
						ans++;
						cd3[x][y]=d;
					}
				}
				else{
					d=d%4+1;
				}
			}
			else if(d==4){
				if( x-1>=1 and cd[x-1][y]=='.'){
					x--;
					if(cd3[x][y]==d){
						break;
					}
					if (cd2[x][y]==0){
						cd2[x][y]=1;
						ans++;
						cd3[x][y]=d;
					}
				}
				else{
					d=d%4+1;
				}
			}
			
		}
		cout<<ans<<endl;
		for(int j=0;j<=n;j++){
			for(int l=0;l<=m;l++){
				cd2[j][l]=0;
				cd3[j][l]=0;
			}
		}
	}
	
	return 0;
}
