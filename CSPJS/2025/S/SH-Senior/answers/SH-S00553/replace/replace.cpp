#include<bits/stdc++.h>
using namespace std;
typedef int ll;
inline ll read(){
	ll c=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		c=(c<<1ll)+(c<<3ll)+(ch^48ll);
		ch=getchar();
	}
	return c*f;
}
inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
const ll N=5000009;
const ll B=27;
inline ll id(char c){
	if(c>='a'&&c<='z') return c-'a';
	return 26;
}
struct Trie{
	ll ch[27],ed,fail;
} tr[N];
ll val[N];
ll tot;
vector<ll> to[N];
#define ch(u,c) tr[u].ch[c]
#define fail(u) tr[u].fail
#define ed(u) tr[u].ed
void build(){
	queue<ll> q;
	for(ll i=0;i<B;i++){
		if(tr[0].ch[i]){
			q.push(tr[0].ch[i]);
		}
	}
	while(!q.empty()){
		ll u=q.front(); q.pop();
		for(ll i=0;i<B;i++){
			if(ch(u,i)) fail(ch(u,i))=ch(fail(u),i),q.push(ch(u,i));
			else ch(u,i)=ch(fail(u),i);
		}
	}
}
void dfs(ll u,ll fa){
	val[u]=ed(u)+val[fa];
	for(ll v:to[u]){
		if(v==fa) continue;
		dfs(v,u);
	}
}
string s;
inline void add(){
	ll u=0;
	for(ll i=0;i<s.size();i++){
		ll c=id(s[i]);
		if(!ch(u,c)) ch(u,c)=++tot;
		u=ch(u,c);
	}
	ed(u)++;
}
ll cur[N],tmp[N],pc,pt;
ll vst[N];
inline void query(ll iq){
	ll u=0;
	for(ll i=0;i<s.size();i++){
		ll c=id(s[i]);
		u=ch(u,c);
		vst[u]=1;
		cur[++pc]=u;
	}
}
ll n,nQ;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>nQ;
	for(ll i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		ll j=0;
		s="";
		for(;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				break;
			}
		}
		ll k=s1.size()-1;
		for(;k>=j;k--){
			if(s1[k]!=s2[k]){
				break;
			}
		}
		// j-k
		for(ll t=0;t<j;t++) s+=s1[t];
		s+="#";
		for(ll t=j;t<=k;t++){
			s+=s1[t];
		}
		for(ll t=j;t<=k;t++){
			s+=s2[t];
		}
		s+="#";
		for(ll t=k+1;t<s1.size();t++) s+=s1[t];
		add();
	}
	build();
	
	for(ll i=1;i<=tot;i++){
		to[fail(i)].emplace_back(i);
	}
	dfs(0,0);
//	ll aaa=0;
	for(ll iq=1;iq<=nQ;iq++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<"\n";
			continue;
		}
		
		ll j=0;
		s="";
		for(;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				break;
			}
		}
		ll k=s1.size()-1;
		for(;k>=j;k--){
			if(s1[k]!=s2[k]){
				break;
			}
		}
		// j-k
		for(ll t=0;t<j;t++) s+=s1[t];
		s+="#";
		for(ll t=j;t<=k;t++){
			s+=s1[t];
		}
		for(ll t=j;t<=k;t++){
			s+=s2[t];
		}
		s+="#";
		for(ll t=k+1;t<s1.size();t++) s+=s1[t];
		pc=0,pt=0;
		query(iq);
		ll ans=0;
		for(ll i=1;i<=pc;i++){
			ll u=cur[i];
			if(vst[u]==1){
				ll v=u;
				ans+=val[v];
				while(v){
					if(vst[v]==iq) break;
					vst[v]=iq;
//					tmp[++pt]=v;
					v=fail(v);
				}
			}
		}
		cout<<ans<<"\n";
//		for(ll u=1;u<=pt;u++){
//			vst[tmp[u]]=0;
//		}
	}
	return 0;
}

