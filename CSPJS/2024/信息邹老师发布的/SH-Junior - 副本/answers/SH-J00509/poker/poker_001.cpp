#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	set<string> s;
	for(int i=1;i<=n;i++){
		string str;
		cin>>str;
		s.insert(str);
	}
	cout<<52-s.size()<<endl;
	return 0;
} 
