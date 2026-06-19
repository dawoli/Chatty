#include <bits/stdc++.h>
using namespace std;
int buc[100001];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int ans=0;
	int n;cin >> n;
	for(int i=1;i<=n;i++)
	{
		int c;cin >> c;buc[c]++;
	}
	for(int i=1;i<=100001;i++)
	{
		if(buc[i]>=2)ans += buc[i]-1;
	}
	cout << ans;
}
