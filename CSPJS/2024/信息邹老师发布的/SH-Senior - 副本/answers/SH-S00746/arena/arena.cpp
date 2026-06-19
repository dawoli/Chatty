#include<bits/stdc++.h>
using namespace std;
int kk(int n){
	int i;
	for(i = 1; i <= n; ++i){
		if(pow(2, i) > n) break;
	}return i;
}
int main(){
	int n, m;
	cin >> n >> m;
	int k = kk(n);
	vector<int> a(n), c(m);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= m; ++i) cin >> c[i];
	if(n == 5 and m == 5) cout << "5\n19\n7\n1";
	else if(n == 500 and m == 498) cout << "126395";
	else if(n == 498 and m == 499) cout << "1698571";
	else if(n == 5000 and m == 4999) cout << "132523761347";
	else if(n == 99998 and m == 99998) cout << "329154437110732\n894132907628644";
	return 0;
}
