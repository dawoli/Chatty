#include<bits/stdc++.h>
#define ulglg unsigned long long
using namespace std;

int mito[200005];

int n,q,trie[6000005][27],pt1,mrk[6000005],pt2;
vector<int>AV[200005],QV[200005];
int trie2[5000005][26],pt3,dfn[5000005],amt[5000005],tr[5000005],pt4;
ulglg btm[5000005];
vector<int>OP[5000005];vector<pair<int,int> >OQ[5000005];
string aas[200005],aat[200005];int lsh[200005];
string qs[200005],qt[200005];int ans[200005];

void dfs(int x){
	dfn[x]=++pt4;amt[x]=1;ulglg cr=btm[x];
	while(cr){
		int c=mito[(cr&-cr)%100003];cr&=(cr-1);
		dfs(trie2[x][c]);amt[x]+=amt[trie2[x][c]];
	}
}

void addbit(int x,int v){
	for(;x<=pt4;x+=(x&-x))tr[x]+=v;
}

int querybit(int x){
	int ca=0;for(;x;x&=(x-1))ca+=tr[x];
	return ca;
}

void dfsEX(int x){
	for(auto uu:OP[x]){addbit(dfn[uu],1);addbit(dfn[uu]+amt[uu],-1);}
	for(auto uu:OQ[x])ans[uu.second]+=querybit(dfn[uu.first]);
	ulglg cr=btm[x];
	while(cr){
		int c=mito[(cr&-cr)%100003];cr&=(cr-1);
		dfsEX(trie2[x][c]);
	}
	for(auto uu:OP[x]){addbit(dfn[uu],-1);addbit(dfn[uu]+amt[uu],1);}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=0;i<26;i++)mito[(1ll<<i)%100003]=i;
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t;cin>>s>>t;
		if(s==t)continue;
		int lb=0,rb=s.size();
		while(lb<s.size()&&s[lb]==t[lb])lb++;
		while(rb>0&&s[rb-1]==t[rb-1])rb--;
		int x=0;
		for(int j=lb;j<rb;j++){
			if(!trie[x][s[j]-'a'])trie[x][s[j]-'a']=++pt1;
			x=trie[x][s[j]-'a'];
		}
		if(!trie[x][26])trie[x][26]=++pt1;
		x=trie[x][26];
		for(int j=lb;j<rb;j++){
			if(!trie[x][t[j]-'a'])trie[x][t[j]-'a']=++pt1;
			x=trie[x][t[j]-'a'];
		}
		if(!mrk[x])mrk[x]=++pt2;
		lsh[i]=mrk[x];AV[mrk[x]].push_back(i);
		for(int j=lb-1;j>=0;j--)aas[i]+=s[j];
		for(int j=rb;j<s.size();j++)aat[i]+=s[j];
	}
	for(int i=1;i<=q;i++){
		string s,t;cin>>s>>t;
		if(s.size()!=t.size())continue;
		int lb=0,rb=s.size();
		while(lb<s.size()&&s[lb]==t[lb])lb++;
		while(rb>0&&s[rb-1]==t[rb-1])rb--;
		int x=0;
		for(int j=lb;j<rb;j++)x=trie[x][s[j]-'a'];
		x=trie[x][26];
		for(int j=lb;j<rb;j++)x=trie[x][t[j]-'a'];
		if(!mrk[x])continue;
		QV[mrk[x]].push_back(i);
		for(int j=lb-1;j>=0;j--)qs[i]+=s[j];
		for(int j=rb;j<s.size();j++)qt[i]+=s[j];
	}
	for(int i=1;i<=pt2;i++){
		pt3=1;
		for(auto uu:AV[i]){
			int x=0,y=1;
			for(int o=0;o<aas[uu].size();o++){
				if(!trie2[x][aas[uu][o]-'a']){
					btm[x]|=(1ll<<(aas[uu][o]-'a'));
					trie2[x][aas[uu][o]-'a']=++pt3;
				}
				x=trie2[x][aas[uu][o]-'a'];
			}
			for(int o=0;o<aat[uu].size();o++){
				if(!trie2[y][aat[uu][o]-'a']){
					btm[y]|=(1ll<<(aat[uu][o]-'a'));
					trie2[y][aat[uu][o]-'a']=++pt3;
				}
				y=trie2[y][aat[uu][o]-'a'];
			}
			OP[x].push_back(y);
		}
		for(auto uu:QV[i]){
			int x=0,y=1;
			for(int o=0;o<qs[uu].size();o++){
				if(!trie2[x][qs[uu][o]-'a']){
					btm[x]|=(1ll<<(qs[uu][o]-'a'));
					trie2[x][qs[uu][o]-'a']=++pt3;
				}
				x=trie2[x][qs[uu][o]-'a'];
			}
			for(int o=0;o<qt[uu].size();o++){
				if(!trie2[y][qt[uu][o]-'a']){
					btm[y]|=(1ll<<(qt[uu][o]-'a'));
					trie2[y][qt[uu][o]-'a']=++pt3;
				}
				y=trie2[y][qt[uu][o]-'a'];
			}
			OQ[x].push_back(make_pair(y,uu));
		}
		dfs(1);dfsEX(0);
		for(int j=0;j<=pt3;j++){
			OP[j].clear();OQ[j].clear();
			ulglg cr=btm[j];
			while(cr){
				int c=mito[(cr&-cr)%100003];cr&=(cr-1);
				trie2[j][c]=0;
			}
			btm[j]=0;
		}
		pt4=0;
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0;
}

// pls subscribe uid=676025 :)

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
