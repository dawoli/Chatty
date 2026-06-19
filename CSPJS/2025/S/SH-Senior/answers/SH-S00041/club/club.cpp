#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int T,n,a[100005][4];
int club1[100005],club2[100005],club3[100005],cc1,cc2,cc3;//三个club里存的是把这个人从这个club移走后会损失多少（负数） 
ll ans=0;
int ghc(int a,int b,int c)	//get_highest_club
{
//	cout<<a<<" "<<b<<" "<<c<<"\n";
	if(a>=b&&a>=c)
		return 1;
	if(b>=a&&b>=c)
		return 2;
	return 3;
}
bool cmp1(int x,int y)
{
	return x>y;
}
bool cmp2(int x,int y)
{
	return x>y;
}
bool cmp3(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		cc1=0,cc2=0,cc3=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int k=ghc(a[i][1],a[i][2],a[i][3]);
			if(k==1)
				club1[++cc1]=max(a[i][2],a[i][3])-a[i][1],ans+=a[i][1];
			else if(k==2)
				club2[++cc2]=max(a[i][1],a[i][3])-a[i][2],ans+=a[i][2];
			else
				club3[++cc3]=max(a[i][1],a[i][2])-a[i][3],ans+=a[i][3];
		}
//		cout<<111111111<<endl;
		sort(club1+1,club1+1+cc1,cmp1);
		sort(club2+1,club2+1+cc2,cmp2);
		sort(club3+1,club3+1+cc3,cmp3);
//		cout<<222222222<<endl;
//		cout<<cc1<<" "<<cc2<<" "<<cc3<<endl;
		if(cc1>n/2)
		{
			int d=cc1-n/2;
			for(int i=1;i<=d;i++)
				ans+=club1[i];
//			cout<<ans<<endl;
		}
		else if(cc2>n/2)
		{
			int d=cc2-n/2;
			for(int i=1;i<=d;i++)
				ans+=club2[i];
//			cout<<ans<<endl;
		}
		else
		{
			int d=cc3-n/2;
			for(int i=1;i<=d;i++)
				ans+=club3[i];
//			cout<<ans<<endl;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
