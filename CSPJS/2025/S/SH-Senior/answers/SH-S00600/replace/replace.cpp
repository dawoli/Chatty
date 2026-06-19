#include<bits/stdc++.h>
using namespace std;
string a1[200005],a2[200005];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> a1[i] >> a2[i];
	}
	for(int i = 1;i <= q;i++)
	{
		string x,y;
		int cnt = 0;
		cin >> x >> y;
		for(int j = 1;j <= n;j++)
		{
			//cout << "µÚ" << j << " " << x.find(a1[j]) << "\n";
			if(x.find(a1[j]) < x.size())
			{
				//cout << a1[j] << " ";
				int m = x.find(a1[j]),sz = a1[j].size();
				string t = x;
				for(int k = m;k < m + sz;k++)
				{
					t[k] = a2[j][k - m];
				}
				//cout << "µÚ" << j << " " << t << "\n";
				if(t == y)
				{
					cnt++;
					//cout << a1[j] << "\n";
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
} 
