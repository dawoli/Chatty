#include<bits\stdc++.h>
using namespace std;
int abc(int x,int y)
{
	int p=1;
	for (int i=0;i<y;i++)
	{
		p*=x;
	}
	return p;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	int m[51];
	int f[10]={6,2,5,5,4,5,6,3,7,6};
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>m[i];
	}
	for (int w=0;w<n;w++)
	{
		int a=m[w];
		int t=0;
		if (a<=1) 
		{
			cout<<-1<<endl;
			continue;
		}
		if (a%7==0) 
		{
			t=a/7;
			for (int i=0;i<t;i++)
			{
				cout<<8;
			}
			continue;
		}
		if (a%7!=0)
		{
			int l=1;
			int r=9;
			int mini=10000000;
			t=a/7+1;
			for (int i=0;i<t-1;i++)
			{
				l*=10;
				r=r*10+9;	
			}
			for (int i=l;i<=r;i++)
			{
				int count=0;
				count+=i%10;
				for (int j=1;j<t;j++)
				{
					int p=abc(10,j);
					count+=f[i/abc(10,j)%10];
				}
				if (count==a&&count<mini) 
				{
					mini=count;
				}
			}
			cout<<mini;
			continue;
		}
		if (a==2) 
		{
			cout<<"1"<<endl;
		}	
		if (a==3) 
		{
			cout<<"7"<<endl;
		}		
		if (a==4) 
		{
			cout<<"4"<<endl;
		}		
		if (a==5) 
		{
			cout<<"2"<<endl;
		}			
		if (a==6) 
		{
			cout<<"6"<<endl;
		}		
		if (a==7) 
		{
			cout<<"8"<<endl;
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
