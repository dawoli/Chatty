//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505;

int n, m, sum;

string s;

int a[N], nandu[N], cnt;

string s1;

int jiech(int n){
	int ans = 1;
	for(int i = 1; i <= n; ++i){
		ans = (ans * i) % (998244353);
	//	cout << ans <<endl;
	}
	//cout << ans << endl;
	return ans % 998244353;
}

signed main(){
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i){
		nandu[i] = (s[i-1] -'0');
		if(nandu[i] == 0) cnt++; 
	}
	if(n == m && cnt != 0) cout << 0;
	else if(n == m && cnt == 0) cout << 1;
	else if(cnt == 0){
		for(int i = n - m; i < n; ++i){
			//cout <<"1" << endl;
			sum += (((jiech(n)% 998244353/(jiech(n - i)% 998244353 * jiech(i)% 998244353)) * jiech(n)% 998244353 ));
			
		}
		cout << (sum+1) % 998244353;
	}else if(n - cnt < m) cout <<0;
	
	return 0;
} 
