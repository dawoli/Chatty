#include<bits/stdc++.h>
using namespace std;
int number[10]={0,1,2,3,4,5,6,7,8,9};
int number_size[10]={6,2,5,5,4,5,6,3,7,6};
int n,t,each,tt,sum;
bool flag=0;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		flag=0;
		sum=0;
		cin>>n;
		if(n==1)
		{
			cout<<-1;
			continue;
		}
		for(int j=1;j<=100000;j++)
		{
			sum=0;
			tt=j;
			while(tt>0)
			{
				each=tt%10;
				for(int k=0;k<10;k++)
				{
					if(each==number[k]) sum+=number_size[k];
				}
				tt/=10;
			}
			if(sum==n)
			{
				cout<<j<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0) cout<<-1<<endl;
	}
	return 0;
}
