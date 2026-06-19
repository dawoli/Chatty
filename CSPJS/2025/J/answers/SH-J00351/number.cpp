#include<bits/stdc++.h>
using namespace std;
stack<int>a;
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a.push(s[i]);
		}
	}
	while(!a.empty())
	{
		cout<<a.top();
		a.pop();
	}
	return 0;
}
