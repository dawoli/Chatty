/**************
 * T1 club
 * ¹À·Ö: 4
 **************/
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int t,n;
int m[100005][4];
int main()
{
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) 
	{
		cin >> n;
		if(n==2)
		{
			int a1,b1,c1,a2,b2,c2;
			cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
			cout << max(a1+b2,max(a1+c2,max(b1+a2,max(b1+c2,max(c1+a2,c1+b2))))) << endl;
			continue;
		}
		else
		{
			for(int i=1; i<=n; i++)
			{
				;
			}
		}
	}
	return 0;
}
