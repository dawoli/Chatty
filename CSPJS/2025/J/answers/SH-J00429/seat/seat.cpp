#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n, m;
int a[1010];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; ++i){
		cin >> a[i];
	}
	int res = a[1];
	sort(a+1, a+n*m+1, greater<int>());
	int k = 0;
	int x = 1, y = 1;
	for(int i=1; i<=n*m; ++i){
		if(a[i] == res){
			cout << x << ' ' << y << endl;
			return 0;
		}
		if(y == n && x%2 == 1){
			x++;
		}else if(y == 1 && x%2 == 0){
			x++;
		}else if(x%2 == 1){
			y++;
		}else{
			y--;
		}
	}
	
	return 0;
}
