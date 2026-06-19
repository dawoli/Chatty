#include<bits/stdc++.h>
using namespace std;
int t,nn,n[5],x,y,z;
long long ans;
struct
{
	int max1,max2,max3,maxn1,maxn2,maxn3;
}a[100100];
bool sort()
{
	int q;
	for(int i=1;i<=nn;i++)
	{
		for(int j=1;j<nn;j++)
		{
			if(a[j].max1-a[j].max2<a[j+1].max1-a[j+1].max2)
			{
				q=a[j].max1;
				a[j].max1=a[j+1].max1;
				a[j+1].max1=q;
				q=a[j].max2;
				a[j].max2=a[j+1].max2;
				a[j+1].max2=q;
				q=a[j].max3;
				a[j].max3=a[j+1].max3;
				a[j+1].max3=q;
				q=a[j].maxn1;
				a[j].maxn1=a[j+1].maxn1;
				a[j+1].maxn1=q;
				q=a[j].maxn2;
				a[j].maxn2=a[j+1].maxn2;
				a[j+1].maxn2=q;
				q=a[j].maxn3;
				a[j].maxn3=a[j+1].maxn3;
				a[j+1].maxn3=q;
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		n[1]=0;
		n[2]=0;
		n[3]=0;
		ans=0;
		cin>>nn;
		for(int j=1;j<=nn;j++)
		{
			cin>>x>>y>>z;
			if(x>=y && x>=z) {
				a[j].max1=x;
				a[j].maxn1=1;
				if(y>=z){
					a[j].max2=y;
					a[j].maxn2=2;
					a[j].max3=z;
					a[j].maxn3=3;
				}
				else{
					a[j].max2=z;
					a[j].maxn2=3;
					a[j].max3=y;
					a[j].maxn3=2;
				}
			}
			else{
				if(y>=x && y>=z)
				{
					a[j].max1=y;
					a[j].maxn1=2;
					if(x>=z){
					a[j].max2=x;
					a[j].maxn2=1;
					a[j].max3=z;
					a[j].maxn3=3;
				}
				else{
					a[j].max2=z;
					a[j].maxn2=3;
					a[j].max3=x;
					a[j].maxn3=1;
				}
				}
				else
				{
					a[j].max1=z;
					a[j].maxn1=3;
					if(y>=x){
					a[j].max2=y;
					a[j].maxn2=2;
					a[j].max3=x;
					a[j].maxn3=1;
				}
				else{
					a[j].max2=x;
					a[j].maxn2=1;
					a[j].max3=y;
					a[j].maxn3=2;
				}
				}
			}
		}
		sort();
		for(int j=1;j<=nn;j++)
		{
			if(n[a[j].maxn1]<nn/2)
			{
				ans+=a[j].max1;
				n[a[j].maxn1]++;
			}
			else
			{
				if(n[a[j].maxn2]<nn/2)
			{
				ans+=a[j].max2;
				n[a[j].maxn2]++;
			}
			else
			{
				ans+=a[j].max3;
				n[a[j].maxn3]++;
			}
			}
		}
		cout<<ans<<endl;
		for(int j=1;j<=nn;j++)
		{
			a[j].max1=0;
			a[j].max2=0;
			a[j].max3=0;
			a[j].maxn1=0;
			a[j].maxn2=0;
			a[j].maxn3=0;
		}
	}
	return 0;
}
