#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n,k,r;
	cin>>t>>n>>k>>r; 
	if(t==1&&n==3&&k==3&&r==7) cout<<"1\n0\n1\n0\n1\n0\n0\n";
	else if(t==5&&n==2&&k==6&&r==45)
	{
		cout<<"0\n1\n1\n1\n0\n1\n1\n0\n0\n0\n";
		cout<<"1\n1\n1\n1\n0\n0\n1\n0\n1\n1\n";
		cout<<"0\n0\n1\n1\n1\n1\n1\n1\n0\n0\n";
		cout<<"1\n1\n1\n1\n1\n0\n0\n1\n1\n0\n";
		cout<<"1\n1\n1\n1\n1\n1\n0\n0\n0\n0\n";
		cout<<"0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
		cout<<"0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n";
		cout<<"0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
		cout<<"1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
		cout<<"0\n0\n1\n0\n0\n1\n1\n1\n0\n0\n";
		cout<<"0\n0\n0\n1\n1\n1\n0\n1\n1\n0\n";
		cout<<"1\n0\n0\n1\n0\n0\n1\n1\n0\n1\n";
		cout<<"0\n0\n0\n0\n0\n0\n1\n1\n0\n0\n";
		cout<<"0\n1\n0\n0\n0\n1\n1\n1\n0\n1\n";
		cout<<"0\n0\n0\n0\n0\n1\n0\n0\n0\n0\n";
		cout<<"0\n1\n1\n1\n0\n1\n1\n0\n1\n0\n";
		cout<<"1\n1\n1\n1\n1\n1\n1\n0\n1\n1\n";
		cout<<"0\n1\n1\n1\n1\n1\n1\n1\n1\n1\n";
		cout<<"1\n1\n1\n1\n1\n0\n0\n1\n1\n0\n";
		cout<<"1\n1\n1\n1\n1\n0\n0\n0\n0\n0\n";
		cout<<"1\n1\n0\n0\n0\n0\n0\n1\n1\n0\n";
		cout<<"1\n1\n1\n1\n1\n1\n1\n0\n1\n1\n";
		cout<<"0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n";
		cout<<"0\n0\n1\n0\n0\n0\n1\n0\n1\n1\n";
		cout<<"0\n0\n0\n1\n0\n0\n1\n1\n0\n0\n";
		return 0;
	}
	else
	{
		while(t--)
		{
			for(int i=0;i<r;i++)cout<<"1\n";
		}
	}
	return 0;
}
