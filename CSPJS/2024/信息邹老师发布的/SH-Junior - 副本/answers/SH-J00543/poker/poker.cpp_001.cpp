#include<bits/stdc++.h>
using namespace std;
int n, cnt = 0;
string p;
map<string, int> mp;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	while(n--){
		cin >> p;
		if(!mp[p]){
			mp[p] = 1;
			cnt++;
		}
		else continue;
	}
	cout << 52 - cnt;
	return 0;
} 
