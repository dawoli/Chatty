#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> ans;
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			ans.push_back(a[i]-'0');
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=ans.size()-1;i>=0;i--)
	{
		cout<<ans[i];
	}
	if(ans.size()==0)
	{
		cout<<0;
	}
	return 0;
}
