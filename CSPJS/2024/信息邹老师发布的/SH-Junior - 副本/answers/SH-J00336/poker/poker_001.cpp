#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
ll n;
string card;
set<string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>card;
		s.insert(card);
	}
	cout<<52-s.size()<<endl;
	return 0;
}
