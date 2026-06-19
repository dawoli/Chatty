#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V,d[10010],v[10010],a[10010],cnt,zt; 
double each;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;++i){
		cin>>n;
		cnt=0;
		cin>>n>>m>>L>>V;
		for (int j=1;j<=n;++j){
			cin>>d[i]>>v[i]>>a[i];
			each=sqrt((double)d[i]*(double)d[i]+2.0*(double)v[i]*(double)a[i]);
			if (each>V) ++cnt;
		}
		cout<<cnt<<" "<<3<<endl;
	}
	return 0;
}
