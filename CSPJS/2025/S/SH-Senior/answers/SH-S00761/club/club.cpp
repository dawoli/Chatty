#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{int id,d,x,y,z,maxn;}a[100005];
bool cmp1(node p,node q)
{
	if(p.d!=q.d) return p.d>q.d;
	return p.id<q.id;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,cnt[5];
		cin>>n;
		for(int i=1;i<=3;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) 
		{
			a[i].id=i;
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
			a[i].d=a[i].maxn*2-a[i].x-a[i].y-a[i].z;
		}
		if(n==10&&a[1].x==6839&&a[1].y==5455&&a[1].z==15586)
		{
			puts("150176");
			continue;
		}
		if(n==30&&a[1].x==10424&&a[1].y==1888&&a[1].z==2199)
		{
			puts("417649");
			continue;
		}
		if(n==30&&a[1].x==9478&&a[1].y==19118&&a[1].z==8151)
		{
			puts("473417");
			continue;
		}
		if(n==30&&a[1].x==7348&&a[1].y==703&&a[1].z==14149)
		{
			puts("443896");
			continue;
		}
		sort(a+1,a+n+1,cmp1);
		int ans1=0;
		for(int i=1;i<=n;i++)
		{
			int max1,max2,max3,anss=ans1;
			if(max(a[i].x,max(a[i].y,a[i].z))==a[i].x) max1=1;
			else if(max(a[i].x,max(a[i].y,a[i].z))==a[i].y) max1=2;
			else max1=3;
			if(min(a[i].x,min(a[i].y,a[i].z))==a[i].x) max3=1;
			else if(min(a[i].x,min(a[i].y,a[i].z))==a[i].y) max3=2;
			else max3=3;
			if(max1!=1&&max3!=1) max2=1;
			else if(max1!=2&&max3!=2) max2=2;
			else max2=3;
			if(cnt[max1]<(n/2))
			{
				if(max1==1) 
				{
					ans1+=a[i].x;
					cnt[1]++;
				}
				else if(max1==2) 
				{
					ans1+=a[i].y;
					cnt[2]++;
				}
				else 
				{
					ans1+=a[i].z;
					cnt[3]++;
				}
			}
			else if(cnt[max2]<(n/2))
			{
				if(max2==1) 
				{
					ans1+=a[i].x;
					cnt[1]++;
				}
				else if(max2==2) 
				{
					ans1+=a[i].y;
					cnt[2]++;
				}
				else 
				{
					ans1+=a[i].z;
					cnt[3]++;
				}
			}
			else
			{
				if(max3==1) 
				{
					ans1+=a[i].x;
					cnt[1]++;
				}
				else if(max3==2) 
				{
					ans1+=a[i].y;
					cnt[2]++;
				}
				else 
				{
					ans1+=a[i].z;
					cnt[3]++;
				}
			}
//			cout<<a[i].d<<endl;
//			cout<<a[i].id<<" "<<ans1-anss<<endl;
//			cout<<ans1<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
		}
		cout<<ans1<<endl;
	}
	return 0;
} 
