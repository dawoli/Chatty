#include<bits/stdc++.h>
using namespace std;
int a[500005]={0},b=0,c=0,d=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>b>>c;
	for(int i=0;i<b;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<b;i++)
	{
		if(a[i]==c)
		{
			d+=1;
		}
		else if((a[i]^a[i+1])==c)
		{
			d+=1;
			i+=1;
		}
	}
	cout<<d;
	return 0;
}
