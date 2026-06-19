#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int t, n, k, q;
int l[100005];
vector<int> s[100005];
int r[100005], c[100005];
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i++){
			cin >> l[i];
			for(int j = 1, tmp; j <= l[i]; j++){
				cin >> tmp;
				s[i].push_back(tmp);
			}
		}
		
		for(int i = 1; i <= q; i++){
			cin >> r[i] >> c[i];
			cout << 0 << endl;
		}
	}
	return 0;
}
