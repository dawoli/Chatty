#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k;
int x0,y0,d0,b[1003][1003];
string a[1003];
int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for (int i=1;i<=T;i++){
		memset(b,0,sizeof(b));
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		b[x0-1][y0-1]=1;
		for (int j=0;j<n;j++){
			cin>>a[j];
		}
		for (int j=1;j<=k;j++){
			int x1=x0+dx[d0],y1=y0+dy[d0];
			if (1<=x1 && x1<=n && 1<=y1 && y1<=m && a[x1-1][y1-1]=='.'){
				x0=x1;
				y0=y1;
				b[x0-1][y0-1]=1;
			}
			else{
				d0=d0+1;
				d0%=4;
			}
		}
		int ans=0;
		for(int j=0;j<n;j++){
			for (int k=0;k<m;k++){
				if (b[j][k]==1)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
