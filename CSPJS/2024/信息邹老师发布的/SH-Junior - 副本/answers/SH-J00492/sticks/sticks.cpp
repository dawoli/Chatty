#include<bits/stdc++.h>
using namespace std;

int t,n;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int w;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<2)
		{
			cout<<-1<<endl;
			continue;
		}
		w=ceil(1.0*n/7);
		
		for(int i=w-1;i>=0;i--)
		{
			int minn=10;
			for(int j=0;j<10;j++)
			{
				if(j==0&&i==w-1)
				{
					continue;
				}
				if(n>=num[j]&&j<minn&&n-num[j]<=i*7)
				{
					minn=j;
				}
			}
			cout<<minn;
			n-=num[minn];
		}
		cout<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5
1
2
3
6
18
*/
