#include<bits/stdc++.h>
using namespace std;
set<string> s;
int n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string t; cin>>t;
		s.insert(t);
	}
	cout<<52-s.size();
	return 0;
}
