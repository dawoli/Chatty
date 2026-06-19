#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	int x;
	int t[10]={6,2,5,5,4,5,6,3,7,6};
	cin>>n;
	for(int i =1;i<=n;i++)
	{
		cin>>x;
		if(x==1)
		{
			cout<<-1;
		}
		if(x<=7)
		{
			for(int m=1;m<9;m++)
			{
				if(t[m]==x)
					cout<<m<<endl;
					
			}
		}
		if(x<=13&&x>7)
		{
			for(int m=1;m<9;m++)
			{
				for(int j =0;j<=9;j++)
				{
					if(t[m]+t[j]==x)
						cout<<m<<j<<endl;
						break;
				}
				
			}
		}
		if(x>13&&x<=19)
			for(int m =1;m<=9;m++)
			{
				for(int j =0;j<=9;j++)
				{
					for(int k=0;k<=9;k++)
					{
						if(t[m]+t[j]+t[k]==x)
						{
							cout<<m<<j<<k<<endl;
							return 0;
						}
						
					}
					
				}
				
				
			}
		if(x>19&&x<=25)
			for(int m =1;m<=9;m++)
			{
				for(int j =0;j<=9;j++)
				{
					for(int k=0;k<=9;k++)
					{
						for(int q=0;q<=9;q++ )
							if(t[m]+t[j]+t[k]+t[q]==x)
							{
								cout<<m<<j<<k<<q<<endl;
								return 0;
							}
							
					}
					
				}
				
				
			}
			
	}
	return 0;

}
