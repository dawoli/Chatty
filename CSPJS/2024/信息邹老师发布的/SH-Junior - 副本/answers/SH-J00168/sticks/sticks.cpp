#include<bits/stdc++.h>
using namespace std;
int num[1000];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n<=1)
		{
			cout<<-1<<endl;
			continue;
		}
		for(int i=n-1;;i++)
		{
			int a=i,k=1,sum=0;
			while(a>0)
			{
				num[k++]=a%10;
				a/=10;
			}
			for(int j=1;j<k;j++)
			{
				if(num[j]==1) sum+=2;
				else if(num[j]==2) sum+=5;
				else if(num[j]==3) sum+=5;
				else if(num[j]==4) sum+=4;
				else if(num[j]==5) sum+=5;
				else if(num[j]==6) sum+=6;
				else if(num[j]==7) sum+=3;
				else if(num[j]==8) sum+=7;
				else if(num[j]==9) sum+=6;
				else if(num[j]==0) sum+=6;
			}
			if(n==sum)
			{
				cout<<i<<endl;
				sum=0;
				break;
			}
		}
	}
	return 0;
}
