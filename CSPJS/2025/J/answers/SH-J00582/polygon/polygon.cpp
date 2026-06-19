#include <bits/stdc++.h>
using namespace std;

int n, l[5005];
long long ans;
bool flag = false;

void dfs(int d, int sum, int last, int m){
	if (m > 2 && (sum > l[last] * 2)){
		ans = (ans + 1) % 998244353;
		flag = true;
		//cout << "    d " << d << " sum " << sum << " last " << last << " m " << m << "\n";
    }
    if (d == n){
    	return;
	}
	for (int i = last + 1; i <= n; i++){
		if (flag == false)
			dfs(d + 1, sum, i, m);
		dfs(d + 1, sum + l[i], i, m + 1);
	}
}

int main(){
	freopen("polygon.in", "r", stdin); freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> l[i];
	}
	sort(l + 1, l + 1 + n);
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= n; j++){
			if (i != j){
				flag = false;
				dfs(2, l[i] + l[j], j, 2);
				//cout << i << ' ' << j << ' ' << "\n"; 
			}
		}
	}
	cout << ans;
}
