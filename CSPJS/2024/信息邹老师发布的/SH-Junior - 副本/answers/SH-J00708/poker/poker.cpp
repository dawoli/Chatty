#include<bits/stdc++.h>
using namespace std;
set<string> s;
set<string>::iterator it;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		string a;
		cin>>a;
		s.insert(a);
	}
	int ans=52-s.size();
	cout<<ans;
	return 0;
}
