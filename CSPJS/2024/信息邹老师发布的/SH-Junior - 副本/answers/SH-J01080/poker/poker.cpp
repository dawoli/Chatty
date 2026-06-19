#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ok[10][20];
ll ans=52,n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin>>n;
	
	for(ll i=1;i<=n;++i){
		char c,ch;
		ll a,b;
		cin>>c>>ch;
		
		if(c=='S') a=1;
		else if(c=='H') a=2;
		else if(c=='D') a=3;
		else if(c=='C') a=4;
		
		if(ch=='A') b=1;
		else if(ch=='2') b=2;
		else if(ch=='3') b=3;
		else if(ch=='4') b=4;
		else if(ch=='5') b=5;
		else if(ch=='6') b=6;
		else if(ch=='7') b=7;
		else if(ch=='8') b=8;
		else if(ch=='9') b=9;
		else if(ch=='T') b=10;
		else if(ch=='J') b=11;
		else if(ch=='Q') b=12;
		else if(ch=='K') b=13;
		
		if(ok[a][b]) continue;
		ok[a][b]=1;
		ans--;
	}
	
	cout<<ans<<endl;
	return 0;
}
