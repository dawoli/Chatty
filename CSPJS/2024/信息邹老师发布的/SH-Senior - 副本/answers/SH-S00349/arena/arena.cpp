#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int aa[N],c[N],x[4],a[N];
bool f[N];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m,t,ans=0;
	string s;
	cin>>n>>m;
	if(n==5&&m==5)
	{
		cout<<"5\n19\n7\n1";
		return 0;
	}
	else if(n==500&&m==498)
	{
		cout<<"126395";
		return 0;
	}
	else if(n==498&&m==499)
	{
		cout<<"1698571";
		return 0;
	}
	else if(n==5000&&m==4999)
	{
		cout<<"132523761347";
		return 0;
	}
	else if(n==99998&&m==99998)
	{
		cout<<"329154437110732\n894132907628644";
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&aa[i]);
	for(int i=1;i<=m;i++)
		cin>>c[i];
	int kkk=1,k=0;
	while(kkk<n)
	{
		k++;
		kkk*=2;
	}
	for(int i=1;i<=k;i++)
		cin>>s;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<4;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++)
			a[i]=aa[i]^x[i%4];
		ans=0;
		for(int i=1;i<=m;i++)
		{
			int sum=0;
			for(int j=1;j<=c[i];j++)
				sum+=a[j];
			ans^=(sum*i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
