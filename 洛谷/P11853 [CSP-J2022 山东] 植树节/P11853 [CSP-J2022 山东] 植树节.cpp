#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
	int n,x,y;
	vector<int> diff,a;
	bool cmp(int a,int b)
	{
		return a>b;
	}
	void add(int l,int r)
	{
		diff[l]++;
		diff[r]--;
	}
	void sum()
	{
		a.push_back(0);
		for(int i=1;i<=n;i++)
		{
			a.push_back(diff[i]-diff[i-1]);
		}
	}
	void Soar()
	{
		diff.resize(100005);
		a.resize(100005);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y;
			add(x,y);
		}
		sum();
		sort(a.begin(),a.end(),cmp);
		cout<<*a.begin();
		return;
	}
}
int main()
{
	Soaring_Wings::Soar();
	return 0;
}