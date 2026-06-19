#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,js[10]={6,2,5,5,4,5,6,3,7,6};
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int a;
		cin>>a;
		if(a<2)
		{
			cout<<-1<<endl;
		}
		else if(a<=7)
		{
			for(int q=1;q<=9;q++)
			{
				if(js[q]==a)
				{
					cout<<q<<endl;
					break;
				}
			}
		}
		else
		{
			int w=(a-a%7)/7+1,c=a%7+7,ans1,ans2;
			bool tf=1;
			for(int p=1;p<=9;p++)
			{
				for(int q=0;q<=9;q++)
				{
					if(js[p]+js[q]==c)
					{
						tf=0;
						ans1=p;
						ans2=q;
						break;
					}
				}
				if(tf==0)
				{
					break;
				}
			}
			cout<<ans1<<ans2;
			for(int ttt=1;ttt<=w-2;ttt++)
			{
				cout<<8;
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
