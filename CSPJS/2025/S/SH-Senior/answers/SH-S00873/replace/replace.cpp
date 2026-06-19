#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, q, ans = 0;
string s[N], t[N];
string t1, t2;

bool check(int x, string y){//x开始后是否有y 
	int yl = y.length();
	for(int i = x; i <= x + yl - 1; i ++){
		if(t1[i] != y[i - x]) return false;
	}
	return true;
}

void solve(){
	ans = 0;
	cin >> t1 >> t2;
	string tt2 = t1;
	int tl1 = t1.length();
	int tl2 = t2.length();
	if(tl1 != tl2){
		cout << 0 << endl;
		return;
	}
	for(int i = 1; i <= n; i ++){
		int sl = s[i].length();
		for(int j = 0; j + sl <= tl1; j ++){
			if(check(j, s[i])){
				for(int k = j; k <= j + sl - 1; k ++){
					t1[k] = t[i][k - j];//替换 
				}
				j += sl; 
			}
		}
		//cout << t1 << " " << t2 << endl;
		if(t1 == t2) ans ++;
		t1 = tt2;
	}
	cout << ans << endl;
}


int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++){
		cin >> s[i] >> t[i];
	}
	if(n <= 1000){
		for(int i = 1; i <= q; i ++){
			solve();
		}
	}else{
		for(int i = 1; i <= q; i ++){
			cout << 0 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
