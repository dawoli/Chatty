#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int l=1;l<=T;l++){
		int n,m,k,p,q,d,x[4]={0,1,0,-1},y[4]={1,0,-1,0},ans=0;
		char c[1009][1009];
		cin>>n>>m>>k>>p>>q>>d;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>c[i][j];
		c[p][q]='1';
		for(int i=1;i<=k;i++){
			int a=p+x[d%4],b=q+y[d%4];
			if((c[a][b]=='.'||c[a][b]=='1')&&a>0&&a<=n&&b>0&&b<=m) p=a,q=b,c[a][b]='1';
			else d++;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(c[i][j]=='1') ans++;
		cout<<ans;
		if(l!=T) cout<<endl;
	}
	return 0;
}
