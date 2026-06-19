#include<bits/stdc++.h>
using namespace std;
long long T;
long long n,m,k,x,y,d,cnt;
long long dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char c[1222][1222];
bool f[1024][1024];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		memset(f,0,sizeof(f));
		cnt=0;
		f[x][y]=1;
		for(long long i=1;i<=k;i++){
			long long tx=x+dx[d],ty=y+dy[d];
			if(tx<1||tx>n||ty<1||ty>m||c[tx][ty]=='x'){
				d=(d+1)%4; 
			}
			else{
				x=tx,y=ty;
				
			}
			f[x][y]=1;
		}
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=m;j++){
				if(f[i][j]){
					cnt++; 
				}
			}
		}
		cout<<cnt<<endl;
	} 
	
	return 0;
} 
