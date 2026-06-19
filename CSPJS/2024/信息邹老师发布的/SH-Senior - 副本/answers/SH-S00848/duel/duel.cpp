#include <bits/stdc++.h>
using namespace std;
int r[100010],bs[100010],st[100010];
int n;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int u=n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
		bs[r[i]]++;
	}
	int p=1;
	for(int i=1;i<=100009;i++)
	{
		if(bs[i]!=0)
		{
			st[p]=bs[i];p++;
		}
	}
	for(int i=1;i<=p-1;i++)
	{
		u-=min(st[i],st[i+1]);
	}
	cout<<u;
}

/*


*/

