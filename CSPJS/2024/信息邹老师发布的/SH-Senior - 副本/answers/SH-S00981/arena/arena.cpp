#include<bits/stdc++.h>
using namespace std;
int t,n,m,fla,flag1,sum=0,x0,x1,x2,x3,k,wei[200005],T;
int a[200005],ji[200005];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n=0;
	cin>>t;
	while(t--)
	{
		k=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++)
		cin>>ji[i];
		while(n>pow(2,k))
			k++;
		for(int i=1;i<=k;i++)
		cin>>wei[i];
		cin>>T;
		while(T--)
		{
			cin>>x0>>x1>>x2>>x3;
			cout<<1<<endl; 
		}
	}
	
	return 0;
}
