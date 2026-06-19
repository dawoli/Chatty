#include<bits/stdc++.h>
using namespace std;
int T, n, m, k, X, Y, D, cnt=1, x, y, d;
char ma[1005][1005], foot[1005][1005];      
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin>>T;
	for(int A=0;A<T;A++){
		cnt=1;
		cin>>n>>m>>k;
	    cin>>X>>Y>>D;
	    x=X;   
	    y=Y;  
	    d=D;    
	    for(int i=1;i<=n;i++){
	    	for(int j=1;j<=m;j++){
	    		cin>>ma[i][j];
			}
		}
		for(int i=0;i<k;i++){
			if(d==0){
				if(x>=1&&x<=n&&y+1>=1&&y+1<=m&&ma[x][y+1]=='.'){
					y=y+1;
					foot[x][y]=1;
				}else{
					d=(d+1)%4;
				}
			}else if(d==1){
				if(x+1>=1&&x+1<=n&&y>=1&&y<=m&&ma[x+1][y]=='.'){
					x=x+1;
					foot[x][y]=1;
				}else{
					d=(d+1)%4;
				}
			}else if(d==2){
				if(x>=1&&x<=n&&y-1>=1&&y-1<=m&&ma[x][y-1]=='.'){
					y=y-1;
					foot[x][y]=1;
				}else{
					d=(d+1)%4;
				}
			}else if(d==3){
				if(x-1>=1&&x-1<=n&&y>=1&&y<=m&&ma[x-1][y]=='.'){
					x=x-1;
					foot[x][y]=1;
				}else{
					d=(d+1)%4;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(foot[i][j]==1){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n"; 
	}
	return 0;
}
