#include <bits/stdc++.h>
using namespace std;
int n,k,s;
long long a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(k==1&&a[i]==1)
		{
			s++;
		}
		else if(k==0&&a[i]==0||k==0&&a[i]==1&&a[i-1]==1)
		{
			s++;
		}
	}
	cout<<s;
	
	return 0;
}
