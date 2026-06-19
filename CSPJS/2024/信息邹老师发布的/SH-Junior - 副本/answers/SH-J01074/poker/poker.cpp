#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
string s;
map<string, ll> mp;
ll n, ans = 52;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	while(cin >> s){
		if(!mp[s]) ans--;
		mp[s]++;
	}
	cout << ans;
	return 0;
}
