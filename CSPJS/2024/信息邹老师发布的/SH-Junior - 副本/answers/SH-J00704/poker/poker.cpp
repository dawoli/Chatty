#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n;
	cin>>n;
	set<string> s;
	for(long long i=1;i<=n;i++){
		string ns;
		cin>>ns;
		s.insert(ns);
	}
	cout<<52-s.size();
	return 0;
} 
