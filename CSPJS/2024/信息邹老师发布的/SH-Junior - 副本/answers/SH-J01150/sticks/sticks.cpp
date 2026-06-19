#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a[7]={"","10","1","200","20","2","6"};
ll num[8]={0,0,1,7,4,2,6,8};
ll hua[7]={0,8,2,17,11,5,6};

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	ll t;
	cin>>t;
	
	while(t--){
		ll n;
		cin>>n;
		//n++;
		
		if(n<=1){
			cout<<-1<<endl;
			continue;
		}
		
		if(n==10) cout<<22<<endl;
		else if(n<7) cout<<num[n]<<endl;
		else{
			cout<<a[n%7];
			for(ll i=1;i<=(n-hua[n%7])/7;i++) cout<<8;
			cout<<endl;
		}
	}
	
	//cout<<cnt<<endl;
	
	return 0;
}
