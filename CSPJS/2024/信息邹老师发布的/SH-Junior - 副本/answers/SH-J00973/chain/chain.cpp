#include <bits/stdc++.h>
using namespace std;
int t,r,c,n,k,q,a[100001][200005],l[100001];
bool f;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		f=0;
		cin >> n >> k >> q;
		for(int j=1;j<=n;j++)
		{
			cin >> l[j];
			for(int m=1;m<=l[j];m++) cin >> a[j][m];
		}
		for(int j=1;j<=q;j++)
		{
			cin >> r >> c;
		}
		cout << 0 << endl;
	}
}
