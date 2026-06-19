#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k,x,y,d,v[1005][1005],p[1005][1005],dx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		int ans=1;
		char c;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> c;
				if(c=='x') p[i][j]=1;
				else p[i][j]=0; 
				v[i][j]=0;
			}
		}
		v[x][y]=1;
		for(int i=0;i<k;i++){
			int xx=x+dx[d][0];
			int yy=y+dx[d][1];
			if(xx<1||xx>n||yy<1||yy>m||p[xx][yy]==1){
				d=(d+1)%4;
				continue;
			}else{
				if(v[xx][yy]==0){
					ans++;
					v[xx][yy]=1;
				}
				x=xx;
				y=yy;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
