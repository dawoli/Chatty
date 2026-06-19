#include<bits/stdc++.h>
using namespace std;

map<string,int> mp;

int n,cnt=0;
string s;
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>s;
		mp[s]++;
		if(mp[s]==1) cnt++;
	}
	cout<<52-cnt<<'\n'; 
	return 0;
} 
