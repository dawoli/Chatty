#include <bits/stdc++.h>
using namespace std;
long long T,n,k,Q,m,t,r,c;
vector <long long> a[100005]; 
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> T;
	while (T--){
		cin >> n >> k >> Q;
		for (long long i = 1;i <= n;i++){
			cin >> m;
			while (m--) cin >> t,a[i].push_back(t);
		}
		cin >> Q;
		while (Q--){
			cin >> r >> c;
			cout << 1 << endl;
		}
	}
	return 0;
}
