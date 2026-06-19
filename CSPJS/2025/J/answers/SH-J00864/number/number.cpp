#include<bits/stdc++.h>
using namespace std;
string s1;
char s2[1000005];
int sn;
//Ä£Äâ 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	for(int i=0;i<s1.length();i++)
	{
		if(isdigit(s1[i]))
		{
			s2[++sn]=s1[i];
		}
	}
	stable_sort(s2+1,s2+sn+1,greater<>());
	for(int i=1;i<=sn;i++)
	{
		cout<<s2[i];
	}
	return 0;
}
