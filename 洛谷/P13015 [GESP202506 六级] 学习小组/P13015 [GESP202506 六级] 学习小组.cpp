#include<iostream>
using namespace std;
int n,f[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>f[i];
	for(int i=2;i<=n;i++)
		for(int k=1;k<i;k++)
			f[i]=max(f[i],f[k]+f[i-k]);
	cout<<f[n]<<endl;
	return 0;
}