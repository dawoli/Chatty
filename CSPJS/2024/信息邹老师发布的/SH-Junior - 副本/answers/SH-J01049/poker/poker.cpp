#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll ans;
string s;
ll x[9][60];
map<char,ll>cnt;
void deal(ll y,char c){
	cnt['A']=1;
	cnt['2']=2;
	cnt['3']=3;
	cnt['4']=4;
	cnt['5']=5;
	cnt['6']=6;
	cnt['7']=7;
	cnt['8']=8;
	cnt['9']=9;
	cnt['T']=10;
	cnt['J']=11;
	cnt['Q']=12;
	cnt['K']=13;
	x[y][cnt[c]]=1;
}
void input(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>s;
		if(s[0]=='D')deal(1,s[1]);
		if(s[0]=='C')deal(2,s[1]);
		if(s[0]=='H')deal(3,s[1]);
		if(s[0]=='S')deal(4,s[1]);
	}
}
void solve(){
	for(ll i=1;i<=4;i++){
		for(ll j=1;j<=13;j++){
			if(x[i][j]!=1)ans++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	input();
	solve();
	return 0;
}
