/*
CSPS 2025 RP++
Code With Love by Hughpig(646208)
QwQ
*/
#include<bits/stdc++.h>
#include<string>
using namespace std;
#define ll long long
#define up(l,r,i) for(int i=(l);i<=(r);++i)

ll n,q;
string str[200007][2],ta,tb;

void solve(){
	cin>>n>>q;
	up(1,n,i)cin>>str[i][0]>>str[i][1];
	while(q--){
		cin>>ta>>tb;
		ll cnt=0;
		up(1,n,i){
			if(ta.find(str[i][0])==string::npos)continue;
			if(tb.find(str[i][1])==string::npos)continue;
			//cout<<ta<<' '<<tb<<' '<<ta.find(str[i][0])<<' '<<tb.find(str[i][1])<<'\n';
			ll x=ta.find(str[i][0]),y=tb.find(str[i][1]);
			if(ta.substr(0,x)!=tb.substr(0,y))continue;
			if(ta.substr(x+str[i][0].size())!=tb.substr(y+str[i][1].size()))continue;
			++cnt;
		}
		cout<<cnt<<'\n';
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc=1;
	//cin>>tc;
	while(tc--){
		solve();
	}
}

