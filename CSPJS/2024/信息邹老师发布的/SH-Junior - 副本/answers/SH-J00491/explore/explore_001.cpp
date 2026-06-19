#include<bits/stdc++.h>
using namespace std;
int t,m,n,k,x,y,d,xx,yy;
int zz(){
	d++;
	if (d==4) d=0;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	int jg[10];
	for (int e;e<t;e++){
		jg[e]=0;
		cin>>n>>m>>k>>x>>y>>d;
		char dt[n+5][m+5];
		xx=x;
		yy=y;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++){
				dt[i][j]='x';
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>dt[i][j];
			}
		dt[y][x]='j';
		while(k!=0){
			if (d==0 && dt[yy][xx+1]=='.' ){
				xx++;
				dt[yy][xx]='j';
				k--;
				continue;
			}
			if (d==1 && dt[yy-1][xx]=='.' ){
				y--;
				dt[yy][xx]='j';
				k--;
				continue;
			}
			if (d==2 && dt[yy][xx-1]=='.' ){
				xx--;
				dt[yy][xx]='j';
				k--;
				continue;
			}
			if (d==3 && dt[yy+1][xx]=='.' ){
				yy++;
				dt[yy][xx]='j';
				k--;
				continue;
			}
			zz();
			k--;
		}
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=m+1;j++){
				if (dt[i][j]=='j'){
					jg[e]++;
				}
			}
		}
		cout<<jg[e]<<endl;
	}

	return 0;
}









