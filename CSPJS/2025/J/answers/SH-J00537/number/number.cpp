#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	string s;
	getline (cin,s);
	string a={};
	
	for (int i = 0;i < s.size();i ++)
	{
		if (isdigit (s[i]))
		{
			a = a + s[i];		
		}
	}
	for (int i = 0;i < a.size();i ++)
	{
		for (int j = i + 1;j < a.size();j ++)
		{
			if (a[i] < a[j])
			{
				swap (a[i],a[j]);	
			}	
		}	
	}
	cout << a << endl;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
