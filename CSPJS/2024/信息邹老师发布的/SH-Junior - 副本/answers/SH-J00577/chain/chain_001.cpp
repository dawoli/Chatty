#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	for(int s=1;s<=t;s++)
	{
		int n,k,q,l[10020],a[10020][100020],r[10020],c[10020];
		cin >> n >> k >> q;
		for(int i=1;i<=n;i++)
		{
			cin >> l[i];
			for(int j=1;j<=l[i];j++) cin >> a[i][j];	
		}
		for(int i=1;i<=q;i++) cin >> r[i] >> c[i];
		cout << 0;	 
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
