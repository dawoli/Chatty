#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,ans,last,cnt;
int a[N],alive[N],can[N];
set<int> s;

bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(can[a[i]]) return false;
	}
	return true;
}

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	last=ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		can[a[i]]++;
		alive[a[i]]++;
		s.insert(a[i]);
	}
	sort(a+1,a+n+1);
	while(!check())
	{
		set<int>::iterator it;
		it=s.begin();
		int x=*it;it++;
		int y=*it;
		can[x]=0;
		int tmp=min(alive[x],can[y]);
		ans-=tmp;
		if(alive[x]<=can[y])
		{
			last-=alive[x];
			s.erase(x);
			can[y]-=alive[x];
			alive[x]=0;
			cnt++;
		}
		else
		{
			last-=can[y];
			alive[x]-=can[y];
			can[y]=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
