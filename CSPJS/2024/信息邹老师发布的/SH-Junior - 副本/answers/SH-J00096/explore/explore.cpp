#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
//1 1 3 114514 1 1 3 ..x 3
	int T,n,m,k,x,y,d,x_,y_,count;
	cin>>T;
	for(int C=1; C<=T; C++) {
		cin>>n>>m>>k>>x>>y>>d;
		count=1;
		char a[n+2][m+2];
		memset(a,0,sizeof(a));
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin>>a[i][j];
			}
		}
		a[x][y]='#';
		for(int i=1; i<=k; i++) {
			x_=x;
			y_=y;
			switch(d) {
				case 0: {
					y_++;
					break;
				}
				case 1: {
					x_++;
					break;
				}
				case 2: {
					y_--;
					break;
				}
				case 3: {
					x_--;
					break;
				}
			}
			if(a[x_][y_]!='x'&&1<=x_&&x_<=n&&1<=y_&&y_<=m) {
				if(a[x_][y_]=='.'){
					count++;
				}
				a[x_][y_]='#';
				x=x_;
				y=y_;
			}else d=(d+1)%4;
		}
		cout<<count<<'\n';
	}
	return 0;
}
