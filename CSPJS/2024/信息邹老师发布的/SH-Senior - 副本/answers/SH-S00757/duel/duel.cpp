#include<iostream>

using namespace std;

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	int n;
	cin>>n;
	int r[n];
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
	}
	
	int chance[n];
	int quit[n]; 
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(r[i]>r[j]&&r[i]!=r[j]&&chance[i]!=1&&quit[j]!=1)
			{
				quit[j] = 1;
				chance[i] = 1;
			}
		}
	}
	
	int cnt = 0;
	
	for(int i=0;i<n;i++)
	{
		if(quit[i]!=1)
		{
			cnt++;
		}
	}
	
	cout<<cnt;
	
	return 0;
}
