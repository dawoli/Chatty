#include<bits/stdc++.h>
using namespace std;
int n;
set<string> s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string se;
		cin>>se;
		s.insert(se);
	}
	cout<<52-s.size();
	return 0;
}

