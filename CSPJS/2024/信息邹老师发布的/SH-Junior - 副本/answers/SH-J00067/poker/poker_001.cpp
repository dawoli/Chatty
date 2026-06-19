#include<bits/stdc++.h>
using namespace std;
int n;
set<string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string ss;
		cin>>ss;
		s.insert(ss);
	}
	cout<<52-s.size();
	return 0;
}

