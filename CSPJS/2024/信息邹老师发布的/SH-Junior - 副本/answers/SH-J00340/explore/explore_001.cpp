#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k;
int x,y,d;
int point=1;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		char mapp[1001][1001];
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int a=1;a<=n;a++){
			for(int b=1;b<=m;b++){
				cin>>mapp[a][b];
			}
		}
		mapp[x][y]='a';
		for(int j=1;j<=k;j++){//robot
			if(d==0){ //direction 1
				if(mapp[x][y+1]=='.'){
					y++;
					point++;
					mapp[x][y]='a';
				}
				else if(mapp[x][y+1]=='a'){
					y++;
				}
				else{
					d=1;
				}
			}
			else if(d==1){ //direction 2
				if(mapp[x+1][y]=='.'){
					x++;
					point++;
					mapp[x][y]='a';
				}
				else if(mapp[x+1][y]=='a'){
					x++;
				}
				else{
					d=2;
				}
			}
			else if(d==2){ //direction 3
				if(mapp[x][y-1]=='.'){
					y--;
					point++;
					mapp[x][y]='a';
				}
				else if(mapp[x][y-1]=='a'){
					y--;
				}
				else{
					d=3;
				}
			}
			else{ //direction 4
				if(mapp[x-1][y]=='.'){
					x--;
					point++;
					mapp[x][y]='a';
				}
				else if(mapp[x-1][y]=='a'){
					x--;
				}
				else{
					d=0;
				}
			}	
		}
		cout<<point<<'\n';
		point=1; 
	}
	return 0;
}
