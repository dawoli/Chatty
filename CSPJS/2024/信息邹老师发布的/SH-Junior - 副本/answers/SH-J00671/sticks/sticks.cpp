#include<bits/stdc++.h>
using namespace std;
int t,n,w,y,a[25]={0,-1,1,7,4,2,6,8,16,18,22,20,28,68,88,108,188,200,208,288,488};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n;
		if(n==1)  {cout<<a[1]<<endl;continue;}
		if(n==2)  {cout<<a[2]<<endl;continue;}
		if(n==3)  {cout<<a[3]<<endl;continue;}
		if(n==4)  {cout<<a[4]<<endl;continue;}
		if(n==5)  {cout<<a[5]<<endl;continue;}
		if(n==6)  {cout<<a[6]<<endl;continue;}
		if(n==7)  {cout<<a[7]<<endl;continue;}
		if(n==8)  {cout<<a[8]<<endl;continue;}
		if(n==9)  {cout<<a[9]<<endl;continue;}
		if(n==10)  {cout<<a[10]<<endl;continue;}
		if(n==11)  {cout<<a[11]<<endl;continue;}
		if(n==12)  {cout<<a[12]<<endl;continue;}
		if(n==13)  {cout<<a[13]<<endl;continue;}
		if(n==14)  {cout<<a[14]<<endl;continue;}
		if(n==15)  {cout<<a[15]<<endl;continue;}
		if(n==16)  {cout<<a[16]<<endl;continue;}
		if(n==17)  {cout<<a[17]<<endl;continue;}
		if(n==18)  {cout<<a[18]<<endl;continue;}
		if(n==19)  {cout<<a[19]<<endl;continue;}
		if(n==20)  {cout<<a[20]<<endl;continue;}
		if(n%7==0)
		{
			w=n/7;
			for(int i=1;i<=w;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else
		{
			w=n/7-1;y=n%7+7;
			if(y==10)
			{
				w--;
				cout<<200;
				for(int i=1;i<=w;i++)
				{
					cout<<8;
				}
				cout<<endl;
				continue;
			}
			cout<<a[y];
			for(int i=1;i<=w;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
	}
	return 0;
}
