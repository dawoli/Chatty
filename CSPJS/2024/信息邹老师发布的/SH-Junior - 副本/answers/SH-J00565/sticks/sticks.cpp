#include<bits/stdc++.h>
using namespace std;
long long n,sum;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>sum;
		if(sum==1)
		{
			cout<<"-1"<<endl;
		} 
		if(sum==2) cout<<1<<endl;
		if(sum==3) cout<<7<<endl;
		if(sum==4) cout<<4<<endl;
		if(sum==5) cout<<2<<endl;
		if(sum==6) cout<<6<<endl;
		if(sum==7) cout<<8<<endl;
		if(sum==9) cout<<24<<endl;
		if(sum==10) cout<<22<<endl;
		if(sum==11) cout<<20<<endl;
		if(sum==12) cout<<28<<endl;
		if(sum==13) cout<<68<<endl;
		if(sum==16) cout<<202<<endl;
		if(sum==17) cout<<200<<endl;
		if(sum==18) cout<<208<<endl;
		if(sum==19) cout<<288<<endl;
		if(sum==20) cout<<688<<endl;
		else if(sum>7 && sum%7==0)
		{
			for(int j=1;j<=sum/7;j++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else if(sum>7 && sum%7==1)
		{
			for(int j=1;j<=(sum-8)/7;j++)
			{
				cout<<8;
			}
			cout<<10;
			cout<<endl;
		}
	}
	return 0;
} 
