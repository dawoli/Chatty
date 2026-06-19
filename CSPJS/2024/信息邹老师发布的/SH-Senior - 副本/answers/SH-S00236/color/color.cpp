#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define inf 0x3f3f3f3f
typedef pair<int,int> pii;
int n,m,x,y,a[200010],tst=0,tmp=0,ans=0,tp=0; 
int dp[2010][2010];
int b[200010];
int v[200010];
struct seg
{
	int l,r,mx,tg;
	//qujian jia //qujian max
} tr[1000010];
void build(int rt,int l,int r)
{
	tr[rt]=(seg){l,r,-inf,0};
	if(l==r) return;
	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
}
void pushdown(int x)
{
	if(tr[x].tg)
	{
		tr[x*2+1].mx+=tr[x].tg;
		tr[x*2+1].tg+=tr[x].tg;
		tr[x*2].mx+=tr[x].tg;
		tr[x*2].tg+=tr[x].tg;
		tr[x].tg=0;
	}
}
void add(int rt,int l,int r,int v)
{
	if(tr[rt].r<l||tr[rt].l>r) return;
	if(tr[rt].l>=l&&tr[rt].r<=r)
	{
	//	cout<<l<<" "<<r<<" "<<v<<endl;
	//	cout<<tr[rt].tg<<" "<<" "<<tr[rt].mx<<" "<<l<<" "<<r<<endl;
		tr[rt].tg+=v;
		tr[rt].mx+=v;
		//cout<<tr[rt].tg<<" "<<" "<<tr[rt].mx<<" "<<l<<" "<<r<<endl;
		return;
	}
	pushdown(rt);
	add(rt*2,l,r,v);
	add(rt*2+1,l,r,v);
	tr[rt].mx=max(tr[rt*2].mx,tr[rt*2+1].mx);
}
int query(int rt,int l,int r)
{
	if(tr[rt].r<l||tr[rt].l>r) return -inf;
	if(tr[rt].l>=l&&tr[rt].r<=r)
	{
		return tr[rt].mx;
	}
	pushdown(rt);
	return max(query(rt*2,l,r),query(rt*2+1,l,r));
}
//j lst (not now) k now red or blue
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>tst;
	while(tst--)
	{
		cin>>n;
		rep(i,1,n) cin>>a[i],b[i]=a[i];
		sort(b+1,b+n+1);
		m=unique(b+1,b+n+1)-b-1;
		int tp=0;
		rep(i,1,n) 
		{
			tp=a[i];
			a[i]=lower_bound(b+1,b+m+1,a[i])-b;
			v[a[i]]=tp;
		}
	//	rep(i,0,n) rep(j,0,n)  dp[i][j]=-inf;
		build(1,1,n+1);
	//	rep(i,0,n) cout<<query(1,i+1,i+1)<<endl;
		a[0]=-1;
		add(1,1,1,inf);
	//	dp[0][0]=0;
		rep(i,1,n)
		{
			if(i!=1)
			{
				tmp=query(1,1,n+1);
				tmp=max(tmp,v[a[i]]+query(1,a[i]+1,a[i]+1));
			}
			if(a[i]==a[i-1]) add(1,1,n+1,v[a[i]]);
			if(i!=1)
			{
				tp=query(1,a[i-1]+1,a[i-1]+1);
				if(tp<tmp) add(1,a[i-1]+1,a[i-1]+1,tmp-tp);
			}
//			rep(j,0,n)
//			{
//				dp[i][j]=dp[i-1][j];
//				if(a[i]==a[i-1]) dp[i][j]+=v[a[i]];
//			}
//			if(i!=1)
//			{
//				rep(j,0,n)
//				{
//					tmp=dp[i-1][j];
//					if(a[i]==j) tmp+=v[j];
//					dp[i][a[i-1]]=max(dp[i][a[i-1]],tmp);
//				}
			//	cout<<i<<" "<<a[i-1]<<" "<<dp[i][a[i-1]][1]<<" "<<dp[i][a[i-1]][0]<<endl;
//			}
			//rep(j,0,n) cout<<dp[i][j]<<" "<<query(1,j+1,j+1)<<endl;
		}
	//	ans=0;
		//rep(i,0,n) cout<<dp[n][i]<<" ";
		cout<<query(1,1,n+1)<<endl;
	}
} 
