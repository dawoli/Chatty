#include<bits/stdc++.h>
using namespace std;
set<string>cnt;
int main()
{
	freopen("poker.in","r",stdin); 
	freopen("poker.out","w",stdout); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string t;
		cin>>t;
		cnt.insert(t);
	}
	cout<<52-cnt.size()<<endl;
	return 0;
} 
