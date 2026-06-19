#include<iostream>
using namespace std;
int n,k,q,l[20000],s[20000][20000],r,c,tf=0;
void dfs(int round,int aim,int player){
	for(int i=1;i<=n;i++)
	{
		if(i==player) continue;
		for(int j=1;j<l[i];j++)
		{
			if(s[i][j]==aim)
			{
				for(int m=1;m<k;m++)
				{
					if(j+m>l[i]) break;
					if(round==r)
					{
						if(s[i][j+m]==c)
						{
							tf=1;
							return;
						}
					}
					else dfs(round+1,s[i][j+m],i);
					if(tf==1) return;
				}
				if(tf==1) return;
				if(round==r) return;
			}
		}
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	for(T-=1;T>=0;T--)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++) cin>>s[i][j];
		}
		for(int i=1;i<=q;i++)
		{
			cin>>r>>c;
			tf=0;
			dfs(1,1,0);
			cout<<tf<<endl;
		}
	}
	return 0;
}
