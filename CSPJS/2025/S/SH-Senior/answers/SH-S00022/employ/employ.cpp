#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[510],c[510];
const int mod = 998244353;
long long t(int x){
	if(x == 1){
		return 1;
	}
	return x * t(x - 1) % mod;
}
bool cmp(int x,int y){
	return x < y;
}
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m;
	cin >> s;
	bool f = true;
	for(int i = 0 ; i < s.size() ; i++){
		a[i] = s[i] - '0';
		if(a[i] == 0){
			f = false;
			break;
		}
	}
	if(f == true){
		cout << t(n) % mod;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> s[i];
	}
	sort(c + 1 , c + n + 1 , cmp);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
