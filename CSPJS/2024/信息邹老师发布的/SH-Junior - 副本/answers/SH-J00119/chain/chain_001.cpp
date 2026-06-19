#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=1;i<=k;i++)
		{
			cout<<(i%n+m*k)%2<<endl; 
		}
	}
	return 0;
}
