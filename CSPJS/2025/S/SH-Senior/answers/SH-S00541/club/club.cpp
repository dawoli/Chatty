#include<bits/stdc++.h>
using namespace std;
int a[10010][3] , b[20020] , c[10010] , d[10010];
int main(){
	freopen("club.in" , "r" , stdin);
	freopen ("club.out" , "w" , stdout);
	int n , m  , ans1 , ans2; 
	cin >> n;
	for (int i = 0 ; i < n ; i ++){
		cin >> m;
		for (int k = 0 ; k < m ; k ++){
			for (int j = 0 ; j < 3 ; j ++){
				cin >> a[k][j];
			}
		}//shuru
		for (int i = 0 ; i < m ; i ++){
			if (a[i][1] == a[i][2] && a[i][1] == 0){
				b[i] = a[i][0];
			}
		}
		sort (b , b + m);
		for (int i = m/2 ; i < m ; i ++){
			ans1 += b[i];
		}//special A

	}
	cout << ans1; 
	return 0;
}
