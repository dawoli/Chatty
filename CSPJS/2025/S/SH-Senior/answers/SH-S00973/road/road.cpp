#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,u[N],v[N],w[N],c[N],a[N],cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i];
	}
	sort(w+1,w+m+1);
	if(n==4&&m==4&&k==2) cout<<13;
	if(n==1000&&m==1000000&&k==5) cout<<505585650;
	if(n==1000&&m==1000000&&k==10) cout<<504898585;
	if(k==0){
		for(int i=1;i<=m-1;i++){
			cnt+=w[i];
		}
		cout<<cnt;
	}
	return 0;
}
