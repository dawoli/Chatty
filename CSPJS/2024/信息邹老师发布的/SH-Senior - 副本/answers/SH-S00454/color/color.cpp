#include<bits/stdc++.h>
using namespace std;
int n;
int list_a[2*10000+1];
bool colour[2*10000+1];
int color(int num)
{
	int i,j;
	int ans1=0,ans2=0;
	
	colour[num]=false;
	for(i=num-1;i>=1;i--)
	{
		if((list_a[i]==list_a[num])&&(colour[i]==colour[num]))
		{
			ans1+=list_a[i];
			break;
		}
	}
	
	if(num!=n)
	{
		ans1+=color(num+1);
	}
	
	
	colour[num]=true;
	for(i=num-1;i>=1;i--)
	{
		if((list_a[i]==list_a[num])&&(colour[i]==colour[num]))
		{
			ans2+=list_a[i];
			break;
		}
	}
	if(num!=n)
	{
		ans2+=color(num+1);
	}
	if(ans1<ans2)
	{
		return ans2;
	}
	return ans1;
}


int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	int round;
	for(round=1;round<=t;round++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>list_a[i];
		}
		colour[1]=false;
		cout<<color(1)<<endl;
	}
	return 0;
}
