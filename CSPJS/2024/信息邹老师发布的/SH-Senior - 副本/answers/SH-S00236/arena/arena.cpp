#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef pair<int,int> pii;
int n,m,x,y,aa[200010],a[200010],tst,ttmp; 
int c[200010];
string d[20];
int sum=0,now=1,k=0;
int xx[4];
int ans=0;
int l2[200010];
int e[10];
bool vis[10];
int f(int l,int r)
{
	int p=l2[r-l+1];
	if(d[p][l/(1<<p)]=='0') return 0;
	return 1;
}
int calc(int l,int r)
{
	if(l==r){return l;}
	if(r-l==1)
	{
		int tp=f(l,r);
		if(tp==0)
		{
			if(a[l]>=1) return l;
			return r;
		}
		else 
		{
			if(a[r]>=1) return r;
			return l;
		}
	}
	int mid=(l+r)/2;
	int t1=calc(l,mid),t2=calc(mid+1,r);
	int tp=f(l,r);
	if(tp==0)
	{
		if(a[t1]>=l2[r-l+1]) return t1;
		else return t2;
	}
	else
	{
		if(a[t2]>=l2[r-l+1]) return t2;
		return t1;
	}
}
int calc1(int l,int r)
{
	if(l==r){return l;}
	//cout<<l<<" "<<r<<endl;
	if(r-l==1)
	{
		int tp=f(l,r);
		if(tp==0)
		{
			if(e[l]>=1) return l;
			return r;
		}
		else 
		{
			if(e[r]>=1) return r;
			return l;
		}
	}
	int mid=(l+r)/2;
	int t1=calc1(l,mid),t2=calc1(mid+1,r);
//	cout<<l<<" "<<mid<<" "<<t1<<endl;
//	cout<<mid+1<<" "<<r<<" "<<t2<<endl;
	int tp=f(l,r);
	if(tp==0)
	{
		if(e[t1]>=l2[r-l+1]) return t1;
		else return t2;
	}
	else
	{
		if(e[t2]>=l2[r-l+1]) return t2;
		return t1;
	}
}
void dfs(int l,int r)
{
	//cout<<l<<" "<<r<<endl;
	if(l>r)
	{
		vis[calc1(1,ttmp)]=1;
		return;
	}
	rep(i,0,3)
	{
		e[l]=i;
		dfs(l+1,r);
		e[l]=0;
	}
}
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	l2[1]=0;
	rep(i,2,n*2) l2[i]=l2[i/2]+1;
	rep(i,1,n) cin>>aa[i];
	rep(i,1,m) cin>>c[i];
	//sort(c+1,c+m+1);
	while(now<n) now*=2,++k;
	rep(i,1,k)
	{
		cin>>d[i];
		//cout<<d[i]<<endl;
		rep(j,1,(1<<(k-i))) sum+=(d[i][j-1]-'0');
	}
	if(sum==0)
	{
		while(tst--)
		{
			rep(i,0,3) cin>>xx[i];
			rep(i,1,n) a[i]=aa[i]^xx[i%4];
			
		}
	}
	else if(n<=8&&m<=8)
	{
		cin>>tst;
		while(tst--)
		{
			rep(i,0,3) cin>>xx[i];
			rep(i,1,n) a[i]=aa[i]^xx[i%4];
			ans=0;
			int sm=0;
			rep(i,1,m)
			{
				ttmp=1;
				while(ttmp<c[i]) ttmp*=2;
				rep(j,1,ttmp) vis[j]=0;
				rep(j,1,c[i]) e[j]=a[j];
				dfs(c[i]+1,ttmp);
				sm=0;
				rep(j,1,ttmp) if(vis[j]) sm+=j;
				//cout<<sm<<endl;
				ans^=(i*sm);
			} 
			cout<<ans<<endl;
		}
	}
	else
	{
		cin>>tst;
		while(tst--)
		{
			rep(i,0,3) cin>>xx[i];
			rep(i,1,n) a[i]=aa[i]^xx[i%4];
			ans=0;
			rep(i,1,m)
			{
				int tmp=calc(1,c[i]);
				ans^=(i*tmp);
			}
			cout<<ans<<endl;
		}
	}
} 
