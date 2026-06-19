#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		sum+=w;
	}
	cout<<sum;
	return 0;
}
