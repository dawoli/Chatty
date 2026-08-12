#include<bits/stdc++.h>
using namespace std;
string s;
int add=0;
bool used=false;
int val(int pos)
{
	return ((int)s[pos]-'0'+add)%10;
}
int main()
{
	//freopen("r","a.in",stdin);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	cin>>s;
	while(val(0)!=9)add++;
	for(int i=0;i<s.size();i++)
	{
		if(val(i)!=9&&!used)
		{
			s[i]++;
			used=true;
		}
		cout<<val(i);
	}
	return 0;
}