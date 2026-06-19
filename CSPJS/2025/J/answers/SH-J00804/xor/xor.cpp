#include <bits/stdc++.h>
using namespace std;
long long x[300001], n, k, cnt1, cnt2, f[2501], ans, ret;
short vis[500000];
bool flag = true;
set<pair<int, int>> v;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i = 1; i <= n; i++){
		cin>>x[i];
		flag = flag && (x[i] == 1 || x[i] == 0);
		cnt1 += x[i] == 1;
	}
	if(flag){
		if(k == 1){
			cout<<cnt1;
		}else if(k == 0){
			cout<<cnt1 / 2 + cnt2;
		}
	}else{
		if(n > 2000){
			return 0;
		}
		for(int i = 1; i <= n; i++){
			if(x[i] == 0){
				continue;
			}
			f[i] = x[i];
			if(f[i] == k){
				v.insert(make_pair(i, i));
			}
			for(int j = i + 1; j <= n; j++){
				f[j] = f[j - 1] ^ x[j];
				if(x[j] == 0){
					continue;
				}
				if(f[j] == k){
					v.insert(make_pair(i, j));
				}
			}
		}
		cout<<v.size();
	}
	return 0;
} 
