#include<bits/stdc++.h>
using namespace std;
char q[1010][1010];
bool vised[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,n,m,k,pos_x,pos_y,dir_s;
	int cnt;
	cin>>T;
	for(int i=0;i<T;i++){
		n=0;m=0;k=0;pos_x=0;pos_y=0;dir_s=0;cnt=0;
		for(int ti_a=0;ti_a<1010;ti_a++){
			for(int ti_b=0;ti_b<1010;ti_b++){
				vised[ti_a][ti_b]=0;
			}
		}
		cin>>n>>m>>k>>pos_x>>pos_y>>dir_s;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				cin>>q[j][k];
			}
		}
		cnt++;
		for(int d=0;d<k;d++){
			if(dir_s==0&&q[pos_x][pos_y+1]=='.'){
				vised[pos_x][pos_y]=1;
				pos_y++;
				if(vised[pos_x][pos_y]==0){
					cnt++;
				}
			}
			else if(dir_s==1&&q[pos_x+1][pos_y]=='.'){
				vised[pos_x][pos_y]=1;
				pos_x++;
				if(vised[pos_x][pos_y]==0){
					cnt++;
				}
			}
			else if(dir_s==2&&q[pos_x][pos_y-1]=='.'){
				vised[pos_x][pos_y]=1;
				pos_y--;
				if(vised[pos_x][pos_y]==0){
					cnt++;
				}
			}
			else if(dir_s==3&&q[pos_x-1][pos_y]=='.'){
				vised[pos_x][pos_y]=1;
				pos_x--;
				if(vised[pos_x][pos_y]==0){
					cnt++;
				}
			}
			else{
				dir_s=(dir_s+1)%4;
			}
		}
		if(i==0){
			cout<<cnt;
		}
		else{
			cout<<endl;
			cout<<cnt;
		}
	}
	return 0;
}
