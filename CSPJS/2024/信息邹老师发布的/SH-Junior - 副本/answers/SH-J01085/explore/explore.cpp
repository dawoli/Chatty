#include <bits/stdc++.h>
int t;
bool w[1005][1005]= {false};
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	std::cin>>t;
	for(int i=1; i<=t; i++) {
		int ans=0;
		int n,m,k,x,y,d;
		char a[1005][1005];
		std::cin>>n>>m>>k;
		std::cin>>x>>y>>d;
		for(int h=1; h<=n; h++) {
			for(int l=1; l<=m; l++) {
				std::cin>>a[h][l];
			}
		}
		w[x][y]=true;
		for(int j=1; j<=k; j++) {
			if(d==0) {
				if(y+1<=m&&a[x][y+1]=='.') {
					y++;
					if(w[x][y]==false) {
						w[x][y]=true;
					}
				} else {
					d=(d+1)%4;
				}
			} else if(d==1) {
				if(x+1<=n&&a[x+1][y]=='.') {
					x++;
					if(w[x][y]==false) {
						w[x][y]=true;
					}
				} else {
					d=(d+1)%4;
				}
			} else if(d==2) {
				if(y-1>0&&a[x][y-1]=='.') {
					y--;
					if(w[x][y]==false) {
						w[x][y]=true;
					}
				} else {
					d=(d+1)%4;
				}
			} else if(d==3) {
				if(x-1>0&&a[x-1][y]=='.') {
					x--;
					if(w[x][y]==false) {
						w[x][y]=true;
					}

				} else {
					d=(d+1)%4;
				}
			}
		}
		for(int h=1; h<=1000; h++) {
			for(int l=1; l<=1000; l++) {
				if(w[h][l]==true) {
					w[h][l]=false;
					ans++;
				}
			}
		}
		std::cout<<ans<<"\n";
	}
	return 0;
}
