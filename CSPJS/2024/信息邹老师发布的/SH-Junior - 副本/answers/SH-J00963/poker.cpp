#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ow[5][200]={},sum=52,co,cn;
	char in1,win;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>win>>in1;
		if (win=='D')	co=1;
		else if(win=='C')	co=2;
		else if(win=='H')	co=3;
		else	co=4;	
		if (ow[co][in1]==0)
		{
			ow[co][in1]=1;
			sum--;
		}
	}
	cout<<sum<<endl;
	return 0;
} 
