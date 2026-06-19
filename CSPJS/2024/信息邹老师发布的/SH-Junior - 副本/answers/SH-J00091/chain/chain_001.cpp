#include <iostream>
#include <cstdio>
using namespace std;
int t,n,k,q;
int s[10005][20005];
int len[20005];
int r,c;
bool chain(int p,int num,int round)
{
	if(round==r&&num==c)return true;
	if(round>=r)return false;
	for(int i=1;i<=len[i]+1;i++)
	{
		if(s[p][i]==num)
		{
			for(int j=2;j<=k&&i+j-1<=len[i]+1;j++)
			{
				chain((p+1)%n,s[p][i+j-1],round+1);
			}
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		for(int i=0;i<=n-1;i++)
		{
			cin>>len[i];
			for(int j=1;j<=len[i]+1;j++)
			{
				cin>>s[i][j];
			}
		}
		bool flag=true;
		for(int i=1;i<=q;i++)
		{
			cin>>r>>c;
			int tflag=0;
			for(int i=0;i<=n-1;i++)
			{
				tflag=tflag||chain(i,1,0);
			}
			if(tflag)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
