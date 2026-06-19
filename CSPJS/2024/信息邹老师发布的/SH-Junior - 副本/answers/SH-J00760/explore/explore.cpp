#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x0,y0,d0,b[6][1010][1010],dd[2][4]={{0,1,0,-1},{1,0,-1,0} },x,y,d,ans;
char a[6][1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		ans=0;
		cin>>n>>m>>k>>x0>>y0>>d0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[t][i][j];
			}
		}
		b[t][x0][y0]=1;
		x=x0,y=y0,d=d0;
		for(int i=1;i<=k;i++){
			if(a[t][x+dd[0][d]][y+dd[1][d]]=='.'){
				x+=dd[0][d],y+=dd[1][d];
				b[t][x][y]=1;
			}
			else{
				d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(b[t][i][j])ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
