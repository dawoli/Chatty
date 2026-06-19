#include<iostream>
using namespace std;
void runn(){
	int n,m,k,xi,yi,x,y,d,f[1001][1001]={0},p[1001][1001]={0},count=1;
	char inp;
	cin>>n>>m>>k>>xi>>yi>>d;
	x=xi;
	y=yi;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>inp;
			if(inp=='.') f[i][j]==1;
		}
	}
	
	for(int i=0;i<k;i++){
		if(d==0){
			if(f[x][y+1]==1&&y+1<=m){
				y++;
			}
		}
		else if(d==1){
			if(f[x+1][y]==1&&x+1<=n){
				x++;
			}
		}
		else if(d==2){
			if(f[x][y-1]==1&&y-1>0){
				y--;
			}
		}
		else if(d==3){
			if(f[x-1][y]==1&&x-1>0){
				x--;
			}
		}
		else{
			d=(d+1)%4;
		}
		
		if(p[x][y]==0&&x<=n&&x>0&&y<=m&&y>0){
			count++;
			p[x][y]=1;
		}
	}
	cout<<count<<endl;
	return;
}

int main(){
	freopen("./explore.in","r",stdin);
	freopen("./explore.out","w",stdout);
	int tests;
	cin>>tests;
	for(int i=0;i<tests;i++) runn();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
