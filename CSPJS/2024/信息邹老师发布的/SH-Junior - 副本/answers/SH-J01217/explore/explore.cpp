#include <bits/stdc++.h>
//freopen("explore.in","r","stdin");
//freopen("explore.out","w","stdout");
using namespace std;
int main(){
	int T,xy[6],nm=0;
	char a[1001][1001];
	cin>>T;
	int n,m,k,x,y,d;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>k>>x>>y>>d;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				cin>>a[j][k];
			}
		}
		int cnt=1;
		a[x][y]='c';
		for(int j=1;j<=k;j++){
			if(d==0){
				if(y+1<=m&&a[x][y+1]=='.'){
					cnt++;
					a[x][y+1]='c';
					y++;
				}else if(y+1<=m&&a[x][y+1]=='c'){
					y++;
				}else{
					d=1;
				}
			}else if(d==1){
				if(x+1<=n&&a[x+1][y]=='.'){
					cnt++;
					a[x+1][y]='c';
					x++;
				}else if(x+1<=n&&a[x+1][y]=='c'){
					x++;
				}else{
					d=2;
				}
			}else if(d==2){
				if(y-1>=1&&a[x][y-1]=='.'){
					cnt++;
					a[x][y-1]='c';
					y--;
				}else if(y-1>=1&&a[x][y-1]=='c'){
					y--;
				}else{
					d=3;
				}
			}else if(d==3){
				if(x-1>=1&&a[x-1][y]=='.'){
					cnt++;
					a[x-1][y]='c';
					x--;
				}else if(x-1>=1&&a[x-1][y]=='c'){
					x--;
				}else{
					d=0;
				}
			}
		}
		xy[nm]=cnt;
		nm++;
	}
	for(int i=0;i<nm;i++){
		cout<<xy[i]<<endl;
	}
	return 0;
}
