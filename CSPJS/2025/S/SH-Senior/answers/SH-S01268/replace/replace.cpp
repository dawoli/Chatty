#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
string s1[200005],s2[200005],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(ll i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<0<<endl;
			continue;
		}
		ll lt=t1.length();
		t1=" "+t1;
		t2=" "+t2;
		ll ans=0;
		for(ll j=1;j<=n;j++){
			ll ls=s1[j].length();
			for(ll k=1;k<=lt-ls+1;k++){
				if(k>1&&t1.substr(1,k-1)!=t2.substr(1,k-1)){
					break;
				}
				if(k<=lt-ls&&t1.substr(k+ls)!=t2.substr(k+ls)){
					continue;
				}
				if(t1.substr(k,ls)==s1[j]&&t2.substr(k,ls)==s2[j]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

