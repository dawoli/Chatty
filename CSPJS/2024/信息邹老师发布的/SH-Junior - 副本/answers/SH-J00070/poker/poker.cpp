#include <bits/stdc++.h>
using namespace std;
set <char> Dse,Cse,Hse,Sse;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n;
	string s;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>s;
		if(s[0] == 'D')Dse.insert(s[1]);
		else if(s[0] == 'C')Cse.insert(s[1]);
		else if(s[0] == 'H')Hse.insert(s[1]);
		else Sse.insert(s[1]);
	}
	cout<<52-Sse.size()-Hse.size()-Cse.size()-Dse.size();
	return 0;
}
