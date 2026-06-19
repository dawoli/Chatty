#include<iostream>
#include<cmath> 
using namespace std;
int main(){
	freopen("explore.in","r",fin);
	freopen("explore.out","w",fout);
	int e,t,n,m,d,x,y,sum=1;
	char cl[1010][1010]={};
	cin>>e;
	for(int i=1;i<=e;i++){
		cin>>n>>m>>t>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>cl[i][j];
			}
		}
		sum=1;
		for(int j=1;j<t;j++){
			if(d==0){
				if(cl[x][y+1]!='x'&&x<=n&&y+1<=m){
					y++;
				    if(cl[x][y]=='.'){
				    	sum++;
				    	cl[x][y]=',';
					}
				}else{
					d=(d+1)%4;
				}
			}
			if(d==1){
				if(cl[x+1][y]!='x'&&x+1<=n&&y<=m){
					x++;
				    if(cl[x][y]=='.'){
				    	sum++;
				    	cl[x][y]=',';
					}
				}else{
					d=(d+1)%4;
				}
			}
			if(d==2){
				if(cl[x][y-1]!='x'&&x>=1&&y-1>=1){
					y--;
				    if(cl[x][y]=='.'){
				    	sum++;
				    	cl[x][y]=',';
					}
				}else{
					d=(d+1)%4;
				}
			}
			if(d==3){
				if(cl[x-1][y]!='x'&&x-1>=1&&y>=1){
					x--;
				    if(cl[x][y]=='.'){
				    	sum++;
				    	cl[x][y]=',';
					}
				}else{
					d=(d+1)%4;
				}
			}
		}
		cout<<sum<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cl[i][j]=0; 
			}
		}
	}
	return 0;
} 

