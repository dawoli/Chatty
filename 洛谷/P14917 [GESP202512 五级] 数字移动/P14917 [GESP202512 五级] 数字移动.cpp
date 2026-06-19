#include<bits/stdc++.h>
using namespace std;
int n,l,r,mx=INT_MIN,mn=INT_MAX,cnt;
list<int> a;
bool check(int x)
{
	list<int> b(a);
	int cnt=0;
	for (auto it:b)
	{
		if (it>x)cnt++;
	}
	for (auto it=b.begin();it!=b.end()&&cnt!=0;)
	{
		if (*it>x)
		{
			int y=*it;
			it=b.erase(it);
			b.push_back(y);
			cnt--;
		}
		else it++;
	}
	for (auto it=b.rbegin();it!=b.rend();it++)
	{
		if (*it<=x)break;
		if (*it!=*++it)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
		mx=max(mx,x);
		mn=min(mn,x);
	}
	l=mn;
	r=mx;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid))
		{
			cnt=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<cnt<<endl;
	return 0;
}