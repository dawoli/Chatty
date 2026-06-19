#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	char ch=getchar();
	ll ret=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
const int MAXN = 131072+10;
const int MAXM = 100010;
const int V = 1e6+20;
int read_01(){
	char ch=getchar();
	while(!(ch=='0'||ch=='1')) ch=getchar();
	return (int)(ch-'0');
}
int n,m,pa[MAXN],h_cnt,a[MAXN];
bool opt[MAXN*4];
struct q_query{int c,id;}q[MAXM];
bool cmp_q(q_query x,q_query y){
	return x.c<y.c;
}
void read_tree(){
	int ct=h_cnt;
	while(ct!=0){
		int l=1<<(ct-1);
		int r=(1<<ct)-1;
		for(int i=l;i<=r;++i){
			opt[i]=read_01();
//			cout<<"o="<<i<<" opt="<<opt[i]<<endl;
		}
		ct--;
	}
	return ;
}
ll dp[MAXN*2][21],q_cnt,now_query_r;
//19- >bigger
//20- >any
//where   val=X sum_id
void push_up(int o,int R){
	int lc=o<<1,rc=o<<1|1;
//	cout<<"o="<<o<<" opt[o]="<<opt[o]<<" R="<<R<<endl;
	if(opt[o]) swap(lc,rc); // lc-> leizhu
	for(int i=0;i<=20;++i) dp[o][i]=0;
	//leizhu win
	for(int i=R;i<=20;++i)
		dp[o][i]+=dp[lc][i];
	//decide leizhu can lose
	bool f=0;
	for(int i=0;i<R;++i)
		if(dp[lc][i]!=0) f=1;
	if(dp[lc][20]!=0)    f=1;
	if(!f) return ;
	//leizhu lose 
	for(int i=0;i<=20;++i)
		dp[o][i]+=dp[rc][i];
	return ;
}
void build(int o,int l,int r,int h,bool f){
	if(l==r){
		if(f==0){
			for(int i=0;i<=19;++i) dp[o][i]=0;
			dp[o][20]=l;
			return ;
		}
//		assert(l<=now_query_r);
		int p=0;
		if(l>now_query_r) p=20;
		else if(a[l]>=19) p=19;
		else 			  p=a[l];
		for(int i=0;i<=20;++i)
			if(p==i)
				dp[o][i]=l;
			else
				dp[o][i]=0;
		return ;
	}
	int mid=(l+r)>>1;
	build(o<<1,l,mid,h-1,f);
	build(o<<1|1,mid+1,r,h-1,f);
	push_up(o,h);
	return ;
}
void update(int o,int l,int r,int ql,int qr,int h){
	if(r<ql||l>qr) return;
	if(ql<=l&&r<=qr){
		build(o,l,r,h,1);
		return ;
	}
	int mid=(l+r)>>1;
	update(o<<1,l,mid,ql,qr,h-1);
	update(o<<1|1,mid+1,r,ql,qr,h-1);
	push_up(o,h);
	return ; 
}
void multi_test(){
	int x[4];
	for(int i=0;i<=3;++i) x[i]=read();
	for(int i=1;i<=n;++i) a[i]=pa[i]^x[i%4];
	ll ans=0;
	q_cnt=0;
	build(1,1,(1<<h_cnt),h_cnt,0);
	for(int i=1;i<=m;++i){
		now_query_r=q[i].c;
		while((1<<q_cnt)<q[i].c) q_cnt++;
		if(q[i-1].c+1<=q[i].c)
			update(1,1,(1<<h_cnt),q[i-1].c+1,q[i].c,h_cnt);
		int rt=1<<(h_cnt-q_cnt);
		ll sum=0;
		for(int j=0;j<=20;++j) sum+=dp[rt][j];
//		cout<<"h_cnt="<<h_cnt<<" q_cnt="<<q_cnt<<endl;
//		cout<<"q[i].id="<<q[i].id<<" sum="<<sum<<endl;
		ans^=((ll)sum*(ll)q[i].id);
	}
	cout<<ans<<endl;
	return ;
} 
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i) pa[i]=read();
	for(int i=1;i<=m;++i) q[i].c=read(),q[i].id=i;
	sort(q+1,q+m+1,cmp_q);
	while((1<<h_cnt)<n) h_cnt++;
	assert(h_cnt>=0);
	read_tree();
	ll T=read();
	while(T--) multi_test();
	return 0;
}
