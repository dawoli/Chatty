/*

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,a[N],l=1,r,b[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		if (l<=r)
		{
			if (b[l]<a[i]) l++;
		}
		b[++r]=a[i];
	}
	cout << (r-l+1) << endl;
	return 0;
 } 
