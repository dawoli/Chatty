#include<bits/stdc++.h>
using namespace std;
const string fileio="poker";
int main()
{
	freopen((fileio+".in").c_str(),"r",stdin);
	freopen((fileio+".out").c_str(),"w",stdout);
	set<string> st;
	int n;
	cin>>n;
	while (n--)
	{
		string s;
		cin>>s;
		st.insert(s);
	}
	cout<<52-st.size();
}
