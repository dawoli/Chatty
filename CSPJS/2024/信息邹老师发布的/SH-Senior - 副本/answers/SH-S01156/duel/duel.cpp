#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n,x[N],ans;
multiset<int>s;

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		s.insert(x[i]);
	}
	while(!s.empty())
	{
		int a=*s.begin();
		cout<<a<<endl;
		s.erase(s.begin());
		if(*s.rbegin()==a)
		{
			break;
		}
		//cout<<*s.lower_bound(a); 
		s.erase(s.upper_bound(a));
		ans++;
	}
	cout<<n-ans;
	return 0;
}
