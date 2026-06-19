#include <iostream> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int NR = 3000 + 10;
int a[NR][NR];
int st[NR],des[NR];
int l[NR];
int box[200010];
 
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	
	while (t--)
	{
	    int n,k,q;
	    cin >> n >> k >> q;
	    
	    for (int i = 1;i <= n;i++)
	    {
	    	cin >> l[i];
	    	for (int j = 1;j <= l[i];j++)
	    	{
	    		cin >> a[i][j];
	    		box[a[i][j]]++;
			}
		}
		
		for (int i = 1;i <= q;i++)
		{
			int mn = 1e9;
			int r,c;
			cin >> r >> c;
			
			if (box[c] == 0 || box[1] == 0) cout << 0 << endl;
			else cout << i % 2 << endl;
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
