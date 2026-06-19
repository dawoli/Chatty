#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string ch[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>ch[i];
	bool flag=0;
	for(ll i=2;i<=n;i++){
		if(ch[i]!=ch[i-1]){
			flag=0;
			break;
		}
	}
	if(flag==1) cout<<52-n<<endl;
	else{
		ll cnt=0;
		sort(ch+1,ch+1+n);
		for(ll i=2;i<=n;i++){
			if(ch[i]==ch[i-1]) cnt++;
		}
		cout<<52+cnt-n<<endl;
	}
	return 0;
}
