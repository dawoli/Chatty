#include<bits/stdc++.h>
using namespace std;
long long n[1000002];
long long jilu[1000002];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout); 
	int t;
	long long cnt=1;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i];
		
	}
	for(int i=1;i<=t;i++)
	{
		for(int j=n[i]/2;j>=2;j--)
		{
			while(n[i]%j==0)
			{
				jilu[cnt]=j;
				cnt++;
				n[i]/=j;
			}
		}
		jilu[cnt]=n[i];
		for(int g=1;g<=cnt;g++)
		{
			if(jilu[g]==2)
			{
				cout<<1;
				jilu[g]=0;
			}
			else if(jilu[g]==3)
			{
				cout<<7;
				jilu[g]=0;	
			}
			else if(jilu[g]==4)
			{
				cout<<4;
				jilu[g]=0;	
			}
			else if(jilu[g]==5)
			{
				cout<<2;
				jilu[g]=0;	
			}
			else if(jilu[g]==6)
			{
				cout<<0;
				jilu[g]=0;	
			}
			else if(jilu[g]==7)
			{
				cout<<8;
				jilu[g]=0;	
			}
			else
			{
				cout<<-1;
			}
			
		}
		cout<<endl;

		cnt=1;
	}
	
	return 0;
 } 
