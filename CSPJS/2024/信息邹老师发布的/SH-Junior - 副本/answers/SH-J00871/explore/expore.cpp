#include<iostream>
#include <cstdio>
#include<fstream>
using namespace std;
const int N=1e3+5,K=1e6+5;
int T,m,n,k,x,y,d;
char ma[N][N];
bool inmap(int r,int c){
	return r>0&&c>0&&r<=n&&c<=m&&ma[r][c]!='x';
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);

	while(T--){
		
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ma[i][j];
			}
		}
		ma[x][y]='o';
		while(k--){
			const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
			
			if(!inmap(x+dir[d][0],y+dir[d][1])){
				d=(d+1)%4;
				//cout<<"r"<<endl;
			}
			else{
				
			x=x+dir[d][0];
			y=y+dir[d][1];
			ma[x][y]='o';
			//cout<<x<<" "<<y<<endl;
		    }
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				//cout<<ma[i][j];
				if (ma[i][j]=='o')sum++;
			}
			//cout<<endl;
		}
		cout<<sum<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0; 
}

