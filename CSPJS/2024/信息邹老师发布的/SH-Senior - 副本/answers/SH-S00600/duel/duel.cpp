#include<bits/stdc++.h>
using namespace std;
const int N = 100009;
int n, a[N], lst, ans, mxx;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		a[x]++;
		mxx = max(mxx, x);
	}
	ans = n;
	for(int i = 1; i <= mxx; i++){
		if(a[i] != 0){
			if(lst >= a[i]) {
				ans -= a[i];
			}
			else{
				ans -= lst;
				lst = a[i]; 
			}
		}
	}
	cout << ans << endl;
	return 0; 
}
