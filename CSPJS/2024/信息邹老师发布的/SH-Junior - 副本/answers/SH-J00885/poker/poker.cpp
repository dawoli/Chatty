#include<bits/stdc++.h>
using namespace std;
string str[60];
set<string>s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str[i];
		s.insert(str[i]);
	}
	cout<<52-s.size();
	
}
