#include<bits/stdc++.h>
using namespace std;
int n,cnt1=0;
int a1[55];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i];
	}
	for(int j=1;j<=n;j++)
	{
		cnt1=52-n;
	}
	cout<<cnt1<<endl;
	return 0;
 } 
