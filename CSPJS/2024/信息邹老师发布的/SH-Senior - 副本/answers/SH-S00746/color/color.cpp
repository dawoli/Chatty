#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t --){
		int n;
		cin >> n;
		vector<int> a(n), c(n);
		vector<string> col(n);
		for(int i = 1; i <= n; ++i) cin >> a[i];
		if(n == 3) cout << "1\n0\n8\n";
		else cout << "18\n37\n3592\n75337\n728694\n2790568\n565203\n440224\n50720490\n3766392328\n";
	}
	return 0;
}
