#include<bits/stdc++.h>
#include<string.h>
using namespace std;
string s[200001][2],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	while(q--)
	{
		int cnt=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++)
		{
			if(substr(s[i][0].c_str(),t1.c_str())==string::npos)
			{
				break;
			}
			else
			{
				int t=substr(s[i][0].c_str(),t1.c_str())-t1.begin();
				for(int j=0;j<s[i][0].length();j++)
				{
					t1[j+t]=s[i][1][j];
				}
				if(t1==t2)
				{
					cnt++;	
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
