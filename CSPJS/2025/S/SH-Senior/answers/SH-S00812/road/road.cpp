#include<bits/stdc++.h>
using namespace std;
const int N=1e4+35,M=1e6+38,K=19;
int n,m,k,u[M],v[M],w[M],c[K],a[K][N],all,good=M,minn;
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		all+=w[i];
	}
	int flag0=1,flagk=1;
	for(int j=1;j<=k;j++){
		cin>>c[j];
		minn=min(minn,c[j]);
		for(int i=1;i<=n;i++){
			flagk=1;
			cin>>a[j][i];
			if(a[j][i]>0)flag0=0,flagk=0;
		}
		if(flagk)good=min(good,min(all,c[j]));
	}
	if(flag0==0){
		cout<<min(minn,min(all,good));
		return 0;
	}
	cout<<min(all,good);
	return 0;
}
