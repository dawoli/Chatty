#include<bits/stdc++.h>
using namespace std;
struct Game
{
	int t,r;
};
bool operator<(const Game& a, const Game& b)
{
	if (a.r==b.r) return a.t<b.t;
	return a.r>b.r;
}
int n,ans=0;
bitset<501> f;
Game g[501];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>g[i].t;
	for (int i=1;i<=n;i++)
		cin>>g[i].r;
	sort(g+1,g+n+1);
	for (int i=1;i<=n;i++)
	{
		for (int j=g[i].t;j>=1;j--)
		{
			if (!f[j])
			{
				f[j]=1;
				cnt+=g[i].r;
				break;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}