#include<bits/stdc++.h>
using namespace std;
struct cmp {
  bool operator()(int a, int b) const { return a > b; }
};
int n;
int a;
set<int,cmp> s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a; 
		s.insert(a);
	}
	auto first=s.begin(),second=++s.begin(),third=++(++s.begin());
	cout<<max(*first%*second,*third);
	return 0;
}