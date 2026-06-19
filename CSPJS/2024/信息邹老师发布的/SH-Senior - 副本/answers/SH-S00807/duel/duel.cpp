#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N],dead=1;
int main()
{
	ios::sync_with_stdio(false);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i)
	{
		if(dead<i&&a[dead]<a[i]) ++dead;
	}
	cout << n - dead + 1 << "\n";
	return 0;
}
