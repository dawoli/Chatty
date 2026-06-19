#include<bits/stdc++.h>
#define N 200009
#define V 20
using namespace std;
typedef long long ll;
inline ll read(){
	char c=getchar();ll x=0,f=1;
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}
ll T,n,m,base[N],X[4],c[N],d[V][N],A[N],K,k,RES,W[V][N];
//W: 确定情况下的胜者 
struct RESULT{
	ll tot_len,L,R;
	//至多一段
	ll tot,val[V];
	//至多 log 个人 
	RESULT(){tot_len=tot=0;}
	void print(){
		printf("%lld\n",tot);
		for(int i=1;i<=tot;i++) printf("%lld ",val[i]);
		printf("\n");
		printf("%lld %lld %lld\n",tot_len,L,R);
	} 
};
void dfs(ll k,ll l,ll r){
	W[k][r>>k]=0;
	if(k==0){W[k][l]=l;return;}
	ll mid=(l+r)>>1;
	dfs(k-1,l,mid),dfs(k-1,mid+1,r);
	if(W[k-1][mid>>(k-1)]&&W[k-1][r>>(k-1)]){
		ll L=W[k-1][mid>>(k-1)],R=W[k-1][r>>(k-1)];
		if(d[k][r>>k]==0) 
		    if(A[L]>=k) W[k][r>>k]=L;
		    else W[k][r>>k]=R;
		else
		    if(A[R]>=k) W[k][r>>k]=R;
		    else W[k][r>>k]=L;
	}
}
RESULT solve(ll k,ll l,ll r,ll c){
	if(r<=c){
		RESULT res;
		res.tot=1,res.val[1]=W[k][r>>k];
//		printf("%lld %lld %lld %lld\n",k,l,r,c);
//		res.print();
		return res;
	}
	if(l>c){
		RESULT res;
		res.tot_len=1,res.L=l,res.R=r;
//		printf("%lld %lld %lld %lld\n",k,l,r,c);
//		res.print();
		return res;
	}
	ll mid=(l+r)>>1;
	RESULT res1=solve(k-1,l,mid,c),res2=solve(k-1,mid+1,r,c),res;
	if(res1.tot_len==1){
		res.tot_len=1,res.L=res1.L,res.R=res2.R;
		if(d[k][r>>k]==0)
			for(int i=1;i<=res1.tot;i++){
				if(A[res1.val[i]]>=k) res.val[++res.tot]=res1.val[i];
		    }
		else for(int i=1;i<=res1.tot;i++) res.val[++res.tot]=res1.val[i];
		//printf("%lld %lld %lld %lld\n",k,l,r,c);
		//res.print();
		return res;
	}
	ll tot=res1.tot;
	if(tot!=1) printf("WARNING!!!!\n");
	ll v=res1.val[1],vst=0,vis[V];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=res2.tot;i++){
		if(d[k][r>>k]==0){
			if(A[v]>=k) vst=1;
			else vis[i]=1;
		}
		else{
			if(A[res2.val[i]]>=k) vis[i]=1;
			else vst=1;
		}
	}
	if(res2.tot_len&&(!(d[k][r>>k]==0&&A[v]<k))) vst=1;
	if(vst) res.val[++res.tot]=v;
	for(int i=1;i<=res2.tot;i++)
	if(vis[i]) res.val[++res.tot]=res2.val[i];
	if(!(d[k][r>>k]==0&&A[v]>=k)) res.tot_len=res2.tot_len,res.L=res2.L,res.R=res2.R;
//	printf("%lld %lld %lld %lld\n",k,l,r,c);
//	res.print();
	return res;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) base[i]=read();
	for(int i=1;i<=m;i++) c[i]=read();
	while((1<<K)<n) K++;
	for(int i=1;i<=K;i++){
		for(int j=1;j<=(1<<(K-i));j++){
			char c=getchar();
			while(!isdigit(c)) c=getchar();
			d[i][j]=c-'0';
		}
	}
	T=read();
	while(T--){
		RES=0;
		for(int i=0;i<4;i++) X[i]=read();
		for(int i=1;i<=n;i++) A[i]=base[i]^X[i%4];
		dfs(K,1,(1<<K));
		for(ll i=1;i<=m;i++){
			ll k=0;
			while((1<<k)<c[i]) k++;
			RESULT r=solve(k,1,1<<k,c[i]);
			ll res=0;
			for(int i=1;i<=r.tot;i++) res+=r.val[i];
			res+=r.tot_len*(r.R-r.L+1)*(r.R+r.L)/2;
			RES^=(res*i);
		}
		printf("%lld\n",RES);
	}
	return 0;
}
//Alea Jecta Est! - BlackY(WAiKURO)
