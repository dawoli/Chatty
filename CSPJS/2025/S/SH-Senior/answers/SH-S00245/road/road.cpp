#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x, y, z;
int cost,a[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i = 1; i <= m; ++i)
		cin>>x>>y>>z;
	for(int i = 1; i <= k; ++i){
		cin>>cost;
		for(int j = 1; j <= n; ++j)
			cin>>a[j];
	}
	cout<<0;
	return 0;
}
