#include<bits/stdc++.h>
using namespace std;
struct robot_t{
	int x,y,d;
}rob;
char Map[1010][1010];
int tur[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,n,m,k;
	cin>>T;
	for(int x=1;x<=T;x++){
		int cnt=0;
		for(int i=1;i<=1001;i++){
			for(int j=1;j<=1001;j++){
				tur[i][j]=0;
			}
		}
		cin>>n>>m>>k;
		cin>>rob.x>>rob.y>>rob.d;
		tur[rob.x][rob.y]++;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>Map[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(rob.d==0){
				if(rob.y+1<=m && Map[rob.x][rob.y+1]=='.'){
					rob.y++;
					tur[rob.x][rob.y]++;
				}else{
					rob.d=(rob.d+1)%4;
				}
			}else if(rob.d==1){
				if(rob.x+1<=n && Map[rob.x+1][rob.y]=='.'){
					rob.x++;
					tur[rob.x][rob.y]++;
				}else{
					rob.d=(rob.d+1)%4;
				}
			}else if(rob.d==2){
				if(rob.y-1>=1 && Map[rob.x][rob.y-1]=='.'){
					rob.y--;
					tur[rob.x][rob.y]++;
				}else{
					rob.d=(rob.d+1)%4;
				}
			}else{
				if(rob.x-1>=1 && Map[rob.x-1][rob.y]=='.'){
					rob.x--;
					tur[rob.x][rob.y]++;
				}else{
					rob.d=(rob.d+1)%4;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(tur[i][j])cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
