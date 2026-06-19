#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ln,ls[105],a,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ln=n*m;
	for(ll i=1;i<=ln;i++){
		cin>>ls[i];
	}
	a=ls[1];
	sort(ls+1,ls+ln+1);
	for(ll i=ln;i>=1;i--){
		if(ls[i]==a){
			a=(ln-i+1);
		}
	}
//	cout<<a<<endl;
	y=(a+n-1)/n;
	if(y%2==0){
		x=n-a%n+1;
	}else{
		x=a%n;
	}
	cout<<y<<' '<<x<<endl;
	return 0;
}
