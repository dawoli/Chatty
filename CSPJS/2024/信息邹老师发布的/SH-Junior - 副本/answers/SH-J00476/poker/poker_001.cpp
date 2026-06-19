#include<bits/stdc++.h>
using namespace std;
set<string> s7t;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		s7t.insert(s);
	}
	cout<<52-s7t.size()<<endl;
	return 0;
} 
