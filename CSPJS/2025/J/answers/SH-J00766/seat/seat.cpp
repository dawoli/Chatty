#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],ri,I[11][11];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int fn=n*m,s=1;
	for(int i = 0; i<fn; i++) cin>>a[i];
	int r=a[0];
	sort(a,a+fn);
	for(int i = 0; i<fn; i++)
		if(a[i]==r) {
			ri=i+1;
			break;
		}
	ri=fn-ri+1;
	for(int i = 1; i<=n; i++) {
		if(i%2) {
			for(int j=1; j<=m; j++) {
				I[j][i]=s;
				s++;
			}
		} else for(int j=m; j>=1; j--) {
				I[j][i]=s;
				s++;
			}
	}
	for(int i = 1; i<=m; i++) {
		for(int j = 1; j<=n; j++) {
			if(ri==I[i][j]) cout<<j<<" "<<i;
		}
	}
	return 0;
}
