#include<bits/stdc++.h>
using namespace std;
struct nmnm
{
	int x,y,z,c,choice;
};
int cmp(nmnm n,nmnm m)
{
	return n.c<m.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int www=1;www<=n;www++)
	{
		nmnm a[100100];
		int m;
		cin>>m;
		int t1=0,t2=0,t3=0;
		int t=m/2;
		for(int i=1;i<=m;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].choice=0;
			a[i].c=0;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				t1++;
				int l=a[i].x-a[i].y;
				int r=a[i].x-a[i].z;
				a[i].choice=1;
				a[i].c=min(l,r);
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				t2++;
				int l=a[i].y-a[i].x;
				int r=a[i].y-a[i].z;
				a[i].choice=2;
				a[i].c=min(l,r);
			}
			else if(a[i].z>=a[i].y&&a[i].z>=a[i].x){
				t3++;
				int l=a[i].z-a[i].x;
				int r=a[i].z-a[i].y;
				a[i].choice=3;
				a[i].c=min(l,r);
			}
			
		}
//		int bei=999999;
		long long ans=0;
		if(t1>t)
		{
			sort(a,a+m+1,cmp);
			int s=1;
			for(int i=1;i<=t1-t;i++)
			{
				while(a[s].choice!=1) s++;
				ans-=a[s].c;
				s++;
//				bei=min(abs(a[s].l-a[s].r));
			}
			
		}
		else if(t2>t)
		{
			sort(a,a+m+1,cmp);
			int s=1;
			for(int i=1;i<=t2-t;i++)
			{
				while(a[s].choice!=2) s++;
				ans-=a[s].c;
				s++;
//				bei=min(abs(a[s].l-a[s].r));
			}
		}
		else if(t3>t)
		{
			sort(a,a+m+1,cmp);
			int s=1;
			for(int i=1;i<=t3-t;i++)
			{
				while(a[s].choice!=3) s++;
				ans-=a[s].c;
				s++;
//				bei=min(abs(a[s].l-a[s].r));
			}
		}
		
		for(int i=1;i<=m;i++)
		{
//			cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<" "<<a[i].choice<<endl;
			if(a[i].choice==1)
			{
				ans+=a[i].x;
			}
			else if(a[i].choice==2)
			{
				ans+=a[i].y;
			}
			else if(a[i].choice==3)
			{
				ans+=a[i].z;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
