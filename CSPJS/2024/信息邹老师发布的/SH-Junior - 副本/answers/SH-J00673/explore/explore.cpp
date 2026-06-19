#include<bits/stdc++.h>
using namespace std;
bool flag[1005][1005],mapp[1005][1005];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(flag,false,sizeof(flag));
		int n,m,k;
		cin>>n>>m>>k;
		int sx,sy,d;
		cin>>sx>>sy>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char b;
				cin>>b;
				if(b=='.') mapp[i][j]=false;
				else mapp[i][j]=true;
			}
		}
		flag[sx][sy]=true;
		int nx=sx,ny=sy;
		int cnt=1;
		for(int i=1;i<=k;i++){
			int tx,ty;
			tx=nx+dir[d][0];
			ty=ny+dir[d][1];
			if(((tx<=0||ty<=0)||(tx>n||ty>m))||mapp[tx][ty]) d=(d+1)%4;
			else{
				nx=tx;
				ny=ty;
				if(flag[nx][ny]==false){
					flag[nx][ny]=true;
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
 } 
