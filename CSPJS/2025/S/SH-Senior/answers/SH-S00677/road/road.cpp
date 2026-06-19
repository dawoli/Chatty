#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10009,M=1000009,K=19,BNRK=1024;
struct edge{ll u,v,w;};
edge fx[M],e[BNRK][N+K],le[N+N+K];
ll id[N+K],ans[BNRK],c[K],a[K][N];
bool cmp(const edge&a,const edge&b){
	return a.w<b.w;
}
ll root(ll u){
	return (id[u]==u?u:id[u]=root(id[u]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,m,k;
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)cin>>fx[i].u>>fx[i].v>>fx[i].w;
	sort(fx+1,fx+1+m,cmp);
	ll yb=0;
	for(ll i=1;i<=n;i++)id[i]=i;
	for(ll i=1;i<=m;i++){
		ll ru=root(fx[i].u),rv=root(fx[i].v);
		if(ru==rv)continue;
		id[ru]=rv;
		ans[0]+=fx[i].w;
		e[0][++yb]=fx[i];
		if(yb==n-1)break;
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++)cin>>a[i][j];
	}
	ll al=(1<<k);
	for(ll i=1;i<al;i++){
		ll ppc=0;
		for(ll j=0;j<n;j++){
			if(((i>>j)&1)==1)ans[i]+=c[j+1],ppc++;
		}
		ll lb=i&-i;
		ll lst=i-lb;
		lb=log2(lb)+1;
		for(ll j=1;j<=n+ppc-2;j++)le[j]=e[lst][j];
		for(ll j=1;j<=n;j++)le[j+n+ppc-2]=(edge){n+lb,j,a[lb][j]};
		sort(le+1,le+n+n+ppc-1,cmp);
		yb=0;
		for(ll j=1;j<=n+k;j++)id[j]=j;
		for(ll j=1;j<=n+n+ppc-2;j++){
			ll ru=root(le[j].u),rv=root(le[j].v);
			if(ru==rv)continue;
			id[ru]=rv;
			ans[i]+=le[j].w;
			e[i][++yb]=le[j];
			if(yb==n+ppc-1)break;
		}
	}
//	for(ll i=0;i<al;i++){
//		cout<<i<<" "<<ans[i]<<" ";
//		for(ll j=1;j<n+k;j++)cout<<"("<<e[i][j].u<<","<<e[i][j].v<<","<<e[i][j].w<<") ";
//		cout<<"\n";
//	}
	cout<<*min_element(ans,ans+al);
    return 0;
}
/*
´óÏÒàÐàÐÈç¼±Óê£¬Ð¡ÏÒÇÐÇÐÈçË½Óï
àÐàÐÇÐÇÐ´íÔÓµ¯£¬´óÖéÐ¡ÖéÂäÓñÅÌ
¼ä¹ØÝºÓï»¨µ×»¬£¬ÓÄÑÊÈªÁ÷±ùÏÂÄÑ
Ë®ÈªÀäÉ¬ÏÒÄý¾ø£¬Äý¾ø²»Í¨ÉùÔÝÐª
±ðÓÐÓÄ³î°µºÞÉú£¬´ËÊ±ÎÞÉùÊ¤ÓÐÉù
ÒøÆ¿Õ§ÆÆË®½¬±Å£¬ÌúÆïÍ»³öµ¶Ç¹Ãù
ÇúÖÕÊÕ²¦µ±ÐÄ»­£¬ËÄÏÒÒ»ÉùÈçÁÑ²¯
¶«´¬Î÷ô³ÇÄÎÞÑÔ£¬Î¨¼û½­ÐÄÇïÔÂ°× 
*/
