#include <bits/stdc++.h>
using namespace std;
int n,r[100005],w[100005],num=1,w2[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> r[i];
	sort(r+1,r+n+1);
	w[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(r[i]!=r[i-1])
		{
			w[++num]=i;
		}
	}
	for(int i=2;i<=num;i++)
	{
		w2[i-1]=w[i]-w[i-1];
	}
	w2[num]=n-w[num]+1;
	for(int i=2;i<=num;i++)
	{
		w2[i]=max(w2[i],w2[i-1]);
	}
	cout << w2[num];
} 
