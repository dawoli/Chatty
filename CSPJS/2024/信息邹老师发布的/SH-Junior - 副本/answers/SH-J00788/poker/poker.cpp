#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	set<string> st;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		st.insert(s);
	}
	cout<<52-st.size();
	return 0;
}

