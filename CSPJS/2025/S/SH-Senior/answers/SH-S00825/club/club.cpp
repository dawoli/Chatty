#include <bits/stdc++.h> 
using namespace std;
int t,n,x,y,z;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 0;i <= t;i++)
	{
		cin >> n;
		for(int i = 0;i <= n;i++)
		{
			cin >> x >> y >> z;
			cout <<x+y+z << endl;
		}
	}
	return 0;
}
