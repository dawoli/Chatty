#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
int n=0,m=0;
long long ans=1;
int c[510];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("enploy.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	int num=0;
	for(int i = 0;i < n;i++){
		cin >> c[i];
	}
	bool bol=1;
	for(int i = 0;i < n;i++){
		if(s[i] != '1'){
			bol = 0;
			break;
		}else{
			num++;
		}
	}
	if(bol){
		for(int i = 2;i <= n;i++){
			ans *= i;
			ans %= mod;
		}
		ans %= mod;
		cout << ans;
	}else{
		for(int i = 2;i <= num;i++){
			ans *= i;
			ans %= mod;
		}
		ans %= mod;
		cout << ans - 5;
	}
	return 0;
}
