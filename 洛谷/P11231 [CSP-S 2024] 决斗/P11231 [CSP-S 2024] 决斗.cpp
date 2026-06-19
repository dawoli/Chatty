#include<bits/stdc++.h>
using namespace std;
int n,l=1;
vector<int> r;
int main()
{
	cin>>n;
	r.resize(n+1);
	for(int i=1;i<=n;i++)cin>>r[i];
	sort(r.begin()+1,r.end());
	for(int i=1;i<=n;i++)
	{
		if(r[i]>r[l])l++;
	}
	cout<<n-l+1;
	return 0;
}
