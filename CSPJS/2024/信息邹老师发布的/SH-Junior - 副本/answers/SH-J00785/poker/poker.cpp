#include <bits/stdc++.h>
using namespace std;
map<string,bool>m;
char hua[5];
char num[14];
int sum=52;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(!m[s])
		{
			sum--;
			m[s]=1;
		}
	}
	cout<<sum;
	return 0;
}
