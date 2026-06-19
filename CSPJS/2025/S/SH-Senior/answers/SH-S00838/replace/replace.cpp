#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define repn(i,n) for(int i=0;i<(n);++i)
#define fir first
#define sec second

constexpr int N = 2e5+5 , M = 3e6;
constexpr ull mod = (1ull<<61)-1, base = 1145141;
ull Madd(ull x,ull y){return x+y<mod?x+y:x+y-mod;}
ull Mmul(ull x,ull y){return Madd(x*y&mod,(__uint128_t)x*y>>61);}

int n,q;
unordered_map<ull,int> mp;

int tot1,tot2;

int tr1[M][26],rt[M],tr2[M][26],cnt[M];

void mg(int x,int &y){
	if(!x)return;
	if(!y){y=x;return;}
	cnt[y]+=cnt[x];
	repn(i,26)mg(tr2[x][i],tr2[y][i]);
}
void dfs(int x){
	repn(i,26)if(tr1[x][i]){
		int y=tr1[x][i];
		mg(rt[x],rt[y]);
		dfs(y);
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>q;
	rep(i,1,n){
		string s,t;cin>>s>>t;
		int len=s.size();
		int l=-1,r=-1;repn(j,len){
			if(s[j]!=t[j]){
				if(l==-1)l=j;
				r=j;
			}
		}
		if(l==-1)continue;
		ull h=0;
		rep(j,l,r)h=Madd(Mmul(h,base),s[j]);
		h=Madd(Mmul(h,base),'#');
		rep(j,l,r)h=Madd(Mmul(h,base),t[j]);
		if(!mp.count(h))mp[h]=++tot1;
		int x=mp[h];per(i,l-1,0){
			int k=s[i]-'a';
			if(!tr1[x][k])tr1[x][k]=++tot1;
			x=tr1[x][k];
		}
		if(!rt[x])rt[x]=++tot2;
		int y=rt[x];rep(i,r+1,len-1){
			int k=s[i]-'a';
			if(!tr2[y][k])tr2[y][k]=++tot2;
			y=tr2[y][k];
		}
		++cnt[y];
	}
	for(auto i:mp)dfs(i.sec);
	while(q--){
		string s,t;cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<"0\n";
			continue;
		}
		int len=s.size();
		int l=-1,r=-1;repn(j,len){
			if(s[j]!=t[j]){
				if(l==-1)l=j;
				r=j;
			}
		}
		assert(l!=-1);
		ull h=0;
		rep(j,l,r)h=Madd(Mmul(h,base),s[j]);
		h=Madd(Mmul(h,base),'#');
		rep(j,l,r)h=Madd(Mmul(h,base),t[j]);
		if(!mp.count(h)){
			cout<<"0\n";
			continue;
		}
		int x=mp[h];per(i,l-1,0){
			int k=s[i]-'a';
			if(!tr1[x][k])break;
			x=tr1[x][k];
		}
		if(!rt[x]){
			cout<<"0\n";
			continue;
		}
		int y=rt[x];int ans=cnt[y];rep(i,r+1,len-1){
			int k=s[i]-'a';
			if(!tr2[y][k])break;
			y=tr2[y][k];
			ans+=cnt[y];
		}
		cout<<ans<<'\n';
	}
} 
