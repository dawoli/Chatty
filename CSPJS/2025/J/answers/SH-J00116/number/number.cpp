#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll d=0;
	for(ll i=0;i<=s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			d++;
			a[d]=s[i]-'0';
		}
	}
	sort(a+1,a+d+1);
	for(ll i=d;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
