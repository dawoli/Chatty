#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,ans;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	for(int i=1;i<=T;i++){
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		bool df[n+1][m+1],p[n+1][m+1];
		char c[m+1];
		memset(df,0,sizeof(df));
		memset(p,0,sizeof(p));
		for(int j=1;j<=n;j++){
			cin >> c;
			for(int l=0;l<=m-1;l++){
				if(c[l]=='.') p[j][l+1]=1;
				else if(c[l]=='x') p[j][l+1]=0;
			} 
		}
		df[x][y]=1;
		for(int j=1;j<=k;j++){
			if(d==0) {
			    if(p[x][y+1]==1){y++;df[x][y]=1;}
			    else {d=(d+1)%4;}
			}else if(d==1){
				if(p[x+1][y]==1){x++;df[x][y]=1;}
			    else {d=(d+1)%4;}
			}else if(d==2){
				if(p[x][y-1]==1){y--;df[x][y]=1;}
			    else {d=(d+1)%4;}
			}else if(d==3){
				if(p[x-1][y]==1){x--;df[x][y]=1;}
			    else {d=(d+1)%4;}
			}
		}
		ans=0;
		for(int j=1;j<=n;j++)
			for(int l=1;l<=m;l++)
				if(df[j][l]==1) ans++;
		cout << ans << "\n";
	}
	return 0;
} 
