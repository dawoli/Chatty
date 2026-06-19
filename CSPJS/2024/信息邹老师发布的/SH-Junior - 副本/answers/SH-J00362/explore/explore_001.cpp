#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt;
char s[1005][1005];
int vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		int xx,yy,dd;
		cin >> xx >> yy >> dd;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> s[i][j];
				vis[i][j]=0;
			}
		}
		vis[xx][yy]=1;
		cnt=1;
		while(k--){
			int xxl,yyl;
			if(dd==0){
				xxl=xx;
				yyl=yy+1;
			}
			if(dd==1){
				xxl=xx+1;
				yyl=yy;
			}
			if(dd==2){
				xxl=xx;
				yyl=yy-1;
			}
			if(dd==3){
				xxl=xx-1;
				yyl=yy;
			}
			if(xxl>=1&&xxl<=n&&yyl>=1&&yyl<=m&&s[xxl][yyl]=='.'){
				xx=xxl;
				yy=yyl;
				if(vis[xx][yy]!=1) cnt++;
				vis[xx][yy]=1;
			}
			else{
				dd=(dd+1)%4;
			}
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
