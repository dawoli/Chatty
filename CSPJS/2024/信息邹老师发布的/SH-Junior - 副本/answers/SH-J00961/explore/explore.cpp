#include<bits/stdc++.h>
using namespace std;
char s[1001][1001];
bool vis[1001][1001];
int sum=0,N,n,m,k,x,y,d,xe,ye;
int main(){
	ifstream fin("explore.in");
	ofstream fout("explore.out");
	fin>>N;
	while(N--){
		fin>>n>>m>>k;
		fin>>x>>y>>d;
		vis[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				fin>>s[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(d==0){
				xe=x,ye=y+1;
			}
			if(d==1){
				xe=x+1,ye=y;
			}
			if(d==2){
				xe=x,ye=y-1;
			}
			if(d==3){
				xe=x-1,ye=y;
			}
			if(xe>=1&&xe<=n&&ye>=1&&ye<=m&&s[xe][ye]=='.'){
				
				x=xe;
				y=ye;
			}else{
				d=(d+1)%4;
			}
			vis[x][y]=1;
			/*fout<<x<<" "<<y<<" "<<d<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					fout<<vis[i][j]<<" ";
				}
				fout<<endl;
			}*/
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==1){
					sum++;
				}
			}
		}
		fout<<sum<<endl;
		sum=0;
		memset(vis,0,sizeof(vis));
	}
	fin.close();
	fout.close();
	return 0;
}
