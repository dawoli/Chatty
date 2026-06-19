#include<bits/stdc++.h>
using namespace std;
long long T,n,m,k,x,y,d,ans=1;
char e[1005][1005];
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++) {
		cin>>n>>m>>k>>x>>y>>d;
		for(int a=1;a<=m;a++) {
			for(int b=1;b<=n;b++) {
				cin>>e[a][b];
			}
		}
		for(int j=0;j<k;j++) {
			if(d==0) {
				if(e[x][y+1]!='x'&&y+1<=m&&y+1>=1) {y+=1; ans++; }
				else d=1;
				continue;
			}
			if(d==1) {
				if(e[x+1][y]!='x'&&x+1<=n&&x+1>=1) {x+=1; ans++;}
				else d=2;
				continue;
			}
			if(d==2) {
				if(e[x][y-1]!='x'&&y-1<=m&&y-1>=1) {y-=1; ans++;}
				else d=3;
				continue;
			}
			if(d==3) {
				if(e[x-1][y]!='x'&&x-1<=n&&x-1>=1) {x-=1; ans++;}
				else d=0;
				continue;
			}
		}
		cout<<ans<<endl;
		ans=1;
	}
	return 0;
}
