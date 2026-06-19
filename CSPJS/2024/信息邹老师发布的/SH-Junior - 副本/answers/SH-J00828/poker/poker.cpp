#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
bool kl[50][140];
string tmp;
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> tmp;
		char x,y;
		ll a,b=0;
		x=tmp[0];
		y=tmp[1];
		if(x=='D') {
			a=1;
		}
		if(x=='C') {
			a=2;
		}
		if(x=='H') {
			a=3;
		}
		if(x=='S') {
			a=4;
		}
		if(y=='A') {
			b=1;
		}
		if(y=='J') {
			b=11;
		}
		if(y=='Q') {
			b=12;
		}
		if(y=='K') {
			b=13;
		}
		if(y=='T') {
			b=10;
		}
		if(b==0) {
			b=y-'0';
		}
		kl[a][b]=1;
	}
	for(int i=1; i<=4; i++) {
		for(int j=1; j<=13; j++) {
			if(!kl[i][j]){
				ans++;
				//cout <<"i="<<i<<", j="<<j<<"\n";
			}
		}
	}
	cout << ans;
}
