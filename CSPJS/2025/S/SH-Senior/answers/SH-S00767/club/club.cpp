#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int maxn=2e5+10;
int n;
int x,y,z;
int cnt1=0,cnt2=0,cnt3=0;
int a[maxn][4];
ll ans=0;
int subt1[maxn],subt2[maxn],subt3[maxn];
inline int read()
{
	int rr=0,ww=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		    ww=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		rr=rr*(1<<3)+rr*(1<<1)+ch-(1<<4)-(1<<5);
		ch=getchar();
	}
	return rr*ww;
}
signed main()
{
//	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();
		ans=0;
		cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++)
		{
			x=read(),y=read(),z=read();
			a[i][1]=x,a[i][2]=y,a[i][3]=z;
			if(x>=y && x>=z)
			{
				cnt1++;
				if(y>=z)
				    subt1[cnt1]=x-y;
				else
				    subt1[cnt1]=x-z;
			}
			else if(y>=x && y>=z)
			{
				cnt2++;
				if(x>=z)
				    subt2[cnt2]=y-x;
				else
				    subt2[cnt2]=y-z;
			}
			else
			{
				cnt3++;
				if(x>=y)
				    subt3[cnt3]=z-x;
				else
				    subt3[cnt3]=z-y;
			}
			ans+=max(x,max(y,z));
		}
		if(cnt1<=n/2 && cnt2<=n/2 && cnt3<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		else if(cnt1>n/2)
		{
			sort(subt1+1,subt1+cnt1+1);
			for(int k=1;k<=cnt1-n/2;k++)
			{
				ans-=subt1[k];
			}
		}
		else if(cnt2>n/2)
		{
			sort(subt2+1,subt2+cnt2+1);
			for(int k=1;k<=cnt2-n/2;k++)
			{
				ans-=subt2[k];
			}
		}
		else if(cnt3>n/2)
		{
			sort(subt3+1,subt3+cnt3+1);
			for(int k=1;k<=cnt3-n/2;k++)
			{
				ans-=subt3[k];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	//CSPrp++;
}
