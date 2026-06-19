#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=200007,M=5000007,K=600007,B=131,MOD1=1e9+7,MOD2=1e9+9;
struct myhash{
	ll h1,h2;
	myhash(){h1=h2=0;}
	void append(char c){
		h1=(h1*B+c)%MOD1;
		h2=(h2*B+c)%MOD2;
	}
	ll get(){
		return h1*MOD2+h2;
	}
};
int n,m,k,nC,rt1[N],rt2[N],p1[N],p2[N],q1[N],q2[N],ooo[N],ok[N],ans[N],_[K];
map<pair<ll,ll>,int> mp;
char s[M],t[M];
struct operation{
	int type,x,y,val;
}op[N*5];
bool cmp(const operation& a,const operation& b){
	return (a.x==b.x?a.type<b.type:a.x<b.x);
}
int getprefix(){
	for (int i=1;i<=k;++i){
		if (s[i]!=t[i]){
			return i;
		}
	}
	return k+1;
}
int getsuffix(){
	for (int i=k;i;--i){
		if (s[i]!=t[i]){
			return i;
		}
	}
	return 0;
}
namespace A{
	struct Trie{
		int nV,to[M][26],tI[M],tO[M],timer;
		bool vis[M];
		int go(int u,char c){
			if (!to[u][c-'a']){
				return to[u][c-'a']=++nV;
			}
			return to[u][c-'a'];
		}
		bool go2(int& u,char c){
			if (!to[u][c-'a']) return 0;
			u=to[u][c-'a'];
			return 1;
		}
		void dfs(int u){
			tI[u]=++timer;
			for (int i=0;i<26;++i){
				if (to[u][i]) dfs(to[u][i]);
			}
			tO[u]=timer;
		}
		void solve(){
			for (int i=1;i<=nV;++i){
				if (vis[i]) dfs(i);
			}
		}
	}L,R;
	void add(int id,int l,int r){
		myhash H1,H2;
		for (int i=l;i<=r;++i){
			H1.append(s[i]);H2.append(t[i]);
		}
		ll h1=H1.get(),h2=H2.get();
		if (mp.find(make_pair(h1,h2))==mp.end()){
			mp[make_pair(h1,h2)]=++nC;
			rt1[nC]=++L.nV;
			L.vis[L.nV]=1;
			rt2[nC]=++R.nV;
			R.vis[R.nV]=1;
		}
		int c=mp[make_pair(h1,h2)];
		int u=rt1[c];
		for (int i=l-1;i;--i){
			u=L.go(u,s[i]);
		}
		p1[id]=u;
		u=rt2[c];
		for (int i=r+1;i<=k;++i){
			u=R.go(u,s[i]);
		}
		p2[id]=u;
	} 
	void query(int id,int l,int r){
		myhash H1,H2;
		for (int i=l;i<=r;++i){
			H1.append(s[i]);H2.append(t[i]);
		}
		ll h1=H1.get(),h2=H2.get();
		if (mp.find(make_pair(h1,h2))==mp.end()) return;
		int c=mp[make_pair(h1,h2)];
		ok[id]=1;
		int u=rt1[c];
		for (int i=l-1;i;--i){
			if (!L.go2(u,s[i])) break;
		}
		q1[id]=L.tI[u];
		u=rt2[c];
		for (int i=r+1;i<=k;++i){
			if (!R.go2(u,s[i])) break;
		}
		q2[id]=R.tI[u];
	}
}
namespace BIT{
	int cnt[K];
	void add(int x,int v){
		while(x<=nC){
			cnt[x]+=v;x+=x&-x;
		}
	}
	int query(int x){
		int s=0;
		while(x){
			s+=cnt[x];x&=x-1;
		}
		return s;
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for (int x=1;x<=n;++x){
		cin>>(s+1)>>(t+1);
		k=strlen(s+1);
		int L=getprefix(),R=getsuffix();
		if (L>k){
			ooo[x]=1;
			continue;
//			ACAM::add();
		}
		else{
			A::add(x,L,R);
		}
	}
	A::L.solve();
	A::R.solve();
//	ACAM::getfail();
	for (int x=1;x<=m;++x){
		cin>>(s+1)>>(t+1);
		k=strlen(s+1);
		if (strlen(t+1)!=k){
			continue;
		}
		int L=getprefix(),R=getsuffix();
		if (L>k) continue;
		A::query(x,L,R);
	}
	k=nC=0;
	for (int i=1;i<=n;++i){
		if (ooo[i]) continue;
		int l1=A::L.tI[p1[i]],r1=A::L.tO[p1[i]],l2=A::R.tI[p2[i]],r2=A::R.tO[p2[i]];
		op[++k]={0,l1,l2,1};
		op[++k]={0,l1,r2+1,-1};
		op[++k]={0,r1+1,l2,-1};
		op[++k]={0,r1+1,r2+1,1};
		_[++nC]=l2;_[++nC]=r2+1;
	}
	for (int i=1;i<=m;++i){
		if (!ok[i]) continue;
		op[++k]={1,q1[i],q2[i],i};
		_[++nC]=q2[i];
	}
	sort(_+1,_+1+nC);nC=unique(_+1,_+1+nC)-_-1;
	for (int i=1;i<=k;++i){
		op[i].y=lower_bound(_+1,_+1+nC,op[i].y)-_;
	}
	sort(op+1,op+1+k,cmp);
	for (int i=1;i<=k;++i){
		if (op[i].type==0) BIT::add(op[i].y,op[i].val);
		else ans[op[i].val]=BIT::query(op[i].y);
	}
	for (int i=1;i<=m;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
//namespace ACAM{
//	int nV=1,to[M][26],cnt[M],fail[M];
//	queue<int> q;
//	void add(){
//		int u=1;
//		for (int i=1;i<=k;++i){
//			if (!to[u][s[i]-'a']){
//				to[u][s[i]-'a']=++nV;
//			}
//			u=to[u][s[i]-'a'];
//		}
//		++cnt[u];
//	}
//	void getfail(){
//		for (int i=0;i<26;++i) to[0][i]=1;
//		q.push(1);
//		while(!q.empty()){
//			int u=q.front();q.pop();
//			cnt[u]+=cnt[fail[u]];
//			for (int i=0;i<26;++i){
//				if (to[u][i]){
//					fail[to[u][i]]=to[fail[u]][i];
//					q.push(to[u][i]);
//				}
//				else to[u][i]=to[fail[u]][i];
//			}
//		}
//	}
//}
