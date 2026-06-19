#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
const ll maxn=1e5+9;
ll n;
bool vst[9][19];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	rep(i,1,n){
		char a,b;
		cin>>a>>b;
		ll x,y;
		if(a=='D')	x=1;
		else if(a=='C')	x=2;
		else if(a=='H')	x=3;
		else if(a=='S')	x=4;
		if(b=='A')	y=1;
		else if(b=='T')	y=10;
		else if(b=='J') y=11;
		else if(b=='Q')	y=12;
		else if(b=='K')	y=13;
		else y=(b-'0');
		vst[x][y]=1;
	}
	ll ans=0;
	rep(i,1,4)	rep(j,1,13)	if(!vst[i][j])	ans++;
	cout<<ans;
	return 0;
} 
