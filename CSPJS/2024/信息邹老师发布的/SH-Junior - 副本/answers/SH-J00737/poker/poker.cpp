#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
set<string> s;
string card;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>card,s.insert(card);
	cout<<52-s.size()<<endl;
	return 0;
}
