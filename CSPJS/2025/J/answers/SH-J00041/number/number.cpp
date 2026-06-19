#include<bits/stdc++.h>
using namespace std;

vector<int> vtr;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=s.size();i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			vtr.push_back(s[i]-'0');
		}
	}
	sort(vtr.begin(),vtr.end());
	for(int i=vtr.size()-1;i>=0;i--)
	{
		cout<<vtr[i];
	}	
	fclose(stdin);
	fclose(stdout);		
	return 0;
}
