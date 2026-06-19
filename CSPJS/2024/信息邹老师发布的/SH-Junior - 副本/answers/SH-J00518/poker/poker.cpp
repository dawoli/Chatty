#include<bits/stdc++.h>
using namespace std;
set<string> pok;
int n;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		pok.insert(s);
	}
	cout<<52-pok.size();
	return 0;
} 
