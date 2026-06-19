#include<bits/stdc++.h>
#define N 100001
#define R 101
#define V 4*R*N
#define E 5*R*N
using namespace std;
typedef long long ll;
ll n,k,nQ,l[N],r[N],c[N],mxr,cnt[2*N],mxv=0,nV,cntS=0,ids[2*N];
vector<ll> s[N],id[N],sC[N*2],sT[N*2];
bool vst[V];
struct Node{
	ll re,co,u,cl,d1,pst;
};
void print(Node now){
	if(now.cl) printf("color(%lld,%lld,%lld)",now.re,now.cl,now.pst);
	else printf("grid(%lld,%lld,%lld,%lld)",now.re,now.co,now.u,now.d1);
}
void bfs(){
	queue<Node> q;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=l[i];j++)
			if(s[i][j]==1) q.push((Node){1,i,j,0,1,0});
	while(!q.empty()){
		Node now=q.front(); q.pop();
		if(now.cl&&sT[now.cl].size()>1){
			for(ll i=0;i<sT[now.cl].size();i++){
				ll co=sC[now.cl][i],tr=sT[now.cl][i];
				ll v=(now.re-1)*(nV+cntS)+id[co][tr];
				if(vst[v]) continue;
//				if(id[co][tr]==now.pst) continue;
				vst[v]=1;
				q.push((Node){now.re,co,tr,0,1,0});
			}
		}else{
			if(now.d1<k&&now.u<l[now.co]){
				ll v=(now.re-1)*(nV+cntS)+id[now.co][now.u+1];
				if(!vst[v]){
					vst[v]=1;
					q.push((Node){now.re,now.co,now.u+1,0,now.d1+1,0});
				}
			}
			if(now.re<=mxr&&now.d1>=2){
				ll v=now.re*(nV+cntS)+nV+ids[s[now.co][now.u]];
				if(!vst[v]){
					vst[v]=1;
					q.push((Node){now.re+1,0,0,ids[s[now.co][now.u]],0,id[now.co][now.u]});
				}
			}
		}
	}
}
void input(){
	for(ll i=1;i<=cntS;i++) sT[i].clear(),sC[i].clear();
	scanf("%lld %lld %lld",&n,&k,&nQ);
	mxr=0; mxv=0; cntS=0;
	for(ll i=1;i<=n;i++) s[i].clear(),id[i].clear();
	ll tot=0;
	for(ll i=1;i<=n;i++){
		s[i].push_back(0);
		id[i].push_back(0);
		scanf("%lld",&l[i]);
		ll val;
		for(ll j=1;j<=l[i];j++){
			scanf("%lld",&val);
			ids[val]=0;
			s[i].push_back(val);
			mxv=max(mxv,val);
			tot++;
			id[i].push_back(tot);
		}
	}
	nV=tot;
	for(ll i=1;i<=nQ;i++){
		scanf("%lld %lld",&r[i],&c[i]);
		mxr=max(mxr,r[i]);
	}
}
void solveR(){
	for(ll i=1;i<=mxv;i++) cnt[i]=0,vst[i]=0;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=l[i];j++){
			if(cnt[s[i][j]]==0){
				cntS++;
				ids[s[i][j]]=cntS;
			}
			cnt[s[i][j]]++;
			sT[ids[s[i][j]]].push_back(j);
			sC[ids[s[i][j]]].push_back(i);
		}
	bfs();
	for(ll i=1;i<=nQ;i++){
		if(ids[c[i]]==0||ids[c[i]]>cntS) printf("0\n");
		else if(vst[r[i]*(nV+cntS)+nV+ids[c[i]]]) printf("1\n");
		else printf("0\n");
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	for(ll i=1;i<=T;i++){
		input();
//		if(mxr==1)
//			solve1();
//		else
			solveR();
	}
	return 0;
}

