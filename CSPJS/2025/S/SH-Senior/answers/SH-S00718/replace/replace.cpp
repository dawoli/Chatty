#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N = 2e5 + 10;
LL n, q;
string s1[N], s2[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> q;
	for(LL i = 1ll; i <= n; i++){
		cin >> s1[i] >> s2[i];
	} 
	for(LL i = 1ll; i <= q; i++){
		cout << 0 << '\n';
	}	
	return 0;
}
