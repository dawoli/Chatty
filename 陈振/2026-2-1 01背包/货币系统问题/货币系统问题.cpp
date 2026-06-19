#include<bits/stdc++.h>
using namespace std;
int v,n,ans=0;
int p,f[1001];
int main()
{
	cin>>v>>n;
	for (int i=1;i<=v;i++)
	{
		cin>>p;
		for (int j=p;j<=n;j++)
			f[j]=f[j]+f[j-p];
	}
	cout<<f[n]<<endl;
	return 0;
}