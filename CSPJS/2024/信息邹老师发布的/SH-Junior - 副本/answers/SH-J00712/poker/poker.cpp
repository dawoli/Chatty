#include<bits/stdc++.h>
using namespace std;
set<string> s;
int n;
string p;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p;
		s.insert(p);
	}
	cout<<52-s.size();
	return 0;
}

