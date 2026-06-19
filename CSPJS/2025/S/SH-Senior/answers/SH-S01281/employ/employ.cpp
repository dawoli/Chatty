#include<bits/stdc++.h>
using namespace std;

int n, m, c[505], ans, a[505];
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> s;
	for(int i = 1; i <= n; ++ i)
		cin >> c[i];
	
	bool flag = true;
	for(int i = 0; i < s.size(); ++ i)
		if(s[i] != '1'){
			flag = false;
			break;
		}
	
	if(flag){
		ans = 1;
		for(int i = 1; i <= n; ++ i)
			ans *= i;
		cout << ans;
		return 0;
	}
	
	if(m == n){
		cout << 0;
		return 0;
	}
//	if(m == 1){
//		
//	}
	
	for(int i = 1; i <= n; ++ i)
		a[i] = i;
	
	do{
		int cnt = 0, luqu = 0;
		for(int i = 1; i <= n; ++ i){
			if(s[i - 1] == '0')
				++ cnt;
			else if(cnt >= c[a[i]])
				++ cnt;
			else
				++ luqu;
		}
		if(luqu >= m)
			ans = (ans + 1) % 998244353;
	}while(next_permutation(a + 1, a + n + 1)); 
	cout << ans;
	return 0;
}
