#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int T,n,k,q,l[N],v,r,c,sl;
vector<int> son[N];
bool flag23=false,flagB;
/*
void solve1(){
	for(int i=1;i<=n;i++){
		int id=0;
		for(int u=0;u<l[i];u++){
			int v=son[i][u];
			if(v!=1) continue;
			for(id=u+1;id<=min(l[i]-1,u+k-1);id++){
				if(u==id) continue;
				if(son[i][id]==c){
					cout<<1<<endl;
					return;
				}
			}
		}
	}
	cout<<0<<endl;
}
void dfs23(int id,int hd,int pre){
	if(id<r){
		if(flag23==true) return;
		set<int> s; s.clear();
		map<int,int> m; m.clear();
		for(int i=1;i<=n;i++){
			if(i==pre) continue;
			for(int u=0;u<l[i];u++) if(son[i][u]==hd)
				for(int v=u+1;v<=min(l[i]-1,u+k-1);v++){
					s.insert(son[i][v]);
					if(m[son[i][v]]==0) m[son[i][v]]=i;
					else m[son[i][v]]=-1;
				}
		}
		set<int>::iterator it;
		for(it=s.begin();it!=s.end();it++){
			int nw=*it;
			dfs23(id+1,nw,m[nw]);
		}
	}else if(id==r){
		if(flag23==true) return;
		for(int i=1;i<=n;i++){
			if(i==pre) continue;
			for(int u=0;u<l[i];u++) if(son[i][u]==hd)
				for(int v=u+1;v<=min(l[i]-1,u+k-1);v++) if(son[i][v]==c){
					cout<<1<<endl; flag23=true; return;
				}
		}
	}
}
void solve23(){
	flag23=false;
	dfs23(1,1,-1);
	if(flag23==false) cout<<0<<endl;
}
*/
void dfsB(int id,int hd,int pre){
	if(id<r){
		if(flagB==true) return;
		set<int> s; s.clear();
		map<int,int> m; m.clear();
		for(int i=1;i<=n;i++){
			if(i==pre) continue;
			for(int u=0;u<l[i];u++) if(son[i][u]==hd)
				for(int v=u+1;v<=min(l[i]-1,u+k-1);v++){
					s.insert(son[i][v]);
					if(m[son[i][v]]==0) m[son[i][v]]=i;
					else m[son[i][v]]=-1;
				}
		}
		set<int>::iterator it;
		for(it=s.begin();it!=s.end();it++){
			int nw=*it;
			dfsB(id+1,nw,m[nw]);
		}
	}else if(id==r){
		if(flagB==true) return;
		for(int i=1;i<=n;i++){
			if(i==pre) continue;
			for(int u=0;u<l[i];u++) if(son[i][u]==hd)
				for(int v=u+1;v<=min(l[i]-1,u+k-1);v++) if(son[i][v]==c){
					cout<<1<<endl; flagB=true; return;
				}
		}
	}
}
void solveB(){
	flagB=false;
	dfsB(1,1,-1);
	if(flagB==false) cout<<0<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i]; sl+=l[i];
			for(int u=0;u<l[i];u++){
				cin>>v;
				son[i].push_back(v);
			}
		}
		while(q--){
			cin>>r>>c;
			solveB();
		}
	}
	return 0;
}

