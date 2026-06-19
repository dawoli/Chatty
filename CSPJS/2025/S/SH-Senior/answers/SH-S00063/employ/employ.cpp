#include <iostream>
using namespace std;
int N = 1e3 + 5;
int INF = 998244353;
long long cheng(int num){
	long long ans = 1;
	while(num){
		ans *= num;
		num--;
		ans %= INF;
	}
	return ans;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	bool flag = true;
	bool flag2 = false;
	bool flag1 = true;
	int fir = 0;
	int cnt = 0;
	for(int i=0; i<s.size(); i++){
		if(fir == 0 && s[i] == '1') fir = i;
		if(s[i] != '1') flag = false;
		if(s[i] == '0') flag2 = true;
		if(s[i] == '1'){
			flag1 = false;
			cnt++;
		}
	}
	int p[N] = {};
	int mn = 1e9;
	int mx = 0;
	for(int i=1; i<=n; i++){
		cin >> p[i];
		mn = min(p[i], mn);
		mx = max(p[i], mx);
	}
	if(cnt < m){
		cout << 0 << endl;
		return 0;
	}
	if(flag1){
		cout << 0 << endl;
		return 0;
	}
	if(flag){
		cout << cheng(n) << endl;
		return 0;
	}
	if(m == 1){
		if(mx < fir){
			cout << 0 << endl;
			return 0;
		}
		else{
			cout << cheng(n) << endl;
			return 0;
		}
	}
	if(m == n){
		if(flag2){
			cout << 0 << endl;
			return 0;
		}
		else{
			cout << cheng(n) << endl;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
