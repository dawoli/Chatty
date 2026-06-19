#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,b,c,d;
	cin>>n>>m;
	for(b=0;b<n*m;b++)
	{
		cin>>a[b];
	}
	d=a[0];
	for(int i=1;i<=b;i++)
	{
		for(int j=i;j>=0;j--)
		{
			if(a[i]>a[j])
			{
				int x=a[i];
				a[i]=a[j];
				a[j]=x;
			}
		} 
	}
	for(int i=0;i<=b;i++)
	{
		if(a[i]==d)
		{
			c=i;
			break;
		}
	}
	cout<<c/n+1<<" ";
	if((c/n+1)%2==0)
	{
		cout<<n-c%n;
	}
	else
	{
		cout<<c%n+1;
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
