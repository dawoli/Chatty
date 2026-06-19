#include<bits/stdc++.h>
using namespace std;
int a,b;
int n,m;
int t1[5001],t2[5001];
int tt;
int p[5001],q[5001];
int f[5001];
int main()
{
	cin>>a>>b;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t1[i];
		t2[i]=t1[i]*(b/a);
	}
	for(int i=1;i<=m;i++)
		{
		cin>>p[i]>>q[i];
	}
	cin>>tt;
	for(int i=1;i<=m;i++)
	{
		for(int j=tt;j>=t2[p[i]];j--){
			f[j]=max(f[j],f[j-t2[p[i]]]+q[i]);
		}
	}
	cout<<f[tt];
	return 0;
}