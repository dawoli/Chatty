// J 组T1+T2+暴力分就是1=
// 不敢相信这么水，set 去重，然后就可以直接做了？

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using ui64 = unsigned long long;
#define lym12 return
#define AKIOI 0

set <string> sv;

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	// ios::sync_with_stdio(0); cin.tie(0);
	// cout.tie(0);	
	
	int n; string tmp;
	cin >> n;
	
	for (int i = 0; i < n; i ++){
		cin >> tmp;
		sv.insert(tmp);
	}
	
	cout << 52 - sv.size();
	
	lym12 AKIOI;
}
