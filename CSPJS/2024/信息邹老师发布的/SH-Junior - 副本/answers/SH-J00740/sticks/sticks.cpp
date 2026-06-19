#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[21]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,228,208,288,688};
int main(){
	freopen("stricks.in","r",stdin);
	freopen("stricks.out","w",stdout);
	ll n,t;
	cin>>t;
	for(ll i=0;i<t;i++){
		cin>>n;
		ll a;
		if(n%7==0){
			a=n/7;
			for(ll j=0;j<a;j++){
				cout<<"8";
			}
			cout<<endl;
		}
		else if(n<=20){
			cout<<f[n]<<endl;
		}
		else if(n%7==1&&n>20){
			a=n/7-1;
			cout<<"10";
			for(ll j=0;j<a;j++)
				cout<<"8";
			cout<<endl;
		}
		else if(n%7==2){
			a=n/7;
			cout<<"1";
			for(ll j=0;j<a;j++)
				cout<<"8";
			cout<<endl;
		}
		else if(n%7==3){
			a=n/7-1;
			cout<<"22";
			for(ll j=0;j<a;j++)
				cout<<"8";
			cout<<endl;
		}
		else if(n%7==4){
			a=n/7-1;
			cout<<"20";
			for(ll j=0;j<a;j++)
				cout<<"8";
			cout<<endl;
		}
		else if(n%7==5){
			a=n/7;
			cout<<"2";
			for(ll j=0;j<a;j++)
				cout<<"8";
			cout<<endl;
		}
		else if(n%7==6){
			a=n/7;
			cout<<"6";
			for(ll j=0;j<a;j++)
				cout<<"8";
			cout<<endl;
		}
	}
	return 0;
}
