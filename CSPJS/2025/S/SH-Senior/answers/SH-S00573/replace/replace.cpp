#include<bits/stdc++.h>
#define N 200005
#define S 5000005
#define ll long long
using namespace std;
int n,q,trie[S][26],ans[N],THS;
int sln[N],tln[N];
int spl[N],spr[N],tpl[N],tpr[N];
int sxi[N],syi[N],tx[N],ty[N],xl[N],xr[N],yl[N],yr[N];
int tot=1,timer,tI[S],tO[S];
string s[N][2],t[N][2];
map<tuple<ll,ll,ll>,int> mp;
vector<int> SID[N],TID[N],sid,tid,to[S];
tuple<ll,ll,ll> hs(string &str1,string &str2,int l,int r){
	ll rA=0,rB=0,rC=0;
	ll PA=131,PB=13331,PC=37;
	ll MA=998244353,MB=1000000007,MC=1000000009;
	for(int i=l;i<=r;i++){
		rA=(rA*PA+str1[i])%MA;
		if(str1[i]!=str2[i]){
			rA=(rA*PA+str2[i])%MA;
		}
	}
	for(int i=l;i<=r;i++){
		rB=(rB*PB+str1[i])%MB;
		if(str1[i]!=str2[i]){
			rB=(rB*PB+str2[i])%MB;
		}
	}
	for(int i=l;i<=r;i++){
		rC=(rC*PC+str1[i])%MC;
		if(str1[i]!=str2[i]){
			rC=(rC*PC+str2[i])%MC;
		}
	}
	return make_tuple(rA,rB,rC);
}
struct point{int x,y,w;};
bool operator<(const point &pp,const point &qq){
	return make_tuple(pp.x,pp.y,-pp.w)<make_tuple(qq.x,qq.y,-qq.w);
}
int tps;
int ist(string str){
	int nw=1;
	for(char ch:str){
		int dir=ch-'a';
		if(!trie[nw][dir]){
			trie[nw][dir]=++tot;
			to[nw].push_back(dir);
		}
		nw=trie[nw][dir];
	}
	return nw;
}
int qry(string str){
	int nw=1;
	for(char ch:str){
		int dir=ch-'a';
		if(!trie[nw][dir]){
			return nw;
		}
		nw=trie[nw][dir];
	}
	return nw;
}
void dfs(int u){
	tI[u]=++timer;
	for(int v:to[u]){
		dfs(trie[u][v]);
	}
	tO[u]=timer;
}
void solvex(){
	for(int i:sid){
		if(spl[i]){
			auto tmp=s[i][0].substr(0,spl[i]);
			reverse(tmp.begin(),tmp.end());
			sxi[i]=ist(tmp);
		}
		else{
			sxi[i]=1;
		}
	}
	dfs(1);
	for(int i:sid){
		xl[i]=tI[sxi[i]];
		xr[i]=tO[sxi[i]];
	}
	for(int i:tid){
		if(tpl[i]){
			auto tmp=t[i][0].substr(0,tpl[i]);
			reverse(tmp.begin(),tmp.end());
			tx[i]=tI[qry(tmp)];
		}
		else{
			tx[i]=tI[1];
		}
	}
}
void solvey(){
	for(int i:sid){
		if(spr[i]+1<sln[i]){
			auto tmp=s[i][0].substr(spr[i]+1,sln[i]-spr[i]-1);
			syi[i]=ist(tmp);
		}
		else{
			syi[i]=1;
		}
	}
	dfs(1);
	for(int i:sid){
		yl[i]=tI[syi[i]];
		yr[i]=tO[syi[i]];
	}
	for(int i:tid){
		if(tpr[i]+1<tln[i]){
			auto tmp=t[i][0].substr(tpr[i]+1,tln[i]-tpr[i]-1);
			ty[i]=tI[qry(tmp)];
		}
		else{
			ty[i]=tI[1];
		}
	}
}
void clr(){
	for(int u=1;u<=tot;u++){
		tI[u]=tO[u]=0;
		for(int v:to[u]){
			trie[u][v]=0;
		}
		to[u].clear();
	}
	timer=0;tot=1;
}
int bit[S];
void ud(int x,int w){
	while(x<=tot){
		bit[x]+=w;
		x+=x&-x;
	}
}
int qy(int x){
	int res=0;
	while(x){
		res+=bit[x];
		x-=x&-x;
	}
	return res;
}
void solve(){
	if(!sid.size()||!tid.size())return;
	clr();
	solvex();
	clr();
	solvey();
	vector<point> ps;
	for(int i:sid){
		ps.push_back((point){xl[i],yl[i],1});
		ps.push_back((point){xl[i],yr[i]+1,0});
		ps.push_back((point){xr[i]+1,yl[i],0});
		ps.push_back((point){xr[i]+1,yr[i]+1,1});
	}
	for(int i:tid){
		ps.push_back((point){tx[i],ty[i],-i});
	}
	stable_sort(ps.begin(),ps.end());
	for(auto p:ps){
		if(p.w>=0){
			ud(p.y,p.w*2-1);
		}
		else{
			ans[-p.w]+=qy(p.y);
		}
	}
	for(int i=1;i<=tot;i++){
		bit[i]=0;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		if(s[i][0]==s[i][1])continue;
		sln[i]=(int)s[i][0].size();
		for(int j=0;j<sln[i];j++){
			if(s[i][0][j]!=s[i][1][j]){
				spr[i]=j;
			}
		}
		for(int j=sln[i]-1;j>=0;j--){
			if(s[i][0][j]!=s[i][1][j]){
				spl[i]=j;
			}
		}
		auto v=hs(s[i][0],s[i][1],spl[i],spr[i]);
		if(mp.find(v)==mp.end()){
			mp[v]=++THS;
		}
		SID[mp[v]].push_back(i);
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		if(t[i][0].size()!=t[i][1].size())continue;
		tln[i]=(int)t[i][0].size();
		for(int j=0;j<tln[i];j++){
			if(t[i][0][j]!=t[i][1][j]){
				tpr[i]=j;
			}
		}
		for(int j=tln[i]-1;j>=0;j--){
			if(t[i][0][j]!=t[i][1][j]){
				tpl[i]=j;
			}
		}
		auto v=hs(t[i][0],t[i][1],tpl[i],tpr[i]);
		if(mp.find(v)!=mp.end()){
			TID[mp[v]].push_back(i);
		}
	}
	for(int _=1;_<=THS;_++){
		sid=SID[_];
		tid=TID[_];
		solve();
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
