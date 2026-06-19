#include<bits/stdc++.h>
using namespace std;
#define N 200009
#define M 5000009
#define ll long long
bool mbe;
int n,q;ll ans[N];
char s[M],t1[M],t2[M];
int rt1,rt2,P1[N],P2[N],l2[N],r2[N];
int t[M][26],cnt,dep[M],fa[M],fail[M],dfn[M],siz[M];
void ins(int id,int tp,char *c){
	int l=strlen(c+1);
	int rt=(tp==1?rt1:rt2);
	int p=rt;
	for(int i=1;i<=l;++i){
		if(!t[p][c[i]-'a'])t[p][c[i]-'a']=++cnt,dep[cnt]=dep[p]+1;
		p=t[p][c[i]-'a'];
	}
	if(tp==1)P1[id]=p;
	else P2[id]=p;
}
int qu[M],lp,rp;int top;
int head[M],to[M],nxt[M],ecnt;
vector<int> son[M];// l2 sons
inline void addedge(int a,int b){
	++ecnt;to[ecnt]=b,nxt[ecnt]=head[a];head[a]=ecnt;
	son[a].push_back(b);
}
int lst[M];
int build(int rt){
	lp=1,rp=0;
	for(int i=0;i<26;++i){
		if(t[rt][i]){
			qu[++rp]=t[rt][i],fail[t[rt][i]]=rt;
		}
		else t[rt][i]=rt;
	}
	int p;
	while(lp<=rp){
		p=qu[lp++];fa[p]=fail[p],addedge(fail[p],p);
		for(int i=0;i<26;++i){
			if(t[p][i]){
				fail[t[p][i]]=t[fail[p]][i],qu[++rp]=t[p][i];
			}
			else t[p][i]=t[fail[p]][i];
		}
	}
	top=0;
	qu[++top]=rt;
	int ed,num=0;
	while(top){
		p=qu[top];siz[p]=0;
		if(!dfn[p])dfn[p]=++num,lst[num]=p;
		if(head[p]==0)--top;
		else{
			ed=to[head[p]];
			qu[++top]=ed;
			head[p]=nxt[head[p]];
		}
	}
	for(int j=num,i;j>=1;--j){
		i=lst[j];
		++siz[i];
		if(fa[i])siz[fa[i]]+=siz[i];
	}
	return num;
}
struct seg{
	int n,x[M];
	inline void init(int _n){n=_n;}
	void _add(int p,int d){for(;p<=n;p+=p&-p)x[p]+=d;}
	int _qr(int p){int r=0;for(;p;p-=p&-p)r+=x[p];return r;}
	inline void add(int l,int r,int d){_add(l,d);if(r<n)_add(r+1,-d);}
	inline int qr(int p){return _qr(p);}
}sg;
vector<pair<int,int> > pt[M];// n pairs
struct ev{int p,mt,id;};vector<ev> qq[M];// l2 events
int fat[M][23];
void pre(int p){
	fat[p][0]=fa[p];
	for(int i=1;i<=22;++i)fat[p][i]=fat[fat[p][i-1]][i-1];
	for(int i:son[p])pre(i);
}
int dth_fa(int p,int d){ // dep<=d maxdep node
	for(int i=22;i>=0;--i)if(dep[fat[p][i]]>d)p=fat[p][i];
	return fat[p][0];
}
void dfs(int p){
//	printf("Node %d\n",p);
	for(pair<int,int> pr:pt[p])sg.add(pr.first,pr.second,1);
	for(ev e:qq[p])ans[e.id]+=sg.qr(e.p)*e.mt;
	for(int i:son[p])dfs(i);
	for(pair<int,int> pr:pt[p])sg.add(pr.first,pr.second,-1);
}
bool med;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	cerr<<(&mbe-&med)/1048576.<<endl;
	scanf("%d%d",&n,&q);
	rt1=1,rt2=2;dep[1]=dep[2]=0;cnt=2;
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		ins(i,1,s);
		scanf("%s",s+1);
		ins(i,2,s);
	}
	fail[1]=1,fail[2]=2;
	int sz1=build(1);int sz2=build(2);
/*	for(int i=1;i<=cnt;++i){
		printf("Node #%d:\n",i);
		printf("Fail[%d]=%d  DFN==%d\n",i,fail[i],dfn[i]);
		for(int j=0;j<26;++j)if(t[i][j]>2)printf("%c=%d ",j+'a',t[i][j]);
		puts("");
	}*/
	for(int i=1;i<=n;++i){
		l2[i]=dfn[P2[i]],r2[i]=dfn[P2[i]]+siz[P2[i]]-1;
		pt[P1[i]].push_back({l2[i],r2[i]});
	}
	pre(rt1);
	for(int i=1,p1,p2,len,q1,q2;i<=q;++i){
		scanf("%s%s",t1+1,t2+1);
		len=strlen(t1+1);
		if(len!=strlen(t2+1)){
			ans[i]=0;
			continue;
		}
		p1=rt1,p2=rt2;
		ans[i]=0;
		int L=1,R=len;
		while(t1[L]==t2[L])++L;
		while(t1[R]==t2[R])--R;
		for(int j=1;j<=len;++j){
			p1=t[p1][t1[j]-'a'],p2=t[p2][t2[j]-'a'];
			if(j>=R){
				// WA
				/*int q1=p1,q2=p2;
				while(dep[q1]>=j-L+1&&dep[q2]>=j-L+1){
					if(dep[q1]>dep[q2])q1=fa[q1];
					else if(dep[q2]>dep[q1])q2=fa[q2];
					else{
						if(clr[q1]==clr[q2]&&clr[q1]!=0)++ans[i];
						q1=fa[q1],q2=fa[q2];
					}
				}*/
				// AC but TLE!
				/*q1=dfn[p1],q2=dfn[p2];
				if(dep[p1]<j-L+1)continue;
				for(int k=1;k<=n;++k)if(l1[k]<=q1&&q1<=r1[k]&&l2[k]<=q2&&q2<=r2[k]
									&&dep[P1[k]]>=j-L+1)
					++ans[i];*/
				if(dep[p1]<j-L+1)continue;
				qq[p1].push_back({dfn[p2],1,i});
				qq[dth_fa(p1,j-L)].push_back({dfn[p2],-1,i});
			}
		//	cout<<j<<" "<<ans[i]<<endl; 
		}
	}
	sg.init(sz2);dfs(rt1);
	for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
//	cerr<<clock()<<endl;
	return 0;
}

