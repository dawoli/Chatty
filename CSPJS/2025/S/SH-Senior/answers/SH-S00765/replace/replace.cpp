#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[2];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i = 0;i<n;i++) cin>>s[0]>>s[1];
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		cout<<(s1.size()-s[0].size())*n;
	}
	return 0;
}
