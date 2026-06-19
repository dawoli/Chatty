#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	map<string,bool>mp;
	int ans=52;
	for(int i=0; i<n; i++) {
		string s;
		cin>>s;
		if(mp[s]==1)
			continue;
		else {
			mp[s]=1;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}

