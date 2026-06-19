#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt[7][19];
void addpai(string s){
	ll h=0,d=0;
	if(s[0]=='D')h=1;
	else if(s[0]=='C')h=2;
	else if(s[0]=='H')h=3;
	else if(s[0]=='S')h=4;
	if(s[1]=='A')d=1;
	else if(s[1]=='2')d=2;
	else if(s[1]=='3')d=3;
	else if(s[1]=='4')d=4;
	else if(s[1]=='5')d=5;
	else if(s[1]=='6')d=6;
	else if(s[1]=='7')d=7;
	else if(s[1]=='8')d=8;
	else if(s[1]=='9')d=9;
	else if(s[1]=='T')d=10;
	else if(s[1]=='J')d=11;
	else if(s[1]=='Q')d=12;
	else if(s[1]=='K')d=13;
	cnt[h][d]++;
}
ll checkpai(){
	ll ans=52;
	for(ll i=1;i<=4;++i){
		for(ll j=1;j<=13;++j){
			if(cnt[i][j]>0)ans--;
		}
	}
	return ans;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	string ss="";
	for(ll i=1;i<=n;++i){
		cin>>ss;
		addpai(ss);
	}
	ll ansp=checkpai();
	cout<<ansp<<endl;
	return 0;
}
