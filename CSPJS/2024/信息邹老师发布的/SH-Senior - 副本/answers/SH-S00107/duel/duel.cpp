#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int m=n;
	int a[n];
	int b[n];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i =1;i<=n;i++)
	{
		a[i]=b[i];
	}
	for(int i=1;i<=n;i++)
	{
		int min=i;
		for(int j=i;j<=n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		swap(a[min],a[i]);
	}
	int c[n];
	int flag=0;
	int min=a[1];
	for(int i=1;i<=n;i++)
	{
		
		if(min==a[i])
		{
			flag+=1;
		}
		else
		{
			c[i-1]=flag;
			flag=0;
			min=a[i];
			flag+=1;
		}
	}
	
	c[n]=flag;
	int d[n]={0};
	flag=1;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=0)
		{
			d[flag]=c[i];
			flag++;
		}
	}
	if(d[2]==0)
	{
		cout<<n;
	}
	else
	{
		if(d[1]>d[2])
		{
			sum+=d[1]-d[2];
		}
		else
		{
			m-=d[1];
		}
	}
	int i=2;
	while(d[i]!=0)
	{
		if(d[i]<=d[i+1])
		{
			m-=d[i];
		}
		else
		{
			m-=d[i+1];
			sum+=d[i]-d[i+1];
		}
		if(d[i+1]>sum)
		{
			m-=sum;
			sum=0;                                                                                                                                                                                                                                                                          
		}
		i++;
	}
	cout<<m;
	return 0;
	
}
