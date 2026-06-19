#include<bits/stdc++.h>
using namespace std;
string a;
int sum[15],asize;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	asize=a.size();
	for(int i=0;i<asize;i++) 
	{
		int now=int(a[i]-'0');
		if(now>=0&&now<10) sum[now]++;
	}
	for(int i=9;i>=0;i--) 
	{
		int s=sum[i];
		for(int j=1;j<=s;j++)
		{
			cout<<i;
		}
	}
	return 0;
} 
