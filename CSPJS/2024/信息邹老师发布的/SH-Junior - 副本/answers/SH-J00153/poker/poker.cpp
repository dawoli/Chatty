#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ll n;
	set<string> s;
	cin>>n;
	for(int i=1;i<=n;i++){
		string j;
		cin>>j;
		s.insert(j);
	}
	cout<<52-s.size();
	return 0;
}
