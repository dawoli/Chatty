#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll ans;
ll x[20];
void solveBF(){
	x[0]=6;
	x[1]=2;
	x[2]=5;
	x[3]=5;
	x[4]=4;
	x[5]=5;
	x[6]=6;
	x[7]=3;
	x[8]=7;
	x[9]=6;
	for(ll i=0;1;i++){
		ll j=i;
		ans=0;
		while(j){
			ll cnt=j%10;
			ans+=x[cnt];
			j/=10;
		}
		if(ans==n){
			cout<<i<<endl;
			break;
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ll o;
	cin>>o;
	for(ll i=1;i<=o;i++){
		cin>>n;
		if(n==1)cout<<-1<<endl;
		else if(n<=100009)solveBF();
	}
	return 0;
}
