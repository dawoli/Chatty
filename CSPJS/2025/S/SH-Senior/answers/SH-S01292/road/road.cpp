#include<bits/stdc++.h>
using namespace std;
long long a[5050][5050];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		long long a , b , c;
		cin >> a >> b >> c;
	}
	for(int i = 1; i <= k; i++){
		int g;
		cin >> g;
		for(int j = 1; j <= n; i++){
			cin >> a[i][j];
		}
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		long long minj=INT_MAX;
		for(int j = 1; j <= k; j++){
			minj = min(minj,a[i][j]);
		}
		ans += minj;
	}
	cout << ans;
	return 0;
} 
