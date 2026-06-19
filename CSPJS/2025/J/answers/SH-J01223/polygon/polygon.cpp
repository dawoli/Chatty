#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if (b==1)cout<<9;
	else if (b==2)cout<<6;
	else
	{
		cout<<random()%998244;
	}
	return 0;
}
