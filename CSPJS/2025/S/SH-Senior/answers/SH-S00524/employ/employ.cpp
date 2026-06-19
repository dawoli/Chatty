/*
CSPS 2025 RP++
Code With Love by Hughpig(646208)
QwQ
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define up(l,r,i) for(int i=(l);i<=(r);++i)
#define pb push_back

ll n,m,c[507],ans,id[507];
bool vis[507];
//vector<ll> val;
string s;

bool check(){
	int cnt=0,_ans=0;
	for(int i=1;i<=n;++i){
		char ch=s[i-1];
		if(ch=='1'){
			if(c[id[i]]>cnt)++_ans,cnt=0;
			else ++cnt;
		}
		else ++cnt;
	}
	return _ans>=m;
}

void solve(){
	cin>>n>>m;
	cin>>s;
	up(1,n,i)cin>>c[i],id[i]=i;
	//sort(val.begin(),val.end());
	sort(c+1,c+n+1);
	do{
		if(check()){
			++ans;
			//up(1,n,i)cout<<c[i]<<' ';
		}
	}while(next_permutation(id+1,id+n+1));
	cout<<ans;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc=1;
	//cin>>tc;
	while(tc--){
		solve();
	}
}

