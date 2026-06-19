#include <bits/stdc++.h>

using namespace std;
struct node
{
	string s;	
};
node a[10000];

int main() 
{
	freopen("poker.in","r",stdin); 
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		
		cin>>a[i].s;
	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>0;j--)
		{
			if(a[i].s==a[j].s)
			{
				cnt++;
			}
		}
		
	}
	int t=52-n+cnt;
	cout<<t;
	return 0;
}
/*
GL@17SXYZ
*/
