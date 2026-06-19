#include<bits/stdc++.h>

using namespace std; 

int n, q; 
string a[105], b[105]; 

int main()
{
	freopen("replace.in", "r", stdin); 
	freopen("replace.out", "w", stdout); 
	cin >> n >> q; 
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i]; 
	}
	while(q--)
	{
		string x, y; 
		cin >> x >> y; 
		int xl = x.length(); 
		int yl = y.length(); 
		int cnt = 0; 
		for(int i = 1; i <= n; i++)
		{
			int al = a[i].length(); 
			for(int j = 1; j <= xl - al + 1; j++)
			{
				bool flag = true; 
				for(int k = j; k <= xl; k++)
				{
					for(int l = 1; l <= al; l++)
					{
						if(x[k] != a[i][l])
						{
							flag = false; 
							break; 
						}
					}
					if(!flag) break; 
				}
				if(flag)
				{
					bool can = true; 
					for(int k = j, l = 1; l <= al; k++, l++)
					{
						if(y[k] != b[i][l])
						{
							can = false; 
							break; 
						}
					}
					if(can)
					{
						bool suc = true; 
						for(int k = j + al; k <= xl; k++)
						{
							if(x[k] != y[k])
							{
								suc = false; 
								break; 
							}
						}
						if(suc)
						{
							cnt++; 
						}
					}
				}
			}
		}
		cout << cnt << endl; 
	}
	return 0; 
}
