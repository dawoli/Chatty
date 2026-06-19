#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int t,n,m,k,x,y,d,cnt;
char dt[1009][1009]; //地图 
int rc[1009][1009]; //记录是否走过 
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int xn=1;xn<=n;xn++)	
			for(int yn=1;yn<=m;yn++){
				cin>>dt[xn][yn];
				rc[xn][yn]=0;
			}
		rc[x][y]=1,cnt=1;
		for(int j=0;j<k;j++){
			if(x+dx[d]<=n&&y+dy[d]<=m&&dt[x+dx[d]][y+dy[d]]=='.'){
				x+=dx[d],y+=dy[d];
				if(rc[x][y]==0) cnt++,rc[x][y]=1;
			}
			else d=(d+1)%4;
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
