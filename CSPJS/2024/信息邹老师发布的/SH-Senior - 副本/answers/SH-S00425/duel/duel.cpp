#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,r[N],vis[N]; 
bool two()
{
	for(int i=1;i<=n;i++)
		if(r[i]>=3)
			return false;
	return true;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>r[i];
	set<int> s;
	for(i=1;i<=n;i++)
		s.insert(r[i]);
	if(s.size()==n)
	{
		cout<<1;
	}
	else if(two())
	{
		int cnt1=0,cnt2=0;
		for(i=1;i<=n;i++)
		{
			if(r[i]==1)
				cnt1++;
			else
				cnt2++;
		}
		cout<<max(cnt1,cnt2);
	}
	else
	{
		int ans=n;
		sort(r+1,r+1+n);
		int j=0,k;
		for(i=1;i<=n;i++)
		{
			j=upper_bound(r+1,r+1+n,r[i])-r;
			k=j;
			while(vis[k]&&k<=n)
				k++;
			if(k<=n)
			{
				ans--;
				vis[k]=1;
			}
			else
				break;
		}
		cout<<ans;
	}
	return 0;
}

