#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,vl;
int ovl[23],clos[23];
int d[100004],v[100004],a[100004],p[100004];
int main(){
	//freopen("detect.in","r",stdin);
	//freopen("detect.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		cin>>n>>m>>l>>vl;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(v[i]>vl)ovl[l]++;
		}
		for(int i=1;i<=m;i++)cin>>p[i];
		
	}
	return 0;
}
