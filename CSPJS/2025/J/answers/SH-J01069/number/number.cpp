#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
string s;
vector<int> num; 
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num.push_back(s[i]-'0');
		}
	}
	sort(num.begin(),num.end());
	reverse(num.begin(),num.end());
	if(num[0]==0)
	{
		cout<<0;
		return 0;
	} 
	for(auto x:num)
	{
		cout<<x;
	}
	return 0;
}

