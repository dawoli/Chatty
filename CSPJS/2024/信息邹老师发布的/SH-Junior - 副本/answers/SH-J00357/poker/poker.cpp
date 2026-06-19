#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool has[4][14];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char clr,card;
		cin>>clr>>card;
		ll idclr,idcard;
		if(clr=='D') idclr=0;
		if(clr=='C') idclr=1;
		if(clr=='H') idclr=2;
		if(clr=='S') idclr=3;
		if(card>='2'&&card<='9') idcard=card-'0';
		if(card=='A') idcard=1;
		if(card=='T') idcard=10;
		if(card=='J') idcard=11;
		if(card=='Q') idcard=12;
		if(card=='K') idcard=13;
		has[idclr][idcard]=1; 
	}
	ll cnt=0;
	for(int i=0;i<4;i++)
		for(int j=1;j<=13;j++)
			if(!has[i][j]) cnt++;
	cout<<cnt;
	return 0;
}

