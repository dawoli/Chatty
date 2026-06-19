#include<bits/stdc++.h>
#define N 3009
#define INF 30009
#define pii pair<int,int>
using namespace std;
struct node{
	int d,v,a;
}car[N];
struct tree{
	int l,r,mn;
}t[N*4];
int n,m,pos[N],limit,L,T,out1,out2,dp[N],cnt;
inline void pushup(int x){
	t[x].mn=max(t[x*2].mn,t[x*2+1].mn);
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){t[p].mn=-INF;return;}
	int mid=(l+r)/2;
	build(p*2,l,mid),build(p*2+1,mid+1,r);
	pushup(p);
}
void change(int p,int x,int y){
	if(t[p].l==t[p].r){t[p].mn=max(t[p].mn,y);return;}
	int mid=(t[p].l+t[p].r)/2;
	if(x<=mid)change(p*2,x,y);
	else change(p*2+1,x,y);
	pushup(p);
}
int ask(int p,int l,int r){
	if(l<=0||r<=0||l>r)return -INF;
	if(l<=t[p].l&&t[p].r<=r)return t[p].mn;
	int val=-INF,mid=(t[p].l+t[p].r)/2;
	if(l<=mid)val=max(val,ask(p*2,l,r));
	if(r>mid)val=max(val,ask(p*2+1,l,r));
	return val;
}
void add(int l,int r){
	if(l<0||r<0||l>r||l>m||r>m)return;
	out1++;
//	cout<<l<<" "<<r<<"\n";
	change(1,r,max(ask(1,r,r),l));
}
void clr(){
	for(int i=1;i<=m+1;i++)dp[i]=INF;
	out1=0,out2=0,cnt=0;
}
void work(int i){
	int ld=lower_bound(pos+1,pos+m+1,car[i].d)-pos;
	double p,s;
	if(car[i].v>limit&&car[i].a>=0){add(ld,m);return;}
	else if(car[i].v<=limit&&car[i].a<=0)return;
	else if(car[i].v>limit&&car[i].a<0){
		p=(double)(car[i].v-limit)/(double)(-car[i].a);
		s=(double)car[i].v*p+0.5*(double)car[i].a*p*p;
		int l=ld,r=m,mid,ans=-1;
		while(l<=r){
			mid=(l+r)/2;
			if((double)car[i].d+s>pos[mid])ans=mid,l=mid+1;
			else r=mid-1;
		}
		add(ld,ans);
	}else{
		p=(double)(limit-car[i].v)/(double)(car[i].a);
		s=(double)car[i].v*p+0.5*(double)car[i].a*p*p;int ans;
		ans=upper_bound(pos+1,pos+m+1,floor(s+(double)car[i].d))-pos;
		add(ans,m);
	}
}
void solve(){
	cin>>n>>m>>L>>limit;
	build(1,1,m);
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		car[i]={x,y,z};
	}
	for(int i=1;i<=m;i++){
		cin>>pos[i];
	}
	for(int i=1;i<=n;i++)work(i);
	//cout<<ask(1,1,5)<<"\n";
	for(int i=1;i<=m;i++){
		dp[i]=INF;
		for(int j=0;j<i;j++){
			if(ask(1,j+1,i-1)<=j)dp[i]=min(dp[i],dp[j]+1);
		}
	//	cout<<i<<" "<<dp[i]<<"\n";
	}
	out2=dp[m];
    for(int i=m-1;i>=1;i--)if(ask(1,i+1,m)<=i)out2=min(out2,dp[i]);
    out2=m-out2;
	cout<<out1<<" "<<out2<<"\n";
	clr();
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
//	int ms=system(clock());
	memset(dp,INF,sizeof(dp));dp[0]=0;
	while(T--){solve();}
//	int msp=system("clock()");
//	cout<<msp-ms;
	return 0;
}
