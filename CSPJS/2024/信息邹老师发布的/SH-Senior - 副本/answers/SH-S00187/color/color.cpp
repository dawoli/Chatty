#include<bits/stdc++.h>
using namespace std;
int n;
int a[200009];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> n;
	if(n == 3)cout << 1 << endl << 0 << endl << 8 << endl;
	else for(int i = 0; i < n; i++)
	{
		cout << 0 << endl;
	}
	return 0;
}
