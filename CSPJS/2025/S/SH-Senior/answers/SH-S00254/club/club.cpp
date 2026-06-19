#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define pc putchar
int n;
int a[200010][5];
int T;
int nw[2000010];
int b[200010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		rep(i,1,n) 
		{
			rep(j,1,3) cin>>a[i][j];
		}
		int cnt1=0,cnt2=0,cnt3=0;
		int ans=0;
		rep(i,1,n)
		{
			int p=a[i][1],q=a[i][2],r=a[i][3];
			int s=max(p,max(q,r));
			if(p==s)
			{
				cnt1++;nw[i]=1;
			}
			else if(q==s)
			{
				cnt2++;nw[i]=2;
			}
			else if(r==s)
			{
				cnt3++;nw[i]=3;
			}
			else assert(0);
			ans+=s;
		}
	//	cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<'\n';
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2)
		{
			cout<<ans<<'\n';
		}
		else
		{
			if(cnt1>n/2)
			{
				int tp=cnt1-n/2;
				int cnt=0;
				rep(i,1,n)
				{
					if(nw[i]==1)
					{
						b[++cnt]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
					}
				}
				sort(b+1,b+cnt+1);
				int mn=0;
				rep(i,1,tp) mn+=b[i];
				cout<<ans-mn<<'\n';
			}
			else if(cnt2>n/2)
			{
				int tp=cnt2-n/2;
				int cnt=0;
				rep(i,1,n)
				{
					if(nw[i]==2)
					{
						b[++cnt]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
					}
				}
				sort(b+1,b+cnt+1);
				int mn=0;
				rep(i,1,tp) mn+=b[i];
				cout<<ans-mn<<'\n';
			}
			else if(cnt3>n/2)
			{
				int tp=cnt3-n/2;
				int cnt=0;
				rep(i,1,n)
				{
					if(nw[i]==3)
					{
						b[++cnt]=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
					}
				}
				sort(b+1,b+cnt+1);
				int mn=0;
				rep(i,1,tp) mn+=b[i];
				cout<<ans-mn<<'\n';
			}
			else assert(0);
		}
	}
} 
