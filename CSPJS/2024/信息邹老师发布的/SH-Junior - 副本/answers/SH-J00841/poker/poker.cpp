#include<bits/stdc++.h>
using namespace std;

int n;
string s;

set<string> j;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (int i=1 ; i<=n ; i++){
		cin>>s;
		j.insert(s);
	}
	cout<<52 - j.size()<<endl;
	return 0;
} 
