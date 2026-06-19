#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int f = 1, x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return f * x;
}

int t, n, ans, res;
const int maxn = 2e5 + 10;
int a[maxn], color[maxn];
vector<int> color1;
vector<int> color0;

signed main(){
	t = read();
	while(t--){
		ans = 0;
		n = read();
		for(int i = 1; i <= n; i++) cin >> a[i];
	}
	for(int i = 1; i <= t; i++){
		cout << 0 << '\n';
	} 
	return 0;
} 
