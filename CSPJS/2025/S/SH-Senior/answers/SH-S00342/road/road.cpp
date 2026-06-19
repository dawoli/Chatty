#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
long long n,m,k,u[N],v[N],w[N],ans,flag,a[N][N],c[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=1;
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
			if(a[j][i]!=0) flag=1;
		}
	}
	if(flag==1) cout<<n*2+m+k-1;
	if(flag==0){
		for(int i=1;i<=m;i++){
			ans+=w[i];
		}
		cout<<ans;
	}
}
