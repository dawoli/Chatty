#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')
			a.push(s[i]-'0');
	}
	while(!a.empty()){
		cout<<a.top();
		a.pop();
	}
	return 0;
} 
