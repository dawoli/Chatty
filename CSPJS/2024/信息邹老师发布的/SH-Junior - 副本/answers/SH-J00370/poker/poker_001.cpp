#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
set<string> u;
int main(){
    freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		string s;
		cin>>s;
		u.insert(s);
	}
	cout<<52-u.size();
	return 0;
}
