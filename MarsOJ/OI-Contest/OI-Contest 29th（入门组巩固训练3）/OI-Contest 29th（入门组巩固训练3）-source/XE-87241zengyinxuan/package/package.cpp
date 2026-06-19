#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("package.in","r",stdin);
	freopen("package.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int v[m],ans=0x3f3f3f;
	for(int i=0;i<m;i++){
		cin>>v[i];
		ans=min(ans,ceil(n/1.0/i)*v[i]);
	}
	int w[n];
	for(int i=0;i<n;i++){
		int x;
		cin>>x>>w[i];
	}
	cout<<ans;
	return 0;
}
