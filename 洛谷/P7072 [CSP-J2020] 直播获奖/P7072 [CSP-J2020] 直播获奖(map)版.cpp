#include<bits/stdc++.h>
using namespace std;
struct cmp {
	bool operator()(int a, int b) const { return a > b; }
};
double n,w;
map<int,int,cmp> a;
int main()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		int x,ed,cnt=0;
		cin>>x;
		a[x]++;
		ed=max(1.00,floor(i*w/100));
		for(auto it=a.begin();it!=a.end();it++)
		{
			cnt+=it->second;
			if(cnt>=ed)
			{
				cout<<it->first<<' ';
				break;
			}
		}
	}
	return 0;
}
