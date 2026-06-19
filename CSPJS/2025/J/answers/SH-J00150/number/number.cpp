#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
vector<int> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0' && s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	for (const auto& x : v) cout << x;
	return 0;
} 
