#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt = 0,s;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i ++)
	{
		cin>>a[i];	
	}
	s = a[1];
	for(int i = 2;i <= n;i ++)
	{
		if(s == k)
		{
			cnt ++;
			s = a[i];
			continue;
		}
		s = s ^ a[i];
	}
	if(s == k)
	{
		cnt ++;
	}
	cout<<cnt;
	return 0;
} 
