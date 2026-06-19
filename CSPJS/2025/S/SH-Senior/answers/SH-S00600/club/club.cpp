#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	srand(time(0));
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cout << rand() % 100 + 1;
	}
	return 0;
} 
