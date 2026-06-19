#include<bits/stdc++.h>

using namespace std;

ifstream fin("replace.in");
ofstream fout("replace.out");
#define cin fin
#define cout fout
#define endl '\n'

using ll=long long;
using bint=__int128;
const ll mod=114514191981000001ll;
const int N=2e5+9;
const int L=5e6+9;
inline void AddAs(ll &x,ll y){if((x+=y)>=mod) x-=mod;}
inline void SubAs(ll &x,ll y){if((x-=y)<0) x+=mod;}
inline void MulAs(ll &x,ll y){x=bint(x)*y%mod;}
inline ll Add(ll x,ll y){if((x+=y)>=mod) x-=mod;return x;}
inline ll Sub(ll x,ll y){if((x-=y)<0) x+=mod;return x;}
inline ll Mul(ll x,ll y){return bint(x)*y%mod;}
inline ll QPow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1) MulAs(res,x);
		MulAs(x,x);
		y>>=1;
	}
	return res;
}
inline ll Inv(ll x){return QPow(x,mod-2);}

ll b[L],ib[L];
inline void InitBase(int lim){
	b[0]=ib[0]=1;
	ll base=4649,ibase=Inv(base);
	for(int i=1;i<=lim;i++){
		b[i]=Mul(b[i-1],base);
		ib[i]=Mul(ib[i-1],ibase);
	}
}
inline ll Hash(string s){
	ll res=0;
	for(int i=0;i<s.size();i++) AddAs(res,Mul(b[i],s[i]));
	return res;
}

int spre[N],ssuc[N],tpre[N],tsuc[N],ans[N],n,m;
string s1[N],s2[N],t1[N],t2[N],sl[N],tl[N];
ll sh[N],th[N];

int tot;
vector<int> str[N],ttr[N];
map<ll,int> mp;

inline int P(char c){return c=='#'?26:c-'a';}
struct Node{
	int son[27],fail,siz;
}tr[L];

int root,cnt;
inline void Init(){cnt=root=0;}
inline void Insert(string &s){
	int x=root;
	for(char c:s){
		if(!tr[x].son[P(c)]) tr[x].son[P(c)]=++cnt;
		x=tr[x].son[P(c)];
	}
	tr[x].siz++;
}
inline void GetFail(){
	queue<int> q;
	for(int i=0;i<27;i++){
		if(!tr[root].son[i]) continue ;
		tr[tr[root].son[i]].fail=root;
		q.push(tr[root].son[i]);
	}
	while(q.size()){
		int x=q.front();
		q.pop();
		tr[x].siz+=tr[tr[x].fail].siz;
		for(int i=0;i<27;i++){
			if(tr[x].son[i]){
				tr[tr[x].son[i]].fail=tr[tr[x].fail].son[i];
				q.push(tr[x].son[i]);
			}else tr[x].son[i]=tr[tr[x].fail].son[i];
		}
	}
}
inline int Query(string &s){
	int x=root,ans=tr[x].siz;
	for(char c:s){
		x=tr[x].son[P(c)];
		ans+=tr[x].siz;
	}
	return ans;
}
inline void Clear(){
	for(int i=0;i<=cnt;i++){
		for(int j=0;j<27;j++) tr[i].son[j]=0;
		tr[i].siz=tr[i].fail=0;
	}
	cnt=0;
}

signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=m;i++) cin>>t1[i]>>t2[i];

	InitBase(5e6);
	for(int i=1;i<=n;i++){
		if(s1[i]==s2[i]) continue ;
		int len=s1[i].size();
		while(spre[i]<len&&s1[i][spre[i]]==s2[i][spre[i]]) spre[i]++;
		while(ssuc[i]<len&&s1[i][len-ssuc[i]-1]==s2[i][len-ssuc[i]-1]) ssuc[i]++;
		int slen=len-spre[i]-ssuc[i];
		sh[i]=Hash(s1[i].substr(spre[i],slen)+s2[i].substr(spre[i],slen));
		if(!mp[sh[i]]) mp[sh[i]]=++tot;
		str[mp[sh[i]]].push_back(i);
		for(int j=0;j<len;j++) if(j<spre[i]) sl[i].push_back(s1[i][j]);
		sl[i].push_back('#');
		for(int j=0;j<len;j++) if(j+ssuc[i]>len-1) sl[i].push_back(s1[i][j]);
	}
	for(int i=1;i<=m;i++){
		if(t1[i].size()!=t2[i].size()) continue ;
		int len=t1[i].size();
		while(tpre[i]<len&&t1[i][tpre[i]]==t2[i][tpre[i]]) tpre[i]++;
		while(tsuc[i]<len&&t1[i][len-tsuc[i]-1]==t2[i][len-tsuc[i]-1]) tsuc[i]++;
		int tlen=len-tpre[i]-tsuc[i];
		th[i]=Hash(t1[i].substr(tpre[i],tlen)+t2[i].substr(tpre[i],tlen));
		if(!mp[th[i]]) mp[th[i]]=++tot;
		ttr[mp[th[i]]].push_back(i);
		for(int j=0;j<len;j++) if(j<tpre[i]) tl[i].push_back(t1[i][j]);
		tl[i].push_back('#');
		for(int j=0;j<len;j++) if(j+tsuc[i]>len-1) tl[i].push_back(t1[i][j]);
	}

	for(int i=1;i<=tot;i++){
		Init();
		for(int j:str[i]) Insert(sl[j]);
		cout.flush();
		GetFail();
		for(int j:ttr[i]) ans[j]=Query(tl[j]);
		Clear();
	}

	for(int i=1;i<=m;i++) cout<<ans[i]<<endl;

	return 0;
}