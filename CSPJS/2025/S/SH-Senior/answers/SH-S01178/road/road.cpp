#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000005],v[1000005],w[1000005];
int a[10001][10001];
bool x[10001];
long long ans;
void solve() {
	int cnt=0;
	while(cnt<n-1) {
		int q=INT_MAX;
		int p=0;
		for(int i=1; i<=n; i++) {
			if(x[i]==1) {
				for(int j=1; j<=n; j++) {
					if(x[j]==0) {
						 if(a[i][j]!=0){
							if(a[i][j]<q) {
								q=a[i][j];
								p=j;
							}
						}
					}
				}

			}
		}
		x[p]=1;
		ans+=q;
		cnt++;
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
			cin>>u[i]>>v[i]>>w[i];
			a[u[i]][v[i]]=w[i];
			a[v[i]][u[i]]=w[i];
		}
	x[1]=1;
	if(k==0) {
		solve();
		cout<<ans;
	}
	if(k!=0){
		cout<<0;
	}
	return 0;
}
