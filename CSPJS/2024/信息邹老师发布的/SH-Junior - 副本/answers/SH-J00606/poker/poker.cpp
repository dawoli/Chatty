#include<bits/stdc++.h>
using namespace std;
set<string> pok;
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		pok.insert(s);
	}
	cout<<52-pok.size();
	return 0;
}
