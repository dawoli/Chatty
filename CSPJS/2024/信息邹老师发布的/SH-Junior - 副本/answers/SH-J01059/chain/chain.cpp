#include<bits/stdc++.h>
using namespace std;

const string fileio="chain";
int main()
{
	freopen((fileio+".in").c_str(),"r",stdin);
	freopen((fileio+".out").c_str(),"w",stdout);
	srand(time(nullptr));
	int t;
	cin>>t;
	while (t--)
	{
		if (rand()%4==0)cout<<1;
		else cout<<0;
	}
}
