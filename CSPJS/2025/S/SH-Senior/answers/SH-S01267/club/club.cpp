#include<bits/stdc++.h>
using namespace std;
int sum,n;
struct str
{
	int a1,a2,a3;
}a[100010];
int cnt1,cnt2,cnt3;
bool cmp(str x,str y)
{
	if(x.a1<y.a1) return true;
	if(x.a1==y.a1&&x.a2<y.a2) return true;
	if(x.a1==y.a1&&x.a2==y.a2&&x.a3>=y.a3) return true;
	return false;
}
int dps(int now,int s,int t1,int t2,int t3)
{
	int c1=0,c2=0,c3=0;
	if(s>n)return now;
	if(t1<n/2)c1=dps(now+a[n-s+1].a1,s+1,t1+1,t2,t3);
	if(t2<n/2)c2=dps(now+a[n-s+1].a2,s+1,t1,t2+1,t3);
	if(t3<n/2)c3=dps(now+a[n-s+1].a3,s+1,t1,t2,t3+1);
	return max(max(c1,c2),c3);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a+1,a+n+1,cmp);
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			if(!a[i].a2||!a[i].a3)flag=false;
		} 
		if(flag)
		{
			for(int i=1;i<=n/2;i++)sum+=a[i].a1;
			cout<<sum<<endl;
			continue;
		}
		cout<<dps(0,1,0,0,0)<<endl;
	}
	return 0;
} 
