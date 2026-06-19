#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V;
int p[100010];
struct car {
	int d,v,a;
	double vp=0.00000000;
}c[100010];
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++) {
		int ans=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
			cin>>c[i].d>>c[i].v>>c[i].a;
		for(int i=1;i<=m;i++)
			cin>>p[i];
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++) {
			c[i].vp=sqrt(c[i].v*c[i].v
				+2*c[i].a*(p[m]-c[i].d));
			if(c[i].vp>V&&c[i].d<=p[m]) ans++;
		}
		if(ans) m--;
		cout<<ans<<' '<<m<<endl;
	}
	
	return 0;
}
