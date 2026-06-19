#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l[100005];
string s[100005];
int r,c,flag;
void find(int p,int f,int o)
{
	if(p==0&&f==1)
	{
		flag=1;
		return;
	}
	if(p==0&&f!=1)
	{
		return;
	}
	for(int a=1;a<=n;a++)
	{
		if(a==o)
		{
			continue;
		}
		for(int b=1;b<=l[a];b++)
		{
			if(s[a][b]-'0'==f)
			{
				for(int d=b-1;d>=b-k+1&&d>0;d--)
				{
					find(p-1,s[a][d]-'0',a);
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++)
		{
			cin>>l[j];
			for(int z=1;z<=l[j];z++)
			{
				cin>>s[j][z];
			}
		}
		for(int j=1;j<=q;j++)
		{
			flag=0;
			cin>>r>>c;
			find(r,c,0);
			cout<<flag;
		}
	}
	return 0;
}
