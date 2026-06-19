#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int n;
		cin>>n;
		int x=n/7;
		for(int j=0;j<x;j++)
		{
			cout<<8;
		}
		cout<<endl;
	}
	return 0;
}

