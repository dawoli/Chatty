#include<bits/stdc++.h>
#define N 200001
#define L 5000001
#define BASE 131
using namespace std;
typedef int ll;
typedef unsigned long long ull;
bool be;
ll n,nQ,rt[N],nV,mx,re[N],nR,nH,rt2;
string s[N][2],t[N][2];
struct Trie{
	ll son[26],id;
} tr[2*L];
struct Node{
	ll hsh1,hsh2;
	bool operator<(const Node&x)const{
		return hsh1<x.hsh1||hsh1==x.hsh1&&hsh2<x.hsh2;
	}
} nqch[L];
map<Node,ll> pos[N],rid;
map<Node,ll>::iterator it;
map<Node,ll> ans;
bool ed;
void add2(ll &u,string str,ll id){
	if(!u) u=++nV;
	if(!tr[u].id) tr[u].id=++nH;
	if(id==-1) return;
	add2(tr[u].son[str[id]-'a'],str,id-1);
}
ll add(ll &u,string str,ll id,ll len,ll gid){
	if(!u) u=++nV;
	if(id==len) return 0;
	ll res=add(tr[u].son[str[id]-'a'],str,id+1,len,gid);
//	cout<<u<<"--"<<str[id]<<"->"<<tr[u].son[str[id]-'a']<<endl;
	if(gid==id) return tr[u].son[str[id]-'a'];
	return res;
}
void upd(ll u,string str,ll id,ll len,ll fr){
//	cout<<u<<" "<<len<<endl;
	if(!u) return;
//	cout<<"ed"<<endl;
	ans[(Node){u,fr}]++;
	if(id==len){
//		cout<<"ed2 "<<u<<" "<<fr<<endl;
		return;
	}
//	cout<<"ed"<<endl;
	upd(tr[u].son[str[id]-'a'],str,id+1,len,fr);
}
ll query(ll u,string str,ll id,ll len,ll fr){
	if(id==len) return ans[(Node){u,fr}];
	return query(tr[u].son[str[id]-'a'],str,id+1,len,fr)+ans[(Node){u,fr}];
}
void input(){
	cin>>n>>nQ;
	for(ll i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(ll i=1;i<=nQ;i++) cin>>t[i][0]>>t[i][1],mx=max(mx,ll(t[i][0].size()));
}
void solve(){
	for(ll i=1;i<=nQ;i++){
		if(t[i][0].size()!=t[i][1].size()) continue;
		ll l=-1,r=-1,len=t[i][0].size();
		for(ll j=0;j<len;j++){
			if(t[i][0][j]==t[i][1][j]) continue;
			if(l==-1) l=j;
			r=j;
		}
		add2(rt2,t[i][0],r);
		add2(rt2,t[i][1],r);
		ll u1=rt2,u2=rt2;
		for(ll j=r;j>=l;j--){
			u1=tr[u1].son[t[i][0][j]-'a'];
			u2=tr[u2].son[t[i][1][j]-'a'];
		}
		ll hshch1=tr[u1].id;
		ll hshch2=tr[u2].id;
		Node nowch=(Node){hshch1,hshch2};
//		if(hshch1==193874&&hshch2==193947) cout<<i<<" "<<l<<" "<<r<<" "<<hshch1<<" "<<hshch2<<endl;
		nqch[i]=nowch;
		it=rid.find(nowch);
		if(it==rid.end()) rid[nowch]=++nR;
		re[i]=r;
		ll ps=add(rt[0],t[i][0],0,len,r);
		for(ll j=l;j>=0;j--){
			if(j!=l){
				u1=tr[u1].son[t[i][0][j]-'a'];
				u2=tr[u2].son[t[i][1][j]-'a'];
			}	
			ll hshn1=tr[u1].id;
			ll hshn2=tr[u2].id;
			Node now=(Node){hshn1,hshn2};
//			if(i==101||rid[nowch]==101) cout<<i<<" "<<rid[nowch]<<" "<<j<<" "<<r<<" "<<hshn1<<" "<<hshn2<<" "<<ps<<endl;
			pos[rid[nowch]][now]=ps;
		}
//		if(i==101) cout<<i<<" "<<pos[rid[nqch[i]]][nqch[i]]<<endl;
	}
	for(ll i=1;i<=n;i++){
		ll l=-1,r=-1,len=s[i][0].size();
		for(ll j=0;j<len;j++){
			if(s[i][0][j]==s[i][1][j]) continue;
			if(l==-1) l=j;
			r=j;
		}
		ll u1=rt2,u2=rt2;
		for(ll j=r;j>=l;j--){
			u1=tr[u1].son[s[i][0][j]-'a'];
			u2=tr[u2].son[s[i][1][j]-'a'];
		}
		ll hshch1=tr[u1].id;
		ll hshch2=tr[u2].id;
		Node nowch=(Node){hshch1,hshch2};
//		if(hshch1==193874&&hshch2==193947)
//			cout<<i<<" "<<l<<" "<<r<<" "<<hshch1<<" "<<hshch2<<endl;
		it=rid.find(nowch);
		if(it==rid.end()) continue;
		for(ll j=l-1;j>=0;j--){
			u1=tr[u1].son[s[i][0][j]-'a'];
			u2=tr[u2].son[s[i][1][j]-'a'];
		}
		ll hshn1=tr[u1].id;
		ll hshn2=tr[u2].id;
		Node now=(Node){hshn1,hshn2};
		it=pos[rid[nowch]].find(now);
		if(it==pos[rid[nowch]].end()) continue;
//		if(hshch1==193874&&hshch2==193947)
//			cout<<i<<" "<<rid[nowch]<<" "<<hshn1<<" "<<hshn2<<" "<<(it->second)<<" "<<(it->first).hsh1<<" "<<(it->first).hsh2<<endl;
		upd(it->second,s[i][0],r+1,len,it->second);
	}
	for(ll i=1;i<=nQ;i++)
		if(t[i][0].size()!=t[i][1].size()) cout<<-1<<endl;
		else cout<<query(rt[0],t[i][0],0,t[i][0].size(),pos[rid[nqch[i]]][nqch[i]])<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	input();
	solve();
	return 0;
}

