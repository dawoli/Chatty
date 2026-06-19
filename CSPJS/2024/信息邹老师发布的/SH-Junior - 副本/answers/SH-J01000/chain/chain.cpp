#include<bits/stdc++.h>
using namespace std;
int jishu[1000002];
int jishuu[1000002];
int jishuuu[1000002];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,k,q;
	cin>>t>>n>>k>>q;
	for(int i=1;i<=14;i++)
	{
		cin>>jishu[i];
	 } 
	 for(int i=1;i<=7;i++)
	{
		cin>>jishuu[i];
		cin>>jishuuu[i];
	 } 
	 for(int i=1;i<=7;i++)
	{
		if(jishuu[i]==jishuuu[i]/2||jishuu[i]==6)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	 } 

	
	return 0;
 } 
