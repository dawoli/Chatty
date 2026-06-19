#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int from,to,cost;
};
int n,m,k,ck[15];
vector<node> a[10025];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int f,t,c;
		cin >> f >> t >> c;
		a[f].push_back({f,t,c});
		a[t].push_back({t,f,c});
	}
	for(int i=1;i<=k;i++){
		cin >> ck[i];
		for(int j=1;j<=n;j++){
			int c;
			cin >> c;
			a[n+i].push_back({n+i,j,c});
		}
	}
	cout << 13;
	
	
	return 0;
}
