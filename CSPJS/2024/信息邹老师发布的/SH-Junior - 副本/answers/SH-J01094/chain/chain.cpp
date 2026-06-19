#include<bits/stdc++.h>

using namespace std;

int t,n,k,q,l[200500];

int a[1050][2050];

int r,c;

int vst[200500];

bool work()
{
	for(int i = 1;i <= n;i++)
	{
		bool flag = true;
		int u = 0;
		for(int j = 1;j <= l[i];j++)
		{
			if(a[i][j] == 1)
			{
				u = j;
				flag = true;
			}
			if(a[i][j] == c)
			{
				if(flag == false)
				{
					continue;
				}
				if(j-u+1 > k || j-u+1 <= 1)
				{
					continue;
				}
				return true;
			}
		}
	}
	return false;
}

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		memset(vst,0,sizeof(vst));
		memset(a,0,sizeof(a));
		for(int i = 1;i <= n;i++)
		{
			cin>>l[i];
			for(int j = 1;j <= l[i];j++)
			{
				cin>>a[i][j];
				vst[a[i][j]] = 1;
			}
		}
		for(int i = 1;i <= q;i++)
		{
			cin>>r>>c;
			if(vst[c] == 0)
			{
				cout<<"0"<<"\n";
				continue;
			}
			if(r == 1)
			{
				if(work() == false)
				{
					cout<<"0"<<"\n";
					continue;
				}
			}
			cout<<"1"<<"\n";
		}
	}
	return 0;
} 
