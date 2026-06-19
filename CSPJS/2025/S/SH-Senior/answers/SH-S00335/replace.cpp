#include<bits/stdc++.h>
using namespace std;
#define pr pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define fi first
#define se second
#define mod 998244353
#define base 13331
#define N 200010
#define M 4010
#define B 50
int n,q,l[N],r[N],z[N],cnt1,cnt2,cnt3,cnt,nz;
vector<int> nl,nr;
string s[N][3],t[3];
unordered_map<int,int> mp1,mp2,mp3;
vector<int> id[N];
bitset<N> g[M*2],s1,s2,s3;
unordered_map<int,vector<int> > h1[N],h2[N];
map<pr,int> to1,to2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		if(s[i][1]==s[i][2]){
			i--;
			n--;
			continue;
		} 
		int now=0;
		while(s[i][1][now]==s[i][2][now]){
			now++;
		}
		int f1=now;
		int pre=0;
		for(int j=now-1;j>=0;j--){
			pre=(1LL*pre*base+s[i][1][j])%mod;
		}
		if(!mp1.count(pre)){
			cnt1++;
			mp1[pre]=cnt1;
		}
		l[i]=mp1[pre];
		now=s[i][1].length()-1;
		while(s[i][1][now]==s[i][2][now]){
			now--;
		}
		int f2=now;
		pre=0;
		for(int j=now+1;j<=(int)s[i][1].length()-1;j++){
			pre=(1LL*pre*base+s[i][1][j])%mod;
		}
		if(!mp2.count(pre)){
			cnt2++;
			mp2[pre]=cnt2;
		}
		r[i]=mp2[pre];
		pre=0;
		for(int j=f1;j<=f2;j++){
			pre=(1LL*pre*base+s[i][1][j])%mod;
		}
		for(int j=f1;j<=f2;j++){
			pre=(1LL*pre*base+s[i][2][j])%mod;
		}
		if(!mp3.count(pre)){
			cnt3++;
			mp3[pre]=cnt3;
		}
		z[i]=mp3[pre];
		id[z[i]].pb(i);
	}
	for(int i=1;i<=cnt3;i++){
		for(auto x:id[i]){
			h1[i][l[x]].pb(x);
		}
		for(auto x:h1[i]){
			if(x.se.size()>=B){
				cnt++;
				to1[mk(x.fi,i)]=cnt;
			}
		}
		for(auto x:id[i]){
			h2[i][r[x]].pb(x);
		}
		for(auto x:h2[i]){
			if(x.se.size()>=B){
				cnt++;
				to2[mk(x.fi,i)]=cnt;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(to1[mk(l[i],z[i])]){
			g[to1[mk(l[i],z[i])]].flip(i);
		}
		if(to2[mk(r[i],z[i])]){
			g[to2[mk(r[i],z[i])]].flip(i);
		}
	}
	while(q--){
		s1=s2=s3;
		nl.clear();
		nr.clear();
		cin>>t[1]>>t[2];
		int now=0;
		while(t[1][now]==t[2][now]){
			now++;
		}
		int f1=now;
		int pre=0;
		if(mp1.count(0)){
			nl.pb(mp1[0]);
		}
		for(int j=now-1;j>=0;j--){
			pre=(1LL*pre*base+t[1][j])%mod;
			if(mp1.count(pre)){
				nl.pb(mp1[pre]);
			}
		}
		now=t[1].length()-1;
		while(t[1][now]==t[2][now]){
			now--;
		}
		int f2=now;
		pre=0;
		if(mp2.count(0)){
			nr.pb(mp2[0]);
		}
		for(int j=now+1;j<=(int)t[1].length()-1;j++){
			pre=(1LL*pre*base+t[1][j])%mod;
			if(mp2.count(pre)){
				nr.pb(mp2[pre]);
			}
		}
		pre=0;
		for(int j=f1;j<=f2;j++){
			pre=(1LL*pre*base+t[1][j])%mod;
		}
		for(int j=f1;j<=f2;j++){
			pre=(1LL*pre*base+t[2][j])%mod;
		}
		nz=mp3[pre];
		if(nz==0||nl.size()==0||nr.size()==0){
			cout<<0<<'\n';
			continue;
		}
		for(auto x:nl){
			if(h1[nz][x].size()<=B-1){
				for(auto p:h1[nz][x]){
					s1.flip(p);
				}
			}
			else{
				s1|=g[to1[mk(x,nz)]];
			}
		}
		for(auto x:nr){
			if(h2[nz][x].size()<=B-1){
				for(auto p:h2[nz][x]){
					s2.flip(p);
				}
			}
			else{
				s2|=g[to2[mk(x,nz)]];
			}
		}
		cout<<(s1&s2).count()<<'\n';
	}
	return 0;
}
