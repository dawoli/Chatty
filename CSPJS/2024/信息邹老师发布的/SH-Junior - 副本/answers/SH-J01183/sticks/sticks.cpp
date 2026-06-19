//60
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL T, n, gen[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, mx[10] = {8, 0, 6, 9, 2, 3, 5, 4, 7, 1};
vector<LL> ans, v;
bool flag;
void dfs(LL k){
//	printf("k = %d\n", k);
	if(!k){
//		cout << "-----------------" << endl;
		LL t = 0;
		for(LL i = v.size() - 1; i >= 0; -- i)
			t = t * 10 + v[i];
//		cout << "t = " << t << endl;
		ans.push_back(t);
		return;
	}
	
	if(k == 1)
		return;
	
	for(LL i = 0; i < 10; ++ i){
		LL tmp = mx[i];
		if(gen[tmp] <= k){
			v.push_back(tmp);
			dfs(k - gen[tmp]);
			if(flag)
				return;
			v.pop_back();
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	cin >> T;
	while(T --){
		while(ans.size())
			ans.pop_back();
		
		cin >> n;
		if(n == 1){
			cout << -1 << endl;
			continue;
		}
		if(n == 6){
			cout << 6 << endl;
			continue;
		}
		if(n % 7 == 0){
			while(n){
				cout << 8;
				n -= 7;
			}
			cout << endl;
			continue;
		}
		if(n % 7 == 1){
			cout << 10;
			n -= 8;
			while(n){
				cout << 8;
				n -= 7;
			}
			continue;
		}
		if(n <= 20){
			flag = false;
			dfs(n);
			if(!ans.size()){
				cout << -1 << endl;
				continue;
			}
			sort(ans.begin(), ans.end());
			cout << ans[0] << endl;
			continue;
		}
		while(n){
			if(n == 1){
				cout << -1 << endl;
				break;
			}
			for(LL i = 0; i < 10; ++ i){
				int tmp = mx[i];
				if(gen[tmp] <= n){
					ans.push_back(tmp);
					n -= gen[tmp];
					break;
				}
			}
		}
		if(n == 1)
			continue;
		for(LL i = ans.size() - 1; i >= 0; -- i)
			cout << ans[i];
		cout << endl;
	}
	return 0;
}
