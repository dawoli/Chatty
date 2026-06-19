#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

int n,r[N],cnt;

int main()
	{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+n+1);
	cnt=0;
	for(int i=2;i<=n;i++)
	{
		if(r[i]>r[cnt+1]) cnt++;
	}
	cout<<n-cnt;
	return 0;
	}
