#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e3+10; 
int n,k;
int ans;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	vector<int>a(n+1);
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	cout << floor(1.0*n/2);
	return 0; 
}
