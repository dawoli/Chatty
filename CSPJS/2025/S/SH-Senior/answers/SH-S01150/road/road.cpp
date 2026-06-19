#include<bits/stdc++.h>
using namespace std;
long long w[1000005],sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v;
		cin>>u>>v>>w[i];
	}
    for(long long i=1;i<=k;i++){
		for(long long j=1;j<=n+1;j++){
			long long a;
			cin>>a;
		}
	}
	sort(w+1,w+m+1);
	for(long long i=1;i<n;i++){
		sum+=w[i];
	}
	cout<<sum;
	return 0;
}
