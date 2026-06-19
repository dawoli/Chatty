#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int i,n=0;
	string s;
	string a;
	cin>>s;
	for(i=0;i<15;i++)
	{
		if(s[i]!='f'&&s[i]!='a'&&s[i]!='b'&&s[i]!='c'&&s[i]!='d'&&s[i]!='e'&&s[i]!='g'&&s[i]!='h'&&s[i]!='i'&&s[i]!='j'&&s[i]!='k'&&s[i]!='l'&&s[i]!='m'&&s[i]!='n'&&s[i]!='o'&&s[i]!='p'&&s[i]!='q'&&s[i]!='r'&&s[i]!='s'&&s[i]!='t'&&s[i]!='u'&&s[i]!='v'&&s[i]!='w'&&s[i]!='x'&&s[i]!='y'&&s[i]!='z')
		{
			for(int c=0;c<15;c++)
			{
				if(s[c]<s[c+1])
				{
					n=s[c];
					s[c]=s[c+1];
					s[c+1]=n;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
