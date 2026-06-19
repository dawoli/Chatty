#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int c[128];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)c[s[i]]++;
	for(char i='9';i>='0';i--)
	{
		while(c[i]--)cout<<i;
	}
	cout<<endl;
	return 0;
}
