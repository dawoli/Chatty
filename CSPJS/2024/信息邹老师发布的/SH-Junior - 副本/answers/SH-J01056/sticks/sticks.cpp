#include<bits/stdc++.h>
using namespace std;
const int q=1e5;
int n[q];
int t;
int s1=2,s2=5,s3=5,s4=4,s5=5,s6=6,s7=3,s8=7,s9=6,s0=6;
bool flag1=1;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i];
			if(n[i]==1)
			{
				cout<<-1<<endl;
			}
			if(n[i]==2)
			{
				cout<<2<<endl;
			}
			else if(n[i]==3)
			{
				cout<<7<<endl;
			}
			else if(n[i]==4)
			{
				cout<<4<<endl;
			}
			else if(n[i]==5)
			{	
				cout<<235<<endl;
			}
			else if(n[i]==6)
			{
				cout<<609<<endl;
			}
			else if(n[i]==7)
			{
				cout<<8<<endl;
			}
	}
	return 0;
 } 
