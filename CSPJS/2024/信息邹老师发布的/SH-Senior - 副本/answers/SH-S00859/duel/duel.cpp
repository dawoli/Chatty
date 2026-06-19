#include<bits/stdc++.h>
using namespace std ; 
const int N = 1e5 + 10 ; 
int n , a[N] , ans ; 
priority_queue<int> x ; 
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout) ; 
	cin >> n ; 
	for ( int i = 1 ; i <= n ; ++i ) cin >> a[i] ; 
	sort(a + 1 , a + n + 1) ; x.push(a[1]) ; 
	for(int i = 2 ; i <= n ; ++i) {
		int t = x.top() ; 
		if(t != -a[i]) x.pop() , ++ans ; 
		x.push(-a[i]) ; 
	}
	cout << n - ans << endl ; 
	return 0 ; 
} 
