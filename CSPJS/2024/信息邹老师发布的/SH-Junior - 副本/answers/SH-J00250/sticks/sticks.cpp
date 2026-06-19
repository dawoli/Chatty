#include<bits/stdc++.h>
using namespace std;
const int numbers[10]={6,2,5,5,4,5,6,3,7,6};
int num[10];
int n,T;
int getnum(int a)
{
	int i=0;
	while(a)
	{
		num[i]=a%10;
		a/=10;
		i++;
	}
	return i;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n;
		if(n<2)
		{
			cout<<-1<<endl;
		}
		else
		{
			bool flag=true;
			for(int j=0;j<=100001;j++)
			{
				int size=getnum(j);
				int numstick=0;
				for(int k=0;k<size;k++)
				{
					numstick+=numbers[num[k]];
				}
				if(numstick==n)
				{
					cout<<j<<endl;
					flag=false;
					break;
				}
			}
			if(flag)
			  cout<<-1<<endl;
		}
	}
	return 0;
} 
