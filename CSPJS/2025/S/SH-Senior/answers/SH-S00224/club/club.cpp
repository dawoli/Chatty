#include<bits/stdc++.h>
using namespace std;

int v=0,a[10001],b[10001],c[10001],cnt=0,m=0,a1=0,b1=0,c1=0;
int xunhuan(int n,int j)
{
	int i=0;
	if(j==n)
	{
		if(v>m)
		{
			m=v;
		}
		if(i==0)
		{
			v=v-a[j];
			a1=a1-1;
		}
		if(i==1)
		{
			v=v-b[j];
			b1=b1-1;
		}
		if(i==2)
		{
			v=v-c[j];
			c1=c1-1;
		}
		cout<<v<<endl;
		return 0;
	}
	for(;i<3;i++)
	{
		if(i==0&&a1!=0.5*n)
		{
			v=v+a[j];
			a1++;
		}
		if(i==1&&b1!=0.5*n)
		{
			v=v+b[j];
			b1++;
		}
		if(i==2&&c1!=0.5*n)
		{
			v=v+c[j];
			c1++;
		}
		xunhuan(n,j+1);
	}

}
int main()
{
	freopen("club1.in","r",stdin);//¼ÇµÃÉ¾ 
	freopen("club.out","w",stdout);
	int t,n,cnt=0,daan[n+1];
	int f=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		xunhuan(n,0);
		daan[i]=m;
		cnt=0;
		
	}
	for(int i=0;i<t;i++)
	{
		cout<<daan[i]<<endl;
	}
	
	return 0;
}
