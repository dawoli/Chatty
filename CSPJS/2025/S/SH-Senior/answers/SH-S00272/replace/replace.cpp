#include <bits/stdc++.h>
#define MOD 10000000000000061ll
std::unordered_map<long long,int> vc;
char s1[5000009],s2[5000009];
int N,Q,id,ch[10000009][26],sg[10000009],as[200009],kk,f1[200009],f2[200009],f3[200009],f4[200009],cc,
dfn[10000009],siz[10000009];
std::vector<int> id1[200009],id2[200009];
std::vector<char> al[200009],ar[200009],bl[200009],br[200009];
struct n_t{
	int a,b,c,d;
} aa[600009];
inline bool cmpd(n_t x,n_t y) {
	if(x.a!=y.a) return x.a<y.a;
	return abs(x.d)>abs(y.d);
}
#define lb(x) ((x)&(-(x)))
void dfs(int n) {
	dfn[n]=++cc;siz[n]=1;
	for(int i=0;i<26;i++) {
		if(ch[n][i]) {
			dfs(ch[n][i]);
			siz[n]+=siz[ch[n][i]];
		}
	}
}
inline void up(int n,int v) {
	while(n<=kk) {
		sg[n]+=v;
		n+=lb(n);
	}
}
inline int qr(int n) {
	int as=0;
	while(n) {
		as+=sg[n];
		n-=lb(n);
	}
	return as;
}
signed main(void) {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&N,&Q);
	for(int i=1;i<=N;i++) {
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int l=1,r=strlen(s1+1);
		while(l<=r) {
			if(s1[l]==s2[l]) {
				l++;
			} else if(s1[r]==s2[r]) {
				r--;
			} else break;
		}
		if(l>r) continue;
		long long aq=0;
		for(int i=l;i<=r;i++) {
			aq=(aq*137ll+s1[i]-'a'+17)%MOD;
		}
		for(int i=l;i<=r;i++) {
			aq=(aq*137ll+s2[i]-'a'+17)%MOD;
		}
		if(vc[aq]==0) {
			vc[aq]=++id;
		}
		int tt=vc[aq];
		id1[tt].push_back(i);
		for(int j=l-1;j>=1;j--) {
			al[i].push_back(s1[j]);
		}
		for(int j=r+1;s1[j];j++) {
			ar[i].push_back(s1[j]);
		}
	}
	for(int i=1;i<=Q;i++) {
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		if(strlen(s1+1)!=strlen(s2+1)) continue;		
		int l=1,r=strlen(s1+1);
		while(l<=r) {
			if(s1[l]==s2[l]) {
				l++;
			} else if(s1[r]==s2[r]) {
				r--;
			} else break;
		}
		assert(l<=r);
		long long aq=0;
		for(int i=l;i<=r;i++) {
			aq=(aq*137ll+s1[i]-'a'+17)%MOD;
		}
		for(int i=l;i<=r;i++) {
			aq=(aq*137ll+s2[i]-'a'+17)%MOD;
		}
		if(vc[aq]==0) {
			continue;
		}
		int tt=vc[aq];
		id2[tt].push_back(i);
		for(int j=l-1;j>=1;j--) {
			bl[i].push_back(s1[j]);
		}
		for(int j=r+1;s1[j];j++) {
			br[i].push_back(s1[j]);
		}
	}
	for(int i=1;i<=id;i++) {
		if(id2[i].empty()) continue;
		int rt=1,qq=0;
		kk=1;memset(ch[kk],0,sizeof(ch[kk]));
		for(int j=0;j<id1[i].size();j++) {
			int x=id1[i][j],cur=rt;
			for(int k=0;k<al[x].size();k++) {
				int oo=al[x][k]-'a';
				if(!ch[cur][oo]) {
					ch[cur][oo]=++kk;
					memset(ch[kk],0,sizeof(ch[kk]));
				}
				cur=ch[cur][oo];
			}
			f1[j]=cur;
			cur=rt;
			for(int k=0;k<ar[x].size();k++) {
				int oo=ar[x][k]-'a';
				if(!ch[cur][oo]) {
					ch[cur][oo]=++kk;
					memset(ch[kk],0,sizeof(ch[kk]));
				}
				cur=ch[cur][oo];
			}
			f2[j]=cur;
		}
		for(int j=0;j<id2[i].size();j++) {
			int x=id2[i][j],cur=rt;
			for(int k=0;k<bl[x].size();k++) {
				int oo=bl[x][k]-'a';
				if(!ch[cur][oo]) {
					ch[cur][oo]=++kk;
					memset(ch[kk],0,sizeof(ch[kk]));
				}
				cur=ch[cur][oo];
			}
			f3[j]=cur;
			cur=rt;
			for(int k=0;k<br[x].size();k++) {
				int oo=br[x][k]-'a';
				if(!ch[cur][oo]) {
					ch[cur][oo]=++kk;
					memset(ch[kk],0,sizeof(ch[kk]));
				}
				cur=ch[cur][oo];
			}
			f4[j]=cur;
		}
		cc=0;
		dfs(1);
		//printf("!! %d %d %d\n",i,kk,siz[1]);
		assert(siz[1]==kk);
		for(int j=1;j<=kk;j++) sg[j]=0;
		for(int j=0;j<id1[i].size();j++) {
			aa[++qq]=(n_t){dfn[f1[j]],dfn[f2[j]],dfn[f2[j]]+siz[f2[j]]-1,1};
			aa[++qq]=(n_t){dfn[f1[j]]+siz[f1[j]],dfn[f2[j]],dfn[f2[j]]+siz[f2[j]]-1,-1};
		}
		for(int j=0;j<id2[i].size();j++) {
			aa[++qq]=(n_t){dfn[f3[j]],dfn[f4[j]],id2[i][j],0};
		}
		std::sort(aa+1,aa+qq+1,cmpd);
		for(int j=1;j<=qq;j++) {
			if(aa[j].d==0) {
				as[aa[j].c]=qr(aa[j].b);
			} else {
				up(aa[j].b,aa[j].d);
				up(aa[j].c+1,-aa[j].d);
			}
		}
	}
	for(int i=1;i<=Q;i++) printf("%d\n",as[i]);
}