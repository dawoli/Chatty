#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int T;
int n,k,q;
int s[1005][2005];
int l[200005];
bool flag[200005];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>q;
		memset(flag,false,sizeof(flag));
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
			{
				cin>>s[i][j];
			}
			for(int j=1;j<=l[i];j++)
			{
				if(s[i][j]==1)
				{
					int x=j,cnt=0;
					while(x+1<=l[i]&&cnt<k-1)
					{
						x++;
						cnt++;
						flag[s[i][x]]=true;
					}
				}
			}
		}
		for(int p=1;p<=q;p++)
		{
			int r,c;
			cin>>r>>c;
			if(r==1)
			{
				if(flag[c]) cout<<1<<endl;
				else cout<<0<<endl;
			}
		}
	}
	return 0;
}
