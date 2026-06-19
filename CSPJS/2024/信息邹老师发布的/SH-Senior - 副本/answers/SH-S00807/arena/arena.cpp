#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
bool h1;
const int N=1<<18;
const int INF=18;
LL A[N],a[N];
LL X[4];
int T;
int lg[N<<1];
int n,m,K;
int c[N],rt[20];
LL ans[N];
string s[20];
struct Segment
{
	// sum表示可能成为擂主的编号之和,val表示所有可能擂主a值的最小值和最大值 ,R是当前比赛为第几轮
	// cnt[i]表示擂主中a值确定为i的编号总和 
	int l,r; LL sum,cnt[18];int mn,mx,R;
	bool d; // 比赛的胜负取决于哪一方 
	bool x; // 擂主候选人中是否有a值未知的人 
} tr[1<<19];
void pushup(int u)
{
	tr[u].mn=INF;
	tr[u].mx=-INF;
	tr[u].sum=0;
	for(int i=0;i<=17;++i) tr[u].cnt[i]=0;
	tr[u].x=false;
	int ls=u<<1,rs=u<<1|1;
	if(!tr[u].d) swap(ls,rs);
	if(tr[rs].mx>=tr[u].R) // 右儿子有可能成为擂主,擂主的a值必然>=R 
	{
		tr[u].sum += tr[rs].sum; // a值<R的不可能成为新擂主
		for(int i=0;i<tr[u].R;++i) tr[u].sum -= tr[rs].cnt[i];
		if(tr[rs].x){tr[u].mx=INF;tr[u].mn=tr[u].R;tr[u].x=true;}
		else
		{
			tr[u].mx=max(tr[u].mx,tr[rs].mx);
			for(int i=17;i>=tr[u].R;--i)
			{
				tr[u].cnt[i]+=tr[rs].cnt[i];
				if(tr[rs].cnt[i]) tr[u].mn=min(tr[u].mn,i);
			}
		}
	}
	if(tr[rs].mn<tr[u].R) // 左儿子有可能成为擂主
	{
		tr[u].sum += tr[ls].sum;
		if(tr[ls].x){tr[u].mx=INF;tr[u].mn=-1;tr[u].x=true;}
		else
		{
			tr[u].mx=max(tr[u].mx,tr[ls].mx);
			for(int i=17;~i;--i)
			{
				tr[u].cnt[i]+=tr[ls].cnt[i];
				if(tr[ls].cnt[i]) tr[u].mn=min(tr[u].mn,i);
			}
		}
	}
}
void build(int u,int l,int r,int R,int pos)
{
	tr[u]={l,r};
	tr[u].sum=0;
	for(int i=0;i<=17;++i) tr[u].cnt[i]=0;
	tr[u].x=true;
	tr[u].mn=-1;
	tr[u].mx=INF;
	tr[u].R=R;
	if(l==1) rt[lg[r]]=u;
	if(l==r){tr[u].sum=l;return;}
	tr[u].d=(s[R][pos]!='0');
	int mid=(l+r)/2;
	build(u<<1,l,mid,R-1,pos<<1);
	build(u<<1|1,mid+1,r,R-1,pos<<1|1);
	pushup(u);
}
// 将pos处的a值改为确定的数x,若x=-1表示改为一个不确定的值 
void upd(int u,int pos,int x)
{
	if(tr[u].l==tr[u].r)
	{
		if(x>=0)
		{
			tr[u].sum=tr[u].l;
			tr[u].mn=tr[u].mx=min(x,17);
			for(int i=0;i<=17;++i) tr[u].cnt[i]=0;
			tr[u].cnt[min(x,17)]=tr[u].l;
			tr[u].x=false;
		}
		else
		{
			tr[u].sum=tr[u].l;
			tr[u].mn=-1; tr[u].mx=INF;
			for(int i=0;i<=17;++i) tr[u].cnt[i]=0;
			tr[u].x=true;
		}
		return;
	}
	if(pos>tr[u<<1].r) upd(u<<1|1,pos,x);
	else upd(u<<1,pos,x);
	pushup(u);
}
bool h2;
int main()
{
	ios::sync_with_stdio(false);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=2;i<=2*n;++i) lg[i]=lg[(i+1)>>1]+1;
	K=lg[n];
	for(int i=1;i<=n;++i) cin>>A[i];
	for(int i=1;i<=m;++i) cin>>c[i];
	for(int i=1;i<=K;++i)
		cin>>s[i];
	build(1,1,1<<K,K,0);
	cin>>T;
	while(T--)
	{
		for(int i=0;i<4;++i) cin>>X[i];
		for(int i=1;i<=n;++i) a[i]=A[i]^X[i%4];
		for(int i=1;i<=(1<<K);++i) upd(1,i,-1);
		for(int i=1;i<=n;++i)
		{
			upd(1,i,a[i]);
			ans[i]=tr[rt[lg[i]]].sum;
		}
		LL res=0;
		for(LL i=1;i<=m;++i)
		{
			res ^= i*ans[c[i]];
		}
		cout << res << "\n";
	}
	return 0;
}
