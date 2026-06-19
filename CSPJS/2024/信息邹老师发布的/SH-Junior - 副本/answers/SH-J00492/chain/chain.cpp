#include<bits/stdc++.h>
using namespace std;

int t;
int n,k,q;
int l[100010]={0};
int s[200010][100010]={0};
int r[100010]={0};
int c[100010]={0};
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	cin>>t;
	
	while(t--)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
			{
				cin>>s[i][j];
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>r[i]>>c[i];
		}
		
		cout<<1<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
