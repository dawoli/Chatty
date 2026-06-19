//poker
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	set<string> s;
	string k;
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>k;
		s.insert(k);
	}
	cout<<52-s.size();
	return 0;
}
