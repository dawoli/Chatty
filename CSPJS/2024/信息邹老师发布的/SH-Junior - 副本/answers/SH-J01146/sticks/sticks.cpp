#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int a[11][2]={0,1,2,3,4,5,6,7,8,9};
	a[0][1]=6;
	a[1][1]=2;
	a[2][1]=5;
	a[3][1]=5;
	a[4][1]=4;
	a[5][1]=5;
	a[6][1]=6;
	a[7][1]=3;
	a[8][1]=7;
	a[9][1]=6;
	int t;
	cin>>t;
	while(t--)
	{
		int n,shuwei;
		cin>>n;
		if(n<2) cout<<"-1"<<endl;
	    else if(n%7==0)
		{
			do
			{
				n/=7;
				cout<<"8";
			}
			while(n);
		 } 
		else 
		{
			int d=n%7;
			for(int e=0;e<=11;e++)
			{
				if (a[e][1]==d&&a[e][1]!=0) 
				{
					cout<<a[e][1];
					n-=e;
					break;
				 } 
				
			}
			shuwei = n/7;
		
			while (shuwei--)
			{	
				if(n%7==0)
				{	
					while(n)
					{
						n/=7;
						cout<<"8";
						break;
					}
				}
			
			}
		}
		cout<<endl;
	}
	return 0;
 } 
