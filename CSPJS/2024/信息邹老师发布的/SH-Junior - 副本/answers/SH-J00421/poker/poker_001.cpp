#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<string,bool> mp;
string s;
ll n;
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n--) cin>>s,mp[s]=1;
	cout<<52-mp.size();
	return 0;
}
