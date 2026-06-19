#include<bits/stdc++.h>
#define rep(i,a,b)	for(ll i=(a);i<=(b);i++)
#define per(i,a,b)	for(ll i=(a);i>=(b);i--)
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll maxn=200009;
const ll BASE=131;
const ll inf=1e15;
ll n,q;
string s[maxn][2],t[2];
ll st[maxn],nd[maxn];
ull p[5000009],h[maxn][2],ht[2][5000009];
ll get(ll l,ll r,ll tp){
	return ht[tp][r]-ht[tp][l-1]*p[r-l+1];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;
	rep(i,1,5000000)	p[i]=p[i-1]*BASE;
	cin>>n>>q;
	rep(i,1,n){
		cin>>s[i][0]>>s[i][1];
		ll len=s[i][0].size();
		s[i][0]=' '+s[i][0];
		s[i][1]=' '+s[i][1];
		rep(j,1,len){
			h[i][0]=h[i][0]*BASE+s[i][0][j];
			h[i][1]=h[i][1]*BASE+s[i][1][j];
			if(s[i][0][j]!=s[i][1][j]){
				if(st[i]==0)	st[i]=j;
				nd[i]=j;
			}
		}
	}
	rep(qid,1,q){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<"0\n";
			continue;
		}
		ll lent=t[0].size();
		t[0]=' '+t[0],t[1]=' '+t[1];
		ll stt=0,ndt;
		rep(i,1,lent){
			if(t[0][i]!=t[1][i]){
				if(stt==0)	stt=i;
				ndt=i;
			}
			ht[0][i]=ht[0][i-1]*BASE+t[0][i];
			ht[1][i]=ht[1][i-1]*BASE+t[1][i];
		}
		ll cnt=0;
//		cout<<stt<<' '<<ndt<<'\n';
		rep(i,1,n){
			ll l=stt-st[i]+1;
			ll r=l+s[i][0].size()-2;
//			cout<<i<<' '<<nd[i]<<' '<<st[i]<<'\n';
			if(nd[i]-st[i]!=ndt-stt)	continue;
			if(h[i][0]==get(l,r,0)&&h[i][1]==get(l,r,1))
				cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
