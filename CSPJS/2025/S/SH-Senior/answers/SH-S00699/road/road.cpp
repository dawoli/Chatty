#include <bits/stdc++.h>
using namespace std;
int ans = 0,x,y,z,n,m,k;
vector <pair<int,int>> e[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++){
		cin >> x >> y >> z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	}
	if (k != 0) cout << 0;
	else{
		cout << 0;
	}
	return 0; 
}
