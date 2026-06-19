#include <bits/stdc++.h>
using namespace std;
typedef long ll;
ll T;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		ll n,m,L,V,d[10009],v[10009],a[10009],cs[10009],q;
		double dsd;
		cin>>n>>m>>L>>V;
		for(int j=1;j<=n;j++){
			cin>>d[j]>>v[j]>>a[j];
		}
		for(int j=1;j<=m;j++){
			cin>>cs[j];
		}
		for(int x=1;x<=m;x++){
			q=d[x];
			for(int y=d[x];y<=L;y++){
				if(y==cs[x]){
					cout<<y-q<<" "<<cs[x]<<" "<<x<<endl;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
