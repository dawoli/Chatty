#include<bits/stdc++.h>
using namespace std;

int t;
bool mapx[1000+5][1000+5][3];


int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char tmp;
				cin>>tmp;
				if(tmp=='.'){
					mapx[i][j][1]=1;
				}
				else{
					mapx[i][j][1]=0;
				}
			}
		} 

		int ans=0;
		for(int i=0;i<=k;i++) {
			if(mapx[x][y][2]==0){
				mapx[x][y][2]=1;
				ans++;
			}
			if(d==0){
				if(mapx[x][y+1][1]==1){
					y++;
					continue;
				}
				else{
					d=1;
				}
			}
			else if(d==1){
				if(mapx[x+1][y][1]==1){
					x++;
					continue;
				}
				else{
					d=2;
				}
			}
			else if(d==2){
				if(mapx[x][y-1][1]==1){
					y--;
					continue;
				}
				else{
					d=3;
				}
			}
			else if(d==3){
				if(mapx[x-1][y][1]==1){
					x--;
					continue;
				}
				else{
					d=0;
				}				
			}
			
		}
		cout<<ans<<endl;
		memset(mapx,0,sizeof(mapx));
	}
	return 0;
}
