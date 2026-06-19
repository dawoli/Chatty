#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	for(int o=1;o<=T;o++)
	{
		int n,m,q;
		cin>>n>>m>>q;
		int num=0;
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			int t;
			for(int j=1;j<=a;j++)
			{
				cin>>t;
				num+=t;
			}
		}
		for(int i=1;i<=q;i++)
		{
			int t=num;
			int a,b;
			cin>>a>>b;
			b-=1;
			t/=a; 
			if(b==t%(b+1)) cout<<1<<endl;
			else cout<<0<<endl;	
		}
	}
}
