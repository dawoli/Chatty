#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998224353;

vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	   
	cin.tie(0);
	
	for(int i = 1; i <= 200; i++){
		random_device rd;
		mt19937 g(rd());
		shuffle(v.begin(), v.end(), g);
	}
	
	cout << v[1];
	
	cout.tie(0);
	return 0;
}

