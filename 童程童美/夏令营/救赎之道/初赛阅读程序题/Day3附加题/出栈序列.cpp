#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int stk[N], top;
int main()
{
	int n, a[N], b[N];
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	for(int i = 1, j = 1; i <= n; ++i)
	{
		stk[++top] = a[i];
		while(top != 0 && stk[top] == b[j])
		{
			--top;
			j++;
		}
	}
	if(top > 0)
		cout << "no";
	else
		cout << "yes";
	return 0;
}

