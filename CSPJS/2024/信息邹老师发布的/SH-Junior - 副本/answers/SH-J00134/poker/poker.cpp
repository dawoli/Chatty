#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
int n;
string x;
int main(){
	ifstream cin("poker.in");
	ofstream cout("poker.out");
	cin >> n;
	int res = 0;
	for(int i = 0; i < n; i ++){
		cin >> x;
		if(mp[x]) continue;
		res ++;
		mp[x] = 1;
	}
	cout << 52 - res;
	return 0;
}
