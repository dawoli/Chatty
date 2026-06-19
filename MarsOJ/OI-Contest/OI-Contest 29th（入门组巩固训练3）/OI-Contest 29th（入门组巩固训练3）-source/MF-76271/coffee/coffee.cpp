#include <bits/stdc++.h>
using namespace std;
long long t,ans;
long long day,m;
string schedule[10][10];
int main()
{
	freopen("coffee.in","r",stdin);//需要额外添加的
	freopen("coffee.out","w",stdout);//需要额外添加的
	cin>>t;
	while(t--)
	{
		int math_cnt[7]={0}; 
		int weak_math=0; 
		int first_weak=0;
		int end_weak=0;
		int sum=0;
		memset(math_cnt,0,sizeof(math_cnt));
		for(int i=1;i<=5;i++)
		{	
			for(int j=1;j<=8;j++)
			{
				cin>>schedule[i][j];
			}
		}
		cin>>day>>m;
		for(int i=1;i<=5;i++)
		{	
			for(int j=1;j<=8;j++)
			{
				if(schedule[i][j]=="math")
				{
					math_cnt[i]++;
					weak_math++;
				}
			}
		}
		cout<<(day/7)*weak_math;	
	}
	return 0;
}
