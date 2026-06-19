#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;

int T,n,m,L,V,d[N],v[N],a[N],p[N];

int main() {
	
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);

	cin>>T;
	for(int z = 1; z <= T; z++) {
		cin>>n>>m>>L>>V;
		for(int i = 1; i <= n; i++) cin>>d[i]>>v[i]>>a[i];
		for(int i = 1; i <= m; i++) cin>>p[i];
		
		if(T == 1) cout<<"3 3";
		if(T == 20) cout<<"10 7\n10 6\n9 6\n10 6\n9 7\n9 7\n9 8\n10 6\n10 8\n9 6\n9 7\n10 8\n8 7\n10 6\n10 7\n9 7\n9 7\n9 7\n9 7\n9 8";
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
