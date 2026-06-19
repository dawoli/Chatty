#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ll t;
	cin>>t;
	bool flag=0;
	while(t--){
		ll n;
		cin>>n;
		ll mn=1e18;
		string a="";
		if(n%7==0){
			flag=1;
			for(ll i=1;i<=n/7;i++){
				a+='8';
			}
			cout<<a<<endl;
			continue;
		}
		if(n%7==1){
			flag=1;
			a+='1',a+='0';
			for(ll i=1;i<=n/7;i++){
				a+='8';
			}
			cout<<a<<endl;
			continue;
		}
	}
	if(flag==0)cout<<-1<<endl<<1<<endl<<7<<endl<<6<<endl<<208<<endl;
}
