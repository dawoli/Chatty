#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,inf=1e9;
int n,t,cnt[4],b,ans;
struct Stu
{
	int a[4],mx,mn,mi;
	void getm()
	{
		a[0]=inf;
		mn=0;
		for(int i=1;i<=3;i++)
			if(a[i]<a[mn])
				mn=i;
		a[0]=-1;
		mx=0;
		for(int i=1;i<=3;i++)
			if(i!=b&&a[i]>=a[mx])
				mx=i;
		mi=6-mx-mn;
	}
}s[N];
bool cmp(Stu x,Stu y)
{
	return x.a[x.mx]-x.a[x.mi]>y.a[y.mx]-y.a[y.mi];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		ans=0;
		b=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				cin>>s[i].a[j];
			s[i].getm();
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(cnt[s[i].mx]>=n/2)
			{
				b=s[i].mx;
				for(int j=i;j<=n;j++)
					s[j].getm();
			}
			ans+=s[i].a[s[i].mx];
			cnt[s[i].mx]++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
