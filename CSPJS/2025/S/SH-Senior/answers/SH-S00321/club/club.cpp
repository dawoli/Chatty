#include<bits/stdc++.h>
using namespace std;

int t;
struct Node
{
	long long a1,a2,a3;
	int n1,n2,n3;
}a[100005];
bool cmp(Node c,Node d)
{
	return c.a1>d.a1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out.exe","w",stdout);
	cin >>t;
	for(int i = 1;i <= t;i++)
	{
		int sum=0;
		long long n;
		cin >>n;
		for(int j = 1;j <= n;j++)
		{
			cin >> a[j].a1 >> a[j].a2 >> a[j].a3;
			a[j].n1=1,a[j].n2=2,a[j].n3=3;
		}
		long long cnt1=0,cnt2=0,cnt3=0;
		for(int j = 1;j <= n;j++)
		{
			int x=a[j].a1;
			int y=a[j].a2;
			int z=a[j].a3;
			if(x>y&&y>z)
			{
				
			}
			else if(x>z&&z>y)
			{
				a[j].a1=x;
				a[j].a2=z;
				a[j].a3=y;
				a[j].n1=1;
				a[j].n2=3;
				a[j].n3=2;
			}
			else if(y>x&&x>z)
			{
				a[j].a1=y;
				a[j].a2=x;
				a[j].a3=z;
				a[j].n1=2;
				a[j].n2=1;
				a[j].n3=3;
			}
			else if(y>z&&z>x)
			{
				a[j].a1=y;
				a[j].a2=z;
				a[j].a3=x;
				a[j].n1=2;
				a[j].n2=3;
				a[j].n3=1;
			}
			else if(z>x&&x>y)
			{
				a[j].a1=z;
				a[j].a2=x;
				a[j].a3=y;
				a[j].n1=3;
				a[j].n2=1;
				a[j].n3=2;
			}
			else if(z>y&&y>x)
			{
				a[j].a1=z;
				a[j].a2=y;
				a[j].a3=x;
				a[j].n1=3;
				a[j].n2=2;
				a[j].n3=1;
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int j = 1;j <= n;j++)
		{
			if(a[j].n1==1)
			{
				if(cnt1==n/2)
				{
					if(a[j].n2==2)
					{
						if(cnt2==n/2)
						{
							cnt3++;
							sum+=a[j].a3;
						}
						else
						{
							cnt2++;
							sum+=a[j].a2;
						}
					}
					else if(a[j].n2==3)
					{
						if(cnt3==n/2)
						{
							cnt2++;
							sum+=a[j].a3;
						}
						else
						{
							cnt3++;
							sum+=a[j].a2;
						}
					}
				}
				else
				{
					cnt1++;
					sum+=a[j].a1;
				}
			}
			else if(a[j].n1==2)
			{
				if(cnt2==n/2)
				{
					if(a[j].n2==1)
					{
						if(cnt1==n/2)
						{
							cnt3++;
							sum+=a[j].a3;
						}
						else
						{
							cnt1++;
							sum+=a[j].a2;
						}
					}
					else if(a[j].n2==3)
					{
						if(cnt3==n/2)
						{
							cnt1++;
							sum+=a[j].a3;
						}
						else
						{
							cnt3++;
							sum+=a[j].a2;
						}
					}
				}
				else
				{
					cnt2++;
					sum+=a[j].a1;
				}
			}
			else if(a[j].n1==3)
			{
				if(cnt3==n/2)
				{
					if(a[j].n2==1)
					{
						if(cnt1==n/2)
						{
							cnt2++;
							sum+=a[j].a3;
						}
						else
						{
							cnt1++;
							sum+=a[j].a2;
						}
					}
					else if(a[j].n2==2)
					{
						if(cnt2==n/2)
						{
							cnt1++;
							sum+=a[j].a3;
						}
						else
						{
							cnt2++;
							sum+=a[j].a2;
						}
					}
				}
				else
				{
					cnt3++;
					sum+=a[j].a1;
				}
			}
		}
		cout <<sum<<endl;
	}
	return 0;
 } 
