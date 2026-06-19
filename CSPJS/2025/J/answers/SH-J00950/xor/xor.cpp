#include <bits/stdc++.h>
using namespace std;
int a[500010],s[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int i=1,j=1,c=0;
	while (j<=n)
	{
		if (i>j||(s[j]^s[i-1])<k)
		{
			j++;
			//cout<<1<<" ";
		}
		else if ((s[j]^s[i-1])>k)
		{
			i++;
			//cout<<2<<" ";
		}
		else if ((s[j]^s[i-1])==k)
		{
			c++;
			i=j+1;
			j=j+1;
			//cout<<3<<" ";
		}
		//cout<<c<<" "<<i<<" "<<j<<endl;
	}
	cout<<c;
	return 0;
}
