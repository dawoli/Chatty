#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,a,b,d,cnt=1;
char c[1010][1010];
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--) {
		cnt=1;
		cin>>n>>m>>k>>a>>b>>d;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cin>>c[i][j];
			}
		}
		if(d==0) {
			if(c[n][m+1]=='.') {
				cnt++;
			}
		}
		if(d==1) {
			if(c[n+1][m]=='.') {
				cnt++;
			}
		}
		if(d==2) {
			if(c[n][m-1]=='.') {
				cnt++;
			}
		}
		if(d==3) {
			if(c[n-1][m]=='.') {
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
