#include<bits/stdc++.h>
#include<set>
using namespace std;
set<string> s;
int a;
int cnt;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>a;
	while(a--){
		string s1;
		cin>>s1;
		s.insert(s1);
	}
	cout<<52-s.size();
	return 0;
}
