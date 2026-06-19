#include<bits/stdc++.h>
using namespace std;
long long n;
set<string>s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		string b;
		cin>>b;
		s.insert(b);
	}
	cout<<52-s.size();
	return 0;
}
