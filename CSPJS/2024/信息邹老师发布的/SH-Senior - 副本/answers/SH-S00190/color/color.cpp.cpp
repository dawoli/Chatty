#include<bits/stdc++.h>
using namespace std;
int a[1000010],n;
int main()
{
    cin>>n;
	int s=0;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(a[i]==a[j])
			  s=s+a[i];
		}
	}
	cout<<s<<endl;
	return 0;
}
