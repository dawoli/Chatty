#include<bits/stdc++.h> 
using namespace std;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int ans[10];
int n,m,k,ste[1001][1001]={};
char maps[1001][1001]={};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	for(int q=0;q<t;q++){
		int n,m,k,x0,y0,d0;
		cin >> n >> m >> k>> x0 >> y0 >> d0;
		ste[x0][y0] = 1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)cin >> maps[i][j];
		}
		int x1 = x0,y1 = y0;
		for(int i=1;i<=k;i++){
			x1 = x0+dir[d0][0],y1 = y0+dir[d0][1];
			if(x1<=n&&y1<=m&&x1>0&&y1>0&&maps[x1][y1]=='.'){
				ste[x1][y1] = 1;
				x0 = x1;
				y0 = y1;
			}else{
				d0 = (d0+1)%4;
				x1 = x0;
				y1 = y0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(ste[i][j])ans[q]++;
			}
		}
	}
	for(int i=0;i<t;i++)cout <<ans[i] << endl;

	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
