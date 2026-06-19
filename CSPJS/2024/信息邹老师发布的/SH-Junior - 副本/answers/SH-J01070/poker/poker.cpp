#include<bits/stdc++.h>
using namespace std;
set<string>s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string st;
		cin>>st;
		s.insert(st);
	}
	int x=s.size();
	cout<<52-x;
	return 0;
}
