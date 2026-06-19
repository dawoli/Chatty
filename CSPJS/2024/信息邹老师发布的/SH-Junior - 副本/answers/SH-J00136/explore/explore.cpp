#include<bits/stdc++.h>
using namespace std;
int flag[1002][1002];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int jj=1;jj<=T;jj++){
		int n,m,k;
		cin>>n>>m>>k;
		int x0,y0,d0;
		cin>>x0>>y0>>d0;
		for(int i=0;i<1002;i++){
			for(int j=0;j<1002;j++){
				flag[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char tmp;
				cin>>tmp;
				if(tmp=='.'){
					flag[i][j]=1;
				}
			}
		}
		int x=x0;
		int y=y0;
		int d=d0;
		flag[x][y]=2;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(flag[x][y+1]!=0){
					y=y+1;
					flag[x][y]=2;
					continue;
				}
				else{
					d=(d+1)%4;
					continue;
				}
			}
			else if(d==1){
				if(flag[x+1][y]!=0){
					x=x+1;
					flag[x][y]=2;
					continue;
				}
				else{
					d=(d+1)%4;
					continue;
				}
			}
			else if(d==2){
				if(flag[x][y-1]!=0){
					y=y-1;
					flag[x][y]=2;
					continue;
				}
				else{
					d=(d+1)%4;
					continue;
				}
			}
			else{
				if(flag[x-1][y]!=0){
					x=x-1;
					flag[x][y]=2;
					continue;
				}
				else{
					d=(d+1)%4;
					continue;
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(flag[i][j]==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
