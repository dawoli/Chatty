#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d=10000000;
void A(long long x,long long y)
{
	if(x<0)
	{
		return ;
	}
	else if(x==0)
	{
		if(y<d)
		{
			d=y;
		}
		return ;
	}
	A(x-2,y*10+1);
	A(x-3,y*10+7);
	A(x-4,y*10+4);
	A(x-5,y*10+2);
	if(x!=b)
	{
		A(x-6,y*10+0);
	}
	else
	{
		A(x-6,y*10+6);
	}
	A(x-7,y*10+8);
	return;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b;
//		if(b%7==1)
//		{
//			cout<<"10";
//			for(int j=1;j<=b/7-2;j++)
//			{
//				cout<<"8";
//			}
//			cout<<endl;
//		}
//		else if(b%7==0)
//		{
//			for(int j=1;j<=b/7;j++)
//			{
//				cout<<"8";
//			}
//			cout<<endl;
//		}
//		else
//		{
			A(b,0);
			if(d==10000000)
			{
				cout<<"-1"<<endl;
			}
			else
			{
				cout<<d<<endl;
			}
			d=10000000;
//		}
	}
	return 0;
}
