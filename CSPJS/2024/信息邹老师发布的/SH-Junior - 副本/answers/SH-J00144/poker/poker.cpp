#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	string a[55] = {};
	for (int i=0;i<n;i++)
	{
		string k;
		cin >> k;
		bool flag = 1;
		for (int j=0;j<n;j++)
		{
			if (k ==a[j])
			{
				flag = 0;
			}
		}
		if(flag)
		{
			a[i] = k;
		}
	}
	int s=0;
	for (int i=0;i<n;i++)
	{
		if (a[i] != "")
		{
			s++;
		}
	}
	cout << 52-s << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
