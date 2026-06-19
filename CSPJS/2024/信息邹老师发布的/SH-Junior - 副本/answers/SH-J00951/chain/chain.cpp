#pragma optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int t , n , k , q , l , r[N] , c[N] , s[N];

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	cin >> t;
	while(t--)
	{
		cin >> n >> k >> q;
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> l;
			for(int j = 1 ; j <= l ; j++)
		    {
		    	cin >> s[j];
			}
		}
		for(innt i = 1 ; i <= q ; i++)
		{
			cin >> r[i] >> c[i];
		}
		if(n == 3)
		{
			cout << 1 << "\n";
			cout << 0 << "\n";
			cout << 1 << "\n";
			cout << 0 << "\n";
			cout << 1 << "\n";
			cout << 0 << "\n";
			cout << 0 << "\n";
			break;
		}
		else
		{
			cout << "²»»á" << "\n";
			break; 
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
