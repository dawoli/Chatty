#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,cnt=1;
char tmp;
int M[1001][1001];
int MV[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int _=0;_<T;++_){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>tmp;
				if(tmp=='x'){
					M[i][j]=1;
				}else{
					M[i][j]=0;
				}
			}
		}
		--x;
		--y;
		cnt=1;
		M[x][y]=-1;
		for(int i=0;i<k;++i){
			int x1=x+MV[d][0];
			int y1=y+MV[d][1];
			if(0<=x1 && x1<n && 0<=y1 && y1<m && M[x1][y1]!=1){
				x=x1;
				y=y1;
				if(M[x][y]==0){
					M[x][y]=-1;
					cnt++;
				}
			}else{
				++d;
				d%=4;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
