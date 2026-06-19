#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[100100],b[100100],c[100100],sum1,sum2,sum3,a1,b1,c1,ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int t1=1;t1<=t;t1++)
	{
		cin>>n;
		ans=0;
		sum1=0;sum2=0;sum3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a1>>b1>>c1;
			if(a1>=b1&&a1>=c1)
			{
				sum1++;
				a[sum1]=a1-max(b1,c1);
				ans+=a1;
			} 
			else if(b1>=c1)
			{
				sum2++;
				b[sum2]=b1-max(a1,c1);
				ans+=b1;
			} 
			else
			{
				sum3++;
				c[sum3]=c1-max(a1,b1);
				ans+=c1;
			} 
		}
		if(sum1>=sum2&&sum1>=sum3)
		{
			if(sum1>n/2)
			{
				sort(a+1,a+sum1+1);
					int kk=sum1-n/2;
				for(int i=1;i<=kk;i++)
					ans-=a[i];
			}
		}
		else if(sum2>=sum3)
		{
			if(sum2>n/2)
			{
				sort(b+1,b+sum2+1);
				int kk=sum2-n/2;
				for(int i=1;i<=kk;i++)
					ans-=b[i];
				}
		}
		else
		{
			if(sum3>n/2)
			{
				sort(c+1,c+sum3+1);
				int kk=sum3-n/2;
				for(int i=1;i<=kk;i++)
					ans-=c[i];
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
