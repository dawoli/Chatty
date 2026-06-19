#include<bits/stdc++.h>
#include<string>
using namespace std;
int n,q,sum;
bool flag;
string s1[200010],s2[200010],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		string t=t2;
		sum=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<t.length();k++)
			{
				if(t2[k]!=t1[k]&&!flag)
				{
					if(s2[j][0]==t2[k])
					{
						int r=0;
						while(s2[j][r]==t2[k])
						{
							t2[k]=s1[j][r];
							r++;
							k++;
						}
						if(r<s2[j].length())continue;
						flag=true;
					}
					else continue;
				}
			}
			if(t1==t2)sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
