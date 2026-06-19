#include<bits/stdc++.h>
using namespace std;
int t,n,k,q;
int a[1003][2003],b[2003];
bool abc(int r,int c,int p,int d)
{
	if(r==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==p) continue;
			for(int j=1;j<=b[i];j++)
			{
				if(a[i][j]==d)
				{
					for(int z=j+1;z<=min(b[i],j+k-1);z++)
					{
						if(a[i][z]==c) return 1;
					}
				}
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==p) continue;
		for(int j=1;j<=b[i];j++)
		{
			if(a[i][j]==d)
			{
				for(int z=j+1;z<=min(b[i],j+k-1);z++)
				{
					if(abc(r-1,c,i,a[i][z])) return 1;
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
			for(int j=1;j<=b[i];j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=q;i++)
		{
			int r,c;
			cin>>r>>c;
			if(abc(r,c,0,1)) cout<<"1"<<endl;
			else cout<<"0"<<endl;
		}
	}
	return 0;
}
