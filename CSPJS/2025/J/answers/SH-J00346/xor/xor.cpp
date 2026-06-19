#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500007];
int main()
{
	n = 1;
	m = 2;
	cout << n^m;
	return 0;
}#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500007];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	if(k <= 1)
	{
		cout << n/2;
	}
	else
	{
		for(int i = 0;i < n;i++)
		{
			int x = 0,y = 0;
			for(int j = i+1;j < n;j++)
			{
				cout << -1;
			}
		}
	}
	return 0;
}
