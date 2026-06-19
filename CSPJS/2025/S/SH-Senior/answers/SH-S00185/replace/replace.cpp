#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll N=2e5+9,M=5e6+9;
ll n,q,cc;ull pw[M]={1};
struct S{ull px,sx,z1,z2;}h[N];
ull hsh(string s){
	ull rs=0;
	for(ll i=0;i<s.size();i++)rs=rs*(ull)26+(ull)(s[i]-'a');
	return rs;
}
S spl(string s1,string s2){
	ll pr=0,sf=s1.size()-1;
	while(s1[pr]==s2[pr])pr++;pr--;
	while(s1[sf]==s2[sf])sf--;sf++;
	S rs;
	rs.px=hsh(s1.substr(0,pr+1));
	rs.sx=hsh(s1.substr(sf));
	rs.z1=hsh(s1.substr(pr+1,sf-pr-1));
	rs.z2=hsh(s2.substr(pr+1,sf-pr-1));
	return rs;
}
bool cmp(const S&u,const S&v){
	if(u.z1!=v.z1)return u.z1<v.z1;
	return u.z2<v.z2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	for(ll i=1;i<M;i++)pw[i]=pw[i-1]*(ull)26;
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;
		if(s1==s2){i--,n--,cc++;continue;}
		h[i]=spl(s1,s2);
	}
	sort(h+1,h+1+n,cmp);
	while(q--){
		string t1,t2;cin>>t1>>t2;
		if(t1.size()!=t2.size()){cout<<"0\n";continue;}
		if(t1==t2){cout<<cc<<"\n";continue;}
		S g=spl(t1,t2);
		ll lt,rt,l=1,r=n,md,ans=0;
		while(l<r){
			if(cmp(h[md=(l+r)/2],g))l=md+1;
			else r=md;
		}
		lt=l;l=1,r=n;
		while(l<r){
			if(cmp(g,h[md=(l+r+1)/2]))r=md-1;
			else l=md;
		}
		rt=l;
		set<ull>prx,sfx;
		prx.insert(0);sfx.insert(0);
		ll ppp=0;
		while(t1[ppp]==t2[ppp])ppp++;ppp--;
		for(ll i=0;i<=ppp;i++)prx.insert(hsh(t1.substr(i,ppp-i+1)));
		for(;g.sx;g.sx/=26)sfx.insert(g.sx);
		for(ll i=lt;i<=rt;i++)
			ans+=(prx.count(h[i].px)&&sfx.count(h[i].sx));
		cout<<ans<<"\n";
	}
	return 0;
}
