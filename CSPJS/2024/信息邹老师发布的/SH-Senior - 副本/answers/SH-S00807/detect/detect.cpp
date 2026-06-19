// 微软输入法居然是好的 
#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=1e5+5;
int T;
int n,m,L,V;
struct Car
{
	int x,v,a;
	//  初始位置，速度，加速度 
}c[N];
struct Interval
{
	int l,r;
	bool operator<(const Interval& rhs)const{return r<rhs.r;}
}a[N],b[N];
int r[N];
int nA,nB; // 区间数 
int main()
{
	ios::sync_with_stdio(false);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;++i)
			cin>>c[i].x>>c[i].v>>c[i].a;
		for(int i=1;i<=m;++i) cin>>r[i];
		nA=0;
		// 处理超速区间 
		for(int i=1;i<=n;++i)
		{
			if(c[i].a==0)
			{
				if(c[i].v>V)
					a[++nA]={c[i].x,L}; // 全局超速 
			}
			if(c[i].a>0)
			{
				if(c[i].v>V)
					a[++nA]={c[i].x,L}; // 全局超速
				else
				{
					int y=((V*V-c[i].v*c[i].v)/2.0/c[i].a + c[i].x);
					++y;
					if(y<=L) a[++nA]={y,L}; // 最后一段超速 
				}
			}
			else
			{
				if(c[i].v>V)
				{
					int y=ceil((V*V-c[i].v*c[i].v)/2.0/c[i].a + c[i].x)-1;
					if(y>L) y=L;
					if(y>=c[i].x) a[++nA]={c[i].x,y};
				}
			}
		}
		nB=0;
		for(int i=1;i<=nA;++i)
		{
			int L=lower_bound(r+1,r+1+m,a[i].l)-r;
			int R=upper_bound(r+1,r+1+m,a[i].r)-r-1;
			if(L<=R) b[++nB]={L,R};
		}
		cout << nB << " ";
		sort(b+1,b+1+nB);
		int ans=0;
		for(int i=1,R=0;i<=nB;++i)
		{
			if(b[i].l<=b[i-1].l) continue;
			if(b[i].l>R) ++ans,R=b[i].r;
		}
		cout << m-ans << "\n";
	}
	return 0;
}
