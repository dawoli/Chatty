#include "bits/stdc++.h"
using namespace std;
int sticks[11]={6,2,5,5,4,5,6,3,7,6};
int po(int n,int t)
{
	int res=n;
	if(t==0)
	{
		return 1;
	 } 
	for(int i=0;i<t-1;i++)
	{
		res*=res; 
	}
	return res;
}
int main()
{
	int T,n,temp,tru[1000],t=0,max,stick=0;
	cin>>T;
	max=10000000;
	for(int j=0;j<T;j++)
	{
		cin>>n;
		temp=n/7;
//		cout<<n/7;
		if(n<2)
		{
			cout<<-1;
			continue;
		}
		if(n<=7)
		{
			if(n==5)
			{
				cout<<2;
				continue;
			}
			if(n==6)
			{
				cout<<6;
				continue;
			}
			if(n==2)
			{
				cout<<1;
				continue;
			}
			if(n==4)
			{
				cout<<4;
				continue;
			}
			if(n==3)
			{
				cout<<7;
				continue;
			}
			if(n==7)
			{
				cout<<8;
				continue;
			}
		}
		else
		{
			printf("n/7:%d\n",n/7);
			for(int i=pow(10,n/7);i<pow(10,n/7+1);i++)
			{
//			for(int i=1;i<10;i++)
//			{
				
			
				stick=0;
//				printf("i:%d\n",i);
				for(int k=0;k<n/7;k++)
				{
					int z,p=n/7;
					z=i%po(10,n/7);
//					printf("z:%d   ",z);
					stick+=sticks[z];
					p=p-1;
				}
//				printf("stick:%d   ",stick);
				if(stick==n)
				{
//					printf("max:%d  ",i);
					tru[t]=i;
					t++;
					if(max>i)
					{
						max=i;
					}
				}
				
			}
		}
		cout<<max;
	}
	return 0;
 } 
