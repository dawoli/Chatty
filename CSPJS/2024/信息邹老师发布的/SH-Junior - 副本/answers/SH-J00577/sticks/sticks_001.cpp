#include <bits/stdc++.h>
using namespace std;
int t;
int s[10]={0,0,1,7,4,2,0,8};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin >> n;
		if(n<=7)
		{
			if(n==6) cout << 6;
			else if (s[n]!=0) cout << s[n];
			else cout << -1;
		}
		else if(n<14)
		{
			if(n%7==0)
			{
				for(int i=1;i<=n/7;i++) cout << 8;
			}
			else if(s[n%7]!=0||n%7==6)
			{
				cout << s[n%7];
				for(int i=1;i<=n/7;i++) cout << 8;
			}
			else cout << -1;
		}
		else if(n%7==0)
		{
			for(int j=1;j<=n/7;j++) cout << 8;
		}
		else if(n%7<=2)
		{
			cout << 1 << 10-n%7;
			for(int j=1;j<n/7;j++) cout << 8;
		}
		else if(n%7<=5)
		{
			cout << 2 << s[n%7+7-5];
			for(int j=1;j<n/7;j++) cout << 8;
		}
		else
		{
			cout << 6;
			for(int j=1;j<=n/7;j++) cout << 8;
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
