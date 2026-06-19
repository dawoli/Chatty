#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) x&-x
int n,q,tot=1,idx,modtot;
int tree[10000010][26];
int L[10000010],R[10000010];
int nowpos[200010][2];
int bit[10000010];
int cntl[200010],cntr[200010];
string a[2];
struct node {
	int len,modpos,posl,posr,num,id;
} op[1500010];
int ans[200010];
bool cmp(node x,node y) {
	if(x.len==y.len) {
		if(x.modpos==y.modpos) {
			return x.posr>y.posr;
		}
		return x.modpos<y.modpos;
	}
	return x.len<y.len; 
}
void add(int x,int l,int r,int id,bool rev) {
	int pos=1;
	if(rev) {
		for(int i=r; i>=l; i--) {
			//cout<<a[x][i]<<"rev"<<endl;
			if(!tree[pos][a[x][i]-'a']) {
				//cerr<<pos<<"pospos"<<endl;
				tree[pos][a[x][i]-'a']=++tot;
			}
			pos=tree[pos][a[x][i]-'a'];
		}
	} else {
		for(int i=l; i<=r; i++) {
			//cout<<a[x][i]<<"irev"<<endl;
			if(!tree[pos][a[x][i]-'a']) {
				tree[pos][a[x][i]-'a']=++tot;
			}
			pos=tree[pos][a[x][i]-'a'];
		}
	}
	nowpos[id][x]=pos;
}
int ask(int x,int l,int r,bool rev) {
	int pos=1;
	if(rev) {
		for(int i=r; i>=l; i--) {
			if(!tree[pos][a[x][i]-'a']) {
				return pos;
			}
			pos=tree[pos][a[x][i]-'a'];
		}
	} else {
		for(int i=l; i<=r; i++) {
			if(!tree[pos][a[x][i]-'a']) {
				return pos;
			}
			pos=tree[pos][a[x][i]-'a'];
		}
	}
	return pos;
}
void dfs(int x) {
	L[x]=++idx;
//	cerr<<x<<" "<<L[x]<<endl;
	for(int i=0; i<26; i++) {
		if(tree[x][i]==0) continue;
		//cout<<x<<" "<<tree[x][i]<<" "<<i<<"tree"<<endl;
		dfs(tree[x][i]);
	}
	R[x]=idx;
//	if(L[x]==0||R[x]==0) cerr<<x<<endl;
}
void addbit(int x,int y) {
	while(x<=idx) {
		bit[x]+=y;
		x+=lowbit(x);
	}
}
int query(int x) {
	int res=0;
	while(x>0) {
		res+=bit[x];
		x-=lowbit(x);
	}
	return res;
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>a[0]>>a[1];
		int nowl=0,nowr=a[0].size()-1;
		while(nowl<a[0].size()&&a[0][nowl]==a[1][nowl]) nowl++;
		while(nowr>=0&&a[0][nowr]==a[1][nowr]) nowr--;
		if(nowr<nowl) continue;
		add(0,0,nowr,i,1);
		add(1,nowl,a[0].size()-1,i,0);
		cntl[i]=nowl,cntr[i]=nowr;
//		if(nowpos[i][1]==0){
//			cerr<<"ccccc"<<endl;
//			cerr<<i<<" "<<nowl<<" "<<a[0].size()-1<<endl;
//		}
	}
	//cerr<<tot<<"tot"<<endl;
	dfs(1);
	//cerr<<"aaaa"<<endl;
	for(int i=1; i<=n; i++) {
		if(nowpos[i][1]==0) continue;
		//cerr<<i<<" "<<nowpos[i][0]<<" "<<nowpos[i][1]<<endl;
		//if(L[nowpos[i][1]]==0||R[nowpos[i][1]]==0) cerr<<nowpos[i][1]<<endl;
		op[++modtot]= {cntr[i]-cntl[i]+1,L[nowpos[i][0]],L[nowpos[i][1]],R[nowpos[i][1]],1,0};
		op[++modtot]= {cntr[i]-cntl[i]+1,R[nowpos[i][0]]+1,L[nowpos[i][1]],R[nowpos[i][1]],-1,0};
	}
	for(int i=1; i<=q; i++) {
		cin>>a[0]>>a[1];
		int nowl=0,nowr=a[0].size()-1;
		while(nowl<a[0].size()&&a[0][nowl]==a[1][nowl]) nowl++;
		while(nowr>=0&&a[0][nowr]==a[1][nowr]) nowr--;
		int nowposa1=ask(0,0,nowr,1),nowposa2=ask(0,nowl+1,nowr,1);
		int nowposb1=ask(1,nowl,a[0].size()-1,0),nowposb2=ask(1,nowl,nowr-1,0);
		//cout<<nowposa1<<" "<<nowposa2<<" "<<nowposb1<<" "<<nowposb2<<endl;
		op[++modtot]= {nowr-nowl+1,L[nowposa1],L[nowposb1],0,1,i};
		op[++modtot]= {nowr-nowl+1,L[nowposa1],L[nowposb2],0,-1,i};
		op[++modtot]= {nowr-nowl+1,L[nowposa2],L[nowposb1],0,-1,i};
		op[++modtot]= {nowr-nowl+1,L[nowposa2],L[nowposb2],0,1,i};
	}
	sort(op+1,op+1+modtot,cmp);
	for(int i=1; i<=modtot; i++) {
//		cerr<<i<<endl;
		//cerr<<i<<" "<<op[i].posl<<" "<<op[i].posr<<" "<<op[i].id<<endl;
		if(op[i].id==0) {
			addbit(op[i].posl,op[i].num);
			addbit(op[i].posr+1,-op[i].num);
		} else {
			ans[op[i].id]+=op[i].num*query(op[i].posl);
		}
	}
	for(int i=1; i<=q; i++) {
		cout<<ans[i]<<'\n';
	}
}
/*
2 1
aab baa
aaaaabaa aaaabaaa
aaaaaaaaaaaaba aaaaaaaaaabaaa
*/
