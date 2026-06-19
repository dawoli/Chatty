#include<bits/stdc++.h>
using namespace std;
struct bot{
	int posx;
	int posy;
	int d;
} B;
int main(){
	//*
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	/**/
	bool map_ex[1005][1005];
	char map_lk[1005][1005];
	int T,n,m,k,ans[10];
	cin>>T;
	for(int mapcnt=1;mapcnt<=T;mapcnt++){
		ans[mapcnt]=0;
		cin>>n>>m>>k;
		cin>>B.posx>>B.posy>>B.d;
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=m+1;j++){
				if(i==0||j==0||i==n+1||j==m+1){
					map_lk[i][j]='B';
				}else{
					cin>>map_lk[i][j];
				}
				map_ex[i][j]=false;
			}
		}
		map_ex[B.posx][B.posy]=true;
		ans[mapcnt]++;
		for(int run=0;run<k;run++){
			if(B.d==0&&map_lk[B.posx][B.posy+1]=='.'){
				B.posy++;
			}else if(B.d==0&&map_lk[B.posx][B.posy+1]!='.'){
				B.d=(B.d+1)%4;
			}else if(B.d==1&&map_lk[B.posx+1][B.posy]=='.'){
				B.posx++;
			}else if(B.d==1&&map_lk[B.posx+1][B.posy]!='.'){
				B.d=(B.d+1)%4;
			}else if(B.d==2&&map_lk[B.posx][B.posy-1]=='.'){
				B.posy--;
			}else if(B.d==2&&map_lk[B.posx][B.posy-1]!='.'){
				B.d=(B.d+1)%4;
			}else if(B.d==3&&map_lk[B.posx-1][B.posy]=='.'){
				B.posx--;
			}else if(B.d==3&&map_lk[B.posx-1][B.posy]!='.'){
				B.d=(B.d+1)%4;
			}
			if(!map_ex[B.posx][B.posy]){
				map_ex[B.posx][B.posy]=true;
				ans[mapcnt]++;
			}
		}
	}
	for(int i=1;i<=T;i++){
		cout<<ans[i]<<endl;
	}
}
