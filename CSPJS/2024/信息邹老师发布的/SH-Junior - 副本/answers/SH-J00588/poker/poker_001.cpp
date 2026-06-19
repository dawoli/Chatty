#include<bits/stdc++.h>
using namespace std;

map<string, int> mp;
int n;

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++){
		string s;
		cin >> s;
		if (mp.count(s) == 0){
			mp[s] ++;
		}
	}
	cout << (52 - mp.size());
} 
