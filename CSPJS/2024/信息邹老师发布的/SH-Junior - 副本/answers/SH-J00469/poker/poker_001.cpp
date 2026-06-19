#include <bits/stdc++.h>
using namespace std;
set<string> pok;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		pok.insert(s);
	}
	cout<<52-(int)pok.size();
	return 0;
}
