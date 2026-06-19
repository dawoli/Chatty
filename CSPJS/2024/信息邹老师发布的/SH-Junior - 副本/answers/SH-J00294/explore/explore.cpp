#include<bits/stdc++.h>
using namespace std;
long long T,n,m,k,x,y,d;
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(long long l=1;l<=T;l++){
		char a[1001][1001];
		bool vst[1001][1001];
		for(int i=1;i<=1000;i++){
			for(int j=1;j<=1000;j++){
				vst[i][j]=false;
			}
		} 
		long long ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		vst[x][y]=true;
		for(int i=1;i<=k;i++){
			if(x+xx[d]>=1&&x+xx[d]<=n&&y+yy[d]>=1&&y+yy[d]<=m&&a[x+xx[d]][y+yy[d]]=='.'){
				x=x+xx[d];
				y=y+yy[d];
				if(!vst[x][y]){
					ans++;
					vst[x][y]=true;
				}
			}
			else{
				d=(d+1)%4;
			}
		}		
		cout <<ans<<endl;
	}
	
	return 0;
}
