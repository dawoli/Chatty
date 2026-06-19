#include<iostream>
using namespace std;
int stk[6]={6,2,5,4,3,7};
int num[6]={0,1,2,4,7,8};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t; cin>>t;
	while (t--)
	{
		int n; cin>>n;
		if(n<=1) cout<<-1;
		else if (n==6) cout<<6;
		else if (n%7==1)
		{
			cout<<10;
			int len=(n-1)/7-1;
			for (int i=0;i<len;i++) cout<<8;
		}
		else
		{
			int len=(n-1)/7+1;
			for (int j=1;j<6;j++)
			{
				int t=(n-1-stk[j])/7+1;
				if (len==1) 
				{
					if (n==stk[j])
					{
						cout<<num[j];
						n-=stk[j];
						len--;
						break;
					 } 
				}
				else if (t==len-1)
				{
					n-=stk[j];
					cout<<num[j];
					len--;
					break;
				}
			}
			while (len)
			{
				for (int j=0;j<6;j++)
				{
					int t=(n-1-stk[j])/7+1;
					if (len==1) 
					{
						if (n==stk[j])
						{
							cout<<num[j];
							len--;
							break;
					 	} 
					}
					else if (t==len-1)
					{
						n-=stk[j];
						cout<<num[j];
						len--;
						break;
					}
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
