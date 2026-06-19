#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n;
string s[7]={"","10","1","22","20","2","6"};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1) cout<<-1<<endl;
		else if(n==2) cout<<1<<endl;
		else if(n==3) cout<<7<<endl;
		else if(n==4) cout<<4<<endl;
		else if(n==5) cout<<2<<endl;
		else if(n==6) cout<<6<<endl;
		else if(n%7==0){
			for(ll i=0;i<n/7;i++) cout<<'8';
			cout<<endl;
		}else{
			cout<<s[n%7];
			for(ll i=0;i<n/7-(s[n%7].size()-1);i++) cout<<'8';
			cout<<endl;
		}
	}
	return 0;
}
