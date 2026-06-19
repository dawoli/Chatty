#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	set<string> s;
	string in;
	int n;
	cin>>n;
	while(n--){
		cin>>in;
		s.insert(in);
	}
	cout<<52-s.size();
	return 0;
}
