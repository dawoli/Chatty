#include<iostream>
using namespace std;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=n;i>=0;i--)
	{
		if(n-i<=i)cnt++;
		if(n-1>i)break;	
	}	
	cout<<cnt;
	return 0;
} 
